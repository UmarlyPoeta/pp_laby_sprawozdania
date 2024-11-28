#include <stdlib.h>
#include <stdio.h>

// deklaracja poczÄtkowa funkcji
void prosta_funkcja(int *int_ptr, double *doublePtr);
// po sprawdzeniu dziaĹania programu:
// 1. zmiana deklaracji (prototypu) prosta_funkcja, tak aby mogĹa przyjmowaÄ
//    dwa wskazane argumenty z funkcji main: wskaznik_do_int i double_p
//    (starÄ deklaracjÄ najlepiej zakomentowaÄ i utworzyÄ nowÄ z odpowiednimi
//    typami argumentĂłw - znalezionymi w funkcji main)
//    - nazwy argumentĂłw prosta_funkcja: int_ptr i doublePtr
// cd. zmiana definicji prosta_funkcja

int main (void)
{

  int i = 1;
  
  int * wskaznik_do_int = &i; // wskazniki zawsze inicjowane przy definiowaniu  
  
  printf("\nprzed wywoĹaniem prostej funkcji\n"); 
  printf("\nwartoĹÄ zmiennej typu int i jej adres:    i = %d, &i = %lu \n", 
	 i, &i);
  printf("to samo co powyĹźej, za pomocÄ wskaĹşnikĂłw: i = %d, &i = %lu \n", 
	 *wskaznik_do_int, wskaznik_do_int);
  
  double pi = 3.14;
  double * double_p = NULL;
  printf("\nwartoĹÄ zmiennej pi: %lf, adres zmiennej pi: %lu\n", pi, &pi);
  printf("wskaĹşnik double_p zainicjowany wartoĹciÄ NULL:      %lu\n", double_p);
  double_p = &pi;
  printf("wskaĹşnik double_p po podstawieniu wartoĹci &pi:     %lu\n", double_p);
  
  // UWAGA: arytmetyka wskaĹşnikĂłw:
  double_p++;
  printf("wskaĹşnik double_p po wykonaniu operacji double_p++: %lu\n", double_p);
  // na co teraz pokazuje *double_p ????? - nie wiadomo,
  // co siÄ stanie gdy wykonanmy (*double_p)++ ????? - nie wiadomo, wiÄc...
  double_p--; // ...wracamy do poprzedniej wartoĹci &pi
  
  // wywoĹanie funkcji 
  //prosta_funkcja();
  // 4. wywoĹanie funkcji prosta_funkcja z nowymi argumentami wskaznik_do_int i double_p
  //    (po wykomentowania poprzedniego obecnie niepoprawnego wywoĹania)
    prosta_funkcja(wskaznik_do_int, double_p);
  printf("\n\npo powrocie z prostej funkcji: \n");
  printf("wartoĹÄ zmiennej typu int i jej adres:    i = %d, &i = %lu \n", 
	 i, &i);
  printf("to samo co powyĹźej, za pomocÄ wskaĹşnikĂłw: i = %d, &i = %lu \n", 
	 *wskaznik_do_int, wskaznik_do_int);
  printf("\nwartoĹÄ zmiennej pi i jej adres:           pi = %lf, &pi = %lu\n", 
	 pi, &pi);
  printf("to samo co powyĹźej, za pomocÄ wskaĹşnikĂłw:  pi = %lf, &pi = %lu \n", 
	 *double_p, double_p);

}

// 2. zmiana definicji prosta_funkcja
//    - dostosowanie nagĹĂłwka do prototypu (dwa argumenty)
void prosta_funkcja(int *int_ptr, double *doublePtr)
{

  // 3. wydrukowanie wartoĹci argumentĂłw i zmiennych, na ktĂłre wskazujÄ
    printf("\n\nwewnÄtrz prostej funkcji: \n");

  // 4. zmiana wywoĹania prosta_funkcja w funkcji main

  // 5. modyfikacja wartoĹci wskazywanych zmiennych
    *int_ptr = 5;
    *doublePtr = 2.71;
  // 6. wydrukowanie wartoĹci argumentĂłw i zmiennych, na ktĂłre wskazujÄ
    printf("wartoĹÄ zmiennej typu int i jej adres:    i = %d, &i = %lu \n",
        *int_ptr, int_ptr);
    printf("Wartosc zmiennej typu int i jej adres po inkrementacji: i = %lf, &i = %lf \n",
        *doublePtr, doublePtr);
  // 7. uruchomienie i sprawdzenie dziaĹania: jakie wartoĹci drukowane sÄ
  //    w funkcji prosta funkcja, a jakie w funkcji main

    // 8. modyfikacja wartości przesłanych argumentów
    int_ptr++;
    doublePtr++;

    // 9. wydrukowanie wartości argumentów i zmiennych, na które aktualnie wskazują
    //    - czy ma to jakiś sens?
    printf("wartość zmiennej typu int po modyfikacji:    i = %d, &i = %lu \n", 
             *int_ptr, int_ptr);
    printf("wartość zmiennej typu double po modyfikacji: pi = %lf, &pi = %lu \n", 
             *doublePtr, doublePtr);

  return;
}

