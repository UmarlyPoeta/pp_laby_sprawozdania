#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

// sposób na łatwą zmianę typu dla wszystkich zmiennych w programie
#define SCALAR double
//#define SCALAR float
#define TOLERANCJA 1.e-10
#define SMALL_NUMBER 1.e-20 // czy wystarczy jedna wartość dla float i dla double?

// Testowanie: konstrukcji sterujących (a także nazw zmiennych,
// zakresów widoczności i czasu życia)
int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  // typ a, b, c ustalany poprzez symbol SCALAR
  SCALAR a, b, c;
  // rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
  // input - uodpornianie na błędy wczytywania danych 
  printf("\nPodaj parametr a: "); scanf("%lf",&a); // adres! (miejsce na wpisanie wartości)
  printf("Podaj parametr b: "); scanf("%lf", &b); // uwaga: inny format dla float!
  printf("Podaj parametr c: "); scanf("%lf", &c);

  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie

    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    exit(-1);

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
        SCALAR real_part = -b / (2 * a);
        SCALAR imaginary_part = sqrt(-delta) / (2 * a);
        printf("Dwa pierwiastki zespolone: x1 = %.12le + %.12lei, x2 = %.12le - %.12lei\n",
          real_part, imaginary_part, real_part, imaginary_part);

      } else if (delta == 0){

	printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", -b/(2*a) );

      } else {

	SCALAR temp = sqrt(delta);

  SCALAR x1 = (-b - temp) / (2 * a);
  SCALAR x2 = (-b + temp) / (2 * a);

  if (fabs(a * x1 * x1 + b * x1 + c) > TOLERANCJA) {
    printf("Pierwiastek x1 = %.12le nie spełnia równania w granicach tolerancji.\n", x1);
  }
  else if (fabs(a * x2 * x2 + b * x2 + c) > TOLERANCJA) {
    printf("Pierwiastek x2 = %.12le nie spełnia równania w granicach tolerancji.\n", x2);
  }
  else{
	printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
	       (-b-temp)/(2*a), (-b+temp)/(2*a) );  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
  }
  }
  }
  
  for (int k = 2; k <= 10; k++) {
    b = pow(10, k);
    a = 1.0;
    c = 1.0;



    SCALAR delta = b * b - 4 * a * c;
    SCALAR temp = sqrt(delta);
    SCALAR x1 = (-b - temp) / (2 * a);
    SCALAR x2 = (-b + temp) / (2 * a);

    printf("\n\nb = 10^%d:\n", k);
    printf("x1 = %.12le, x2 = %.12le\n", x1, x2);
    printf("Sprawdzenie: f(x1)= %.12le\n", a * x1 * x1 + b * x1 + c);
    printf("Sprawdzenie: f(x2) = %.12le\n", a * x2 * x2 + b * x2 + c);
  }
  
  return(0);

}
