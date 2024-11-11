#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROZMIAR_TABLICY 10

void main(void)
{

  

  // 1. inicjowanie tablicy w momencie definowania:

  // a. wszystkie wartoĹci
  int tab_int[ROZMIAR_TABLICY];
  // b. poczÄtkowe wartoĹci
  int tablica_int[ROZMIAR_TABLICY] = {0,2,3,4,5,6,7,8,9,1};
  
  // 2. nadanie wartoĹci w pÄtli
  // a. zaleĹźnych od wartoĹci zmiennej sterujacej
  for (int i = 0; i < ROZMIAR_TABLICY; i++){
    tablica_int[i] = i * 2;
  }
  // b. wczytywanych z klawiatury za pomocÄ scanf
  for (int i = 0; i < ROZMIAR_TABLICY; i++){
    printf("podaj wartosc do tablicy do zadania 2b: ");
    scanf("%d", &tablica_int[i]);
  }
  // 3. zamiana pÄtli for nadawania wartoĹci na pÄtlÄ while
  int j = 0;
  while (j < ROZMIAR_TABLICY){
    printf("podaj wartosc ale dla petli while: ");
    scanf("%d", &tablica_int[j]);
    j++;
  }
  // 4. zamiana poniĹźszej pÄtli for na pÄtlÄ do
  // (jak zwykle najlepiej wykomentowaÄ starÄ pÄtlÄ i wpisaÄ poniĹźej nowÄ pÄtlÄ)

  int i = 0;
  do{
    printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
    i++;
  } while (i < ROZMIAR_TABLICY);

  // 5. wyszukiwanie wartoĹci maksymalnej w tablicy (pÄtla for)
  int max = -1;
  for (int i = 0; i < ROZMIAR_TABLICY; i++){
    if (max < tablica_int[i]){
      max = tablica_int[i];
    }
  }
  // 6. obliczanie sumy elementĂłw tablicy (pÄtla while)
  int k = 0, sum = 0;
  while (k < ROZMIAR_TABLICY){
    sum += tablica_int[k];
    k++;
  }
  //-------------------------------- 3.0 ------------------------------------
  
  // 7. tablica z wartoĹciami losowymi i wyszukiwanie zadanych wartoĹci

  // a. nowa definicja tablicy (np. tablicy znakĂłw)
  srand(time(NULL));
  int new_tab[ROZMIAR_TABLICY];
  // b. nadawanie wartoĹci losowych wyrazom tablicy
  //    (np. liczby z zakresu 33-126, czyli odpowiadajÄce znakom ASCII)
  //    -> odpowiednie wydruki
  for (int i =0 ; i < ROZMIAR_TABLICY; i++){
    new_tab[i] = rand() % 93 + 33;
  }
  for (int i =0; i < ROZMIAR_TABLICY; i ++){
    printf("%d ", new_tab[i]);
  }
  printf("\n");
  // c. sprawdzenie losowoĹci - obliczenie wartoĹci Ĺredniej w tablicy
  //    (w odpowiedniej pÄtli) - porĂłwnanie z teoretycznÄ ĹredniÄ
  //    -> odpowiednie wydruki
  int ssum = 0;
  for (int i = 0; i < ROZMIAR_TABLICY; i++){
    ssum += new_tab[i];
  }
  double srednia = (double)ssum / ROZMIAR_TABLICY;
  printf("srednia w tablicy wynosi %lf\n", srednia);
  if (srednia > 46.5){
    printf("srednia jest wieksza od sredniej teoretycznej\n");
  }
  else{
    printf("srednia jest mniejsza od sredniej teoretycznej\n");
  }
  for (int i =0; i < ROZMIAR_TABLICY; i ++){
    printf("%d ", new_tab[i]);
  }
  printf("\n");
  // d. wyszukiwanie zadanej wartoĹci
  //    -> odpowiednie wydruki w momencie znalezienia wartoĹci
  //    np. "Znaleziono wartoĹÄ %.. w %d elemencie tablicy\n", ...
  int zadana_wartosc;
  printf("podaj zadana wartosc: ");
  scanf("%d", &zadana_wartosc);

  //  d1. wyszukanie tylko jednej (pierwszej) wartoĹci - pÄtla while
  //      (lub pÄtla for i break)
  
  for (int i = 0; i < ROZMIAR_TABLICY; i++){
    if (new_tab[i] == zadana_wartosc){
      printf("Znaleziono pierwsza wartosc %d w %d elemencie tablicy\n", zadana_wartosc, i);
      break;
    }
  }

  //  d2. wyszukanie (i wypisanie) wszytskich wartoĹci - pÄtla for
  //      (lub pÄtla while)

  for (int i = 0; i < ROZMIAR_TABLICY; i++){
    if (new_tab[i] == zadana_wartosc){
      printf("Znaleziono wartosc %d w %d elemencie tablicy\n", zadana_wartosc, i);
    }
  }
  //-------------------------------- 4.0 ------------------------------------

  
}

