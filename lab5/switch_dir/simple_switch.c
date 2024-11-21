#include <stdio.h>

#define TOLERANCE 1

int main(void)
{
  
  char c;
  for(;;){  // wykonywanie nieskończenie wiele razy

    printf("\nWprowadź cyfrę od 0 do 5 lub 6 aby zakonczyc program: \n");  
    scanf(" %c",&c); // wielokrotne wczytywanie pojedynczego znaku (jak pozbyć się \n ?)
    switch (c) {
    case '0': 
      printf("Wprowadzono: 0\n");
      break;
    case '1':
      printf("Wprowadzono: 1\n");
    case '2':
      printf("Wprowadzono: 1 lub 2\n");
      break;
    case '3':
      printf("Wprowadzono: 3\n");
      break;
    case '4':
    case '5':
      printf("Wprowadzono: 4 lub 5\n");
      break;
    case '6':
      printf("pomyslnie zakonczono program");
      return 0;
    default:
      printf("Wprowadzono: znak spoza zakresu 0-5\n");
      break;
    }
  }

}
