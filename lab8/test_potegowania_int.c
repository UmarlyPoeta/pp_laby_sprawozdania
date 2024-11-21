#include <stdio.h>
#include <limits.h>

// funkcja oblicza potÄgÄ caĹkowitÄ liczby caĹkowitej
int potega_int(int m, int n);
int oblicz_wielomian_int_Horner(int *a, int stopien, int x);
int oblicz_wielomian_int(int tab_wsp[], int argument);

int main (void)
{
  int i;
  for (i = 0; i < 10; i++){
    printf("i = %d \t2^i = %d \t(-3)^i = %d\n", 
     i, potega_int(2,i), potega_int(-3,i));
  }
  int wspolczynniki[20];
  for (i = 1; i < 20; i++) {
    wspolczynniki[i] = i + 1;
  }
  int stopien = 20; 
  int x = 2; 
  printf("Wartość wielomianu dla x = %d: %d\n", x, oblicz_wielomian_int_Horner(wspolczynniki, stopien, x));

  for (i = 0; i < 1000000; i++) {
    oblicz_wielomian_int_Horner(wspolczynniki, stopien, x);
  }

  printf("Wartość wielomianu dla x = %d: %d\n", x, oblicz_wielomian_int(wspolczynniki, x));

  return 0;
}

// funkcja oblicza potÄgÄ caĹkowitÄ liczby caĹkowitej
int potega_int(int podstawa, int wykladnik)
{
  int potega = 1;
  for (int i = 1; i <= wykladnik; i++){
    if (potega > INT_MAX / podstawa) {
      printf("Przekroczenie zakresu INT_MAX\n");
      return INT_MAX;
    }
    potega *= podstawa;
  }
  return potega;
}

int oblicz_wielomian_int_Horner(int *a, int stopien, int x)
{
  int wynik = a[stopien];
  for (int i = stopien - 1; i >= 0; i--) {
    if (wynik > (INT_MAX - a[i]) / x) {
      printf("Przekroczenie zakresu INT_MAX\n");
      return INT_MAX;
    }
    wynik = wynik * x + a[i];
  }
  return wynik;
}

int oblicz_wielomian_int(int tab_wsp[], int argument)
{
  int wynik = 0;
  for (int i = 0; i <= 4; i++) {
    int potega = potega_int(argument, i);
    if (wynik > INT_MAX - tab_wsp[i] * potega) {
      printf("Przekroczenie zakresu INT_MAX\n");
      return INT_MAX;
    }
    wynik += tab_wsp[i] * potega;
  }
  return wynik;
}

// modyfikacje: funkcja potega_int_1 - sprawdzanie w trakcie obliczeĹ  
//    czy obliczane wartoĹci nie przekraczajÄ zakresu liczb caĹkowitych INT_MAX
//    (zdefiniowane w pliku limits.h)


// Przypadek schematu Hornera dla wielomianu 4 stopnia
// a[0] + a[1]*x + a[2]*x^2 + a[3]*x^3 + a[4]*x^4:
//
// a[0] + x*( a[1] + x*( a[2] + x*( a[3] + x*a[4]) ) )
//