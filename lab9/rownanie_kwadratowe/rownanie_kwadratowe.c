#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

// sposób na łatwą zmianę typu dla wszystkich zmiennych w programie
#define SCALAR double
//#define SCALAR float
#define TOLERANCJA 1.e-10
#define SMALL_NUMBER 1.e-20 // czy wystarczy jedna wartość dla float i dla double?

// Prototyp funkcji rownanie_kwadratowe
// Zwraca 0 w przypadku sukcesu, -1 w przypadku błędu
// Argumenty:
// a, b, c - współczynniki równania kwadratowego
// x1, x2 - wskaźniki na zmienne, w których zostaną zapisane pierwiastki
int rownanie_kwadratowe(SCALAR a, SCALAR b, SCALAR c, SCALAR *x1, SCALAR *x2);

int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  // typ a, b, c ustalany poprzez symbol SCALAR
  SCALAR a, b, c;
  SCALAR *x1 = (SCALAR *)malloc(sizeof(SCALAR));
  SCALAR *x2 = (SCALAR *)malloc(sizeof(SCALAR));

  // input - uodpornianie na błędy wczytywania danych 
  printf("\nPodaj parametr a: "); scanf("%lf",&a); // adres! (miejsce na wpisanie wartości)
  printf("Podaj parametr b: "); scanf("%lf", &b); // uwaga: inny format dla float!
  printf("Podaj parametr c: "); scanf("%lf", &c);

  // Wywołanie funkcji rownanie_kwadratowe
  if (rownanie_kwadratowe(a, b, c, x1, x2) == 0) {
    printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n", x1, x2);
  }

  for (int k = 2; k <= 10; k++) {
    b = pow(10, k);
    a = 1.0;
    c = 1.0;

    SCALAR delta = b * b - 4 * a * c;
    SCALAR temp = sqrt(delta);
    *x1 = (-b - temp) / (2 * a);
    *x2 = (-b + temp) / (2 * a);

    printf("\n\nb = 10^%d:\n", k);
    printf("x1 = %.12le, x2 = %.12le\n", x1, x2);
    printf("Sprawdzenie: f(x1)= %.12le\n", a * (*x1) * (*x1) + b * (*x1) + c);
    printf("Sprawdzenie: f(x2) = %.12le\n", a * (*x2) * (*x2) + b * (*x2) + c);
  }
  free(x1);
  free(x2);
  return(0);
  return(0);
}

// Definicja funkcji rownanie_kwadratowe
// Funkcja oblicza pierwiastki równania kwadratowego
int rownanie_kwadratowe(SCALAR a, SCALAR b, SCALAR c, SCALAR *x1, SCALAR *x2) {
  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie

    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    return 0;

  }
  else{

    if(fabs(a) < TOLERANCJA) { // równanie liniowe
      printf("x wynosi %.12le\n", (-c / b));
      //co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?

    }
    else{

      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c; // problem jeśli delta bliskie b*b (w skończonej precyzji)
                           // wtedy odejmowanie b i sqrt(delta) traci cyfry znaczące

      if(delta<0){
        exit(0);

      } else if (delta == 0){

    printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", -b/(2*a) );
    *x1 = -b/(2*a);
    *x2 = -b/(2*a);
      } else {

  SCALAR temp = sqrt(delta);

  *x1 = (-b - temp) / (2 * a);
  *x2 = (-b + temp) / (2 * a);

  if (fabs(a * *x1 * *x1 + b * *x1 + c) > TOLERANCJA) {
    printf("Pierwiastek x1 = %.12le nie spełnia równania w granicach tolerancji.\n", x1);
  }
  else if (fabs(a * *x2 * *x2 + b * *x2 + c) > TOLERANCJA) {
    printf("Pierwiastek x2 = %.12le nie spełnia równania w granicach tolerancji.\n", x2);
  }
  else{
  printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
         (-b-temp)/(2*a), (-b+temp)/(2*a) );
  return 1;  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
  }
  }
  }

  return 0;
}
