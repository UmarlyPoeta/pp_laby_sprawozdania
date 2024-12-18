#include <stdlib.h>
#include <stdio.h>

#define MAX_DL_L 100 // maksymalna liczba znaków w jednej linii tekstu
#define MAX_N_L    3 // maksymalna liczba linii tekstu

// typ danych do p. 5 laboratorium
typedef struct linia_tekstu {
  char* znaki;
  int dlugosc_linii;
} linia_tekstu;

// funkcje wczytywania linii ze standardowego wejścia i drukowania linii
// opis z kontraktem na końcu pliku
int wczytaj_linie(char* linia, int max_dlugosc_linii);
void wydrukuj_linie(char* linia, int dlugosc_linii);

int main( void )
{
  // podstawowa struktura danych do przechowywania tekstu
  char tekst_wieloliniowy_tab_2D[MAX_N_L][MAX_DL_L]; 

  int zakres = MAX_DL_L - 1; // w napisie jako tablicy znaków miejsce na \0
  int dlugosc_linii[MAX_N_L]; // tablica do przechowywania długości linii tekstu

  // wczytanie i drukowanie MAX_N_L pojedynczych linii
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    char* linia = tekst_wieloliniowy_tab_2D[nr_linii];
    dlugosc_linii[nr_linii] = wczytaj_linie(linia, zakres);
    wydrukuj_linie(linia, dlugosc_linii[nr_linii]);
  }

  printf("Rozmiar struktury danych (tablica 2D):\t\t %lu B\n",
   sizeof(tekst_wieloliniowy_tab_2D) );

  // 4. nowa struktura danych
  // a) definicja
  char* tekst_wieloliniowy_tab_wsk[MAX_N_L] = {NULL};

  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie
  // d) wydrukowanie linii
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    tekst_wieloliniowy_tab_wsk[nr_linii] = (char*)malloc(MAX_DL_L * sizeof(char));
    if (tekst_wieloliniowy_tab_wsk[nr_linii] == NULL) {
      fprintf(stderr, "Błąd alokacji pamięci!\n");
      exit(EXIT_FAILURE);
    }
    dlugosc_linii[nr_linii] = wczytaj_linie(tekst_wieloliniowy_tab_wsk[nr_linii], zakres);
    wydrukuj_linie(tekst_wieloliniowy_tab_wsk[nr_linii], dlugosc_linii[nr_linii]);
  }

  int rozmiar_str_danych = sizeof(tekst_wieloliniowy_tab_wsk);
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    rozmiar_str_danych += MAX_DL_L*sizeof(char);
    // dla wersji dynamicznej alokacji linii w nowej funkcji wczytaj_linie_dyn:
    // rozmiar_str_danych += dlugosc_linii[nr_linii]*sizeof(char);
  }
  printf("Rozmiar struktury danych (tablica wskaźników):\t %d B\n", rozmiar_str_danych);

  // Zwolnienie pamięci dla tablicy wskaźników
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    free(tekst_wieloliniowy_tab_wsk[nr_linii]);
  }

  // 6. nowa struktura danych (typ struktury (p.5) - definicja na początku pliku)
  // a) definicja tablicy struktur 
  //    (mozna użyć notacji z typedef lub bez)
  struct linia_tekstu tekst_wieloliniowy_tab_str[MAX_N_L];
  //linia_tekstu tekst_wieloliniowy_tab_str[MAX_N_L];
 
  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie
  // d) wydrukowanie linii
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    tekst_wieloliniowy_tab_str[nr_linii].znaki = (char*)malloc(MAX_DL_L * sizeof(char));
    if (tekst_wieloliniowy_tab_str[nr_linii].znaki == NULL) {
      fprintf(stderr, "Błąd alokacji pamięci!\n");
      exit(EXIT_FAILURE);
    }
    tekst_wieloliniowy_tab_str[nr_linii].dlugosc_linii = wczytaj_linie(tekst_wieloliniowy_tab_str[nr_linii].znaki, zakres);
    wydrukuj_linie(tekst_wieloliniowy_tab_str[nr_linii].znaki, tekst_wieloliniowy_tab_str[nr_linii].dlugosc_linii);
  }

  rozmiar_str_danych = sizeof(tekst_wieloliniowy_tab_str);
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    rozmiar_str_danych += MAX_DL_L*sizeof(char);
    //rozmiar_str_danych += .....dlugosc_linii*sizeof(char);
  }
  printf("Rozmiar struktury danych (tablica struktur):\t %d B\n", rozmiar_str_danych);

  // Zwolnienie pamięci dla tablicy struktur
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    free(tekst_wieloliniowy_tab_str[nr_linii].znaki);
  }

}

//------------------------------------------------------------------------------

// funkcja wczytywania pojedynczej linii ze standardowego wejścia
int wczytaj_linie(char* linia, int max_dlugosc_linii)
{
  int zakres = max_dlugosc_linii;
  
  printf("\nWpisz zestaw maksymalnie %d znaków zakończony znakiem końca linii \\n\n",
   zakres);
  
  int znak;
  int i;
  for (i=0; i<zakres && (znak=getchar()) != EOF && znak != '\n'; ++i){
    linia[i] = znak;
  }
  if (znak == '\n') {
    linia[i] = znak;
    ++i;
  }
  linia[i] = '\0'; // od 0 do i - czyli i+1 elementów tablicy
  
  return(i); // liczymy tylko znaki, bez \0 !!!
}

// funkcja drukowania pojedynczej linii jako tablicy znaków i jako napisu
void wydrukuj_linie(char* linia, int dlugosc_linii)
{
  printf("\nLinia o długości %d wypisana jako tablica znaków:\n", dlugosc_linii);
  for(int i=0; i<dlugosc_linii; i++){
    printf("%c", linia[i]); // założenie: na końcu linii jest \n
  }
  
  printf("Linia o długości %d wypisana jako napis:\n", dlugosc_linii);
  printf("%s", linia);
}