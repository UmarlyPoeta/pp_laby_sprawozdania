#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define OKRESLONA_DLUGOSC 10


int main( void ) // program kopiowania z stdin na stdout
{
    /*
    srand(time(NULL));
  int c;
  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar ();
  }
  
  // 1. zamiana programu jak wyĹźej na program wykorzystujÄcy formÄ skrĂłtowÄ 
  // (po sprawdzeniu dziaĹania programu oryginalnego, naleĹźy go wykomentowaÄ w caĹoĹci,
  // a nastÄpnie napisaÄ (odkomentowaÄ) wersjÄ skrĂłconÄ (poniĹźej)
  // while( (c = getchar()) != EOF) { putchar(c); }
  // - po sprawdzeniu poprawnoĹci dziaĹania wprowadzenie koĹczenia wczytywania
  //   po wpisaniu znaku koĹca linii

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            break;
        }
        putchar(c);
    }
  
  // 2. Dodanie wczytywania do tablicy znakĂłw
  //    - definicja tablicy przed pÄtlÄ (z zadanÄ maksymalna dĹugoĹciÄ napisu)
  //    - po wczytaniu do zmiennej c i wypisaniu na ekranie, podstawienie do tablicy
  //    - uwaga na zakoĹczenie tablicy:
  //       - dĹugoĹÄ nie moĹźe byÄ zbyt duĹźa (wprowadzenie nowych warunkĂłw)
  //       - koniec musi byc zawsze zgodny z konwencjÄ

    char buffer[MAX_LENGTH];
    int i = 0;

    while ((c = getchar()) != EOF && i < MAX_LENGTH - 1) {
        if (c == '\n') {
            break;
        }
        putchar(c);
        buffer[i++] = c;
    }
    buffer[i] = '\0'; // Null-terminate the string
  
  // 3. Dodanie wypisywania wczytanych znakĂłw jako liczb caĹkowitych
    for (int j = 0; j < i; j++) {
        printf("%d ", buffer[j]);
    }
    printf("\n");
  // Program switch.c - w innym pliku

  //-------------------------------- 3.0 ------------------------------------

  // 5. Wpisanie kodu (na podstawie wykĹadu) zliczajÄcego liczbÄ znakĂłw w tablicy
  //    - ewentualna zamiana pÄtli for na while
    int count = 0;
    int d = 0;
    while (buffer[d] != '\0') {
        count++;
        d++;
    }
    printf("Number of characters: %d\n", count);
  
  // 6. Wpisanie kodu (na podstawie wykĹadu) przepisujÄcego zawartoĹÄ jednej tablicy
  //    znakĂłw do drugiej (ewentualna zamiana pÄtli while na do)
    char copy[MAX_LENGTH];
    int k = 0;
    do {
        copy[k] = buffer[k];
        k++;
    } while (buffer[k] != '\0');
    copy[k] = '\0';

    printf("Copied string: %s\n", copy);
  // 7. Wpisanie kodu (na podstawie wykĹadu) porĂłwnujÄcego zawartoĹÄ dwĂłch tablic
  //    - ewentualna zamiana pÄtli do na while lub for
    int a =0, b = 0;
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    int are_equal = 1;
    for (;s1[a] != '\0' || s2[b] != '\0';) {
        if (s1[a] != s2[b]) {
            are_equal = 0;
            break;
        }
        a++;
        b++;
    }

    if (are_equal) {
        printf("The arrays are equal.\n");
    } else {
        printf("The arrays are not equal.\n");
    }

    */
  //-------------------------------- 4.0 ------------------------------------

  // 8. Napisanie kodu tworzenia tablicy o okreslonej dĹugoĹci i wypeĹniania
  //     losowymi znakami ( z tablicy ASCII - od 0 do 127, lub dla wybranego
  //     podzbioru znakĂłw, np. maĹych liter lub t.p.)
  char tab[OKRESLONA_DLUGOSC];
  for (int i = 0; i < OKRESLONA_DLUGOSC; i++){
    tab[i] = (char) (rand() % 26 + 97);
  }

  // 9. Napisanie kodu tworzenia histogramu dla otrzymanej tablicy
  //    ( for(....) histogram[ tablica[i] - pierwszy_znak ] ++; )
    int histogram[26] = {0};

    for (int i = 0; i < OKRESLONA_DLUGOSC; i++) {
        histogram[tab[i] - 'a']++;
    }

  // 10. graficzna prezentacja histogramu
  for (int i = 0; i < 26; i++){
    printf("%d %c ",i ,histogram[i]);
    for (int j = 0; j < histogram[i]; j++){
        printf("#");
    }
    printf("\n");
  }
  
  //-------------------------------- 5.0 ------------------------------------

 
    return 0;
}

