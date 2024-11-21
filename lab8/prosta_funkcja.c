#include <stdio.h>
#include <math.h>

// deklaracja funkcji
void prosta_funkcja(int parametr);

int main (void)
{

  // 1. definicja zmiennej test np. typu int z inicjowaniem
  int test = 5;
  
  // 2. drukowanie wartoĹci zmiennej test
  printf("przed wywoĹaniem prostej funkcji: %d\n", test);

  // wywoĹanie funkcji
  //prosta_funkcja();

  // 6. (po wykomentowaniu wywoĹania powyĹźej) wywoĹanie funkcji z argumentem
  prosta_funkcja(test);
  // 7., 8., 9. - co trzeba zmieniÄ po wykonaniu krokĂłw 5 i 6, Ĺźeby program zadziaĹaĹ?

  // 2. drukowanie wartoĹci zmiennej test
  printf("po powrocie z prostej funkcji: %d\n", test);

}

// 5. zmiana definicji - przyjmowanie argumentu
void prosta_funkcja( int parametr )
{

  // 3. definicja zmiennej test np. typu int z inicjowaniem
  int test = 10;
  // 4. drukowanie wartoĹci zmiennej test
  printf("wewnÄtrz prostej funkcji: %d zmienna lokalna \n", test);

  // 11. drukowanie wartoĹci argumentu
  printf("wewnÄtrz prostej funkcji: %d argument przed modyfikacjÄ \n", parametr);
  
  // 10. zmiana wartoĹci przesĹanego argumentu
  parametr = 7;
  
  // 11. drukowanie wartoĹci argumentu
  printf("wewnÄtrz prostej funkcji: %d argument po modyfikacji \n", parametr);

  return;
}

