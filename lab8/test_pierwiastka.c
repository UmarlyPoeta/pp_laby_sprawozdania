#include<stdio.h>
#include<math.h>

#define ACCURACY (1.e-5) // do przeprowadzania obliczeĹ i sprawdzenia dokĹadnoĹci wyniku

// 1. i 2. zaprojektowanie prototypu funkcji obliczania pierwiastka i umieszczenie go 
//       jako deklaracji funkcji
double pierwiastek(double arg);

// 0. przed wykonaniem Äwiczenia caĹy kod w funkcji main (analiza, uruchomienie)   
int main( void ) {
  
  double liczba;
  
  for(;;){
    
    printf("\nPodaj wartoĹÄ liczby dodatniej (-1 koĹczy program):\n");
    scanf("%lf",&liczba);

    // w wariancie pierwszym kaĹźda liczba ujemna przerywa program
    // (nie wywoĹujemy funkcji dla argumentĂłw ujemnych)
    // przy modyfikacji kontraktu moĹźna to zmieniÄ
    if(liczba<0.0) break;

    // 0. przed wykonaniem Äwiczenia caĹy kod w funkcji main (analiza, uruchomienie) 
    
    // 3. wywoĹanie zaprojektowanej funkcji obliczania pierwiastka
    double wynik_pierwiastka = pierwiastek(liczba);
    // 4. wydruk obliczonego pierwiastka
    printf("pierwiastek wynosi %18.15lf\n", wynik_pierwiastka);
    // ewentualne dodatkowe wywoĹania funkcji obliczania pierwiastka, zgodnie z instrukcjÄ

    // 5. zakoĹczenie nieskoĹczonej pÄtli for i funkcji main

    

    // 6. nagĹowek - poczÄtek definicji funkcji
// definicja funkcji + komentarze (z komentarzy moĹźna tworzyÄ dokumentacjÄ):

    
    // 7. przeksztaĹcenie kodu poniĹźej, tak aby stanowiĹ treĹÄ funkcji
    //    (z odpowiednim argumentem i wĹasnymi zmiennymi lokalnymi)
    //    (uwaga: brak nieskoĹczonej pÄtli for - co zamiast break?)

    
    // wydruki kontrolne - moĹźna je wyĹÄczyÄ po zdebugowaniu funkcji
    //printf("\nliczba do obliczenia pierwiastka: %18.15lf\n", liczba);
    //printf("\tzaĹoĹźona dokĹadnoĹÄ (wzglÄdna) obliczania pierwiastka: %18.15lf\n", 
	  // ACCURACY);
    // ten wydruk moĹźna (po odpowiedniej modyfikacji skopiowaÄ takĹźe do main)
    //printf("\tpierwiastek liczby: obliczony %18.15lf, dokĹadny %18.15lf\n", 
    // wynik_pierwiastka, sqrt(liczba));
    //printf("liczba iteracji %d, bĹÄd bezwzglÄdny: %18.15lf, bĹÄd wzglÄdny: %18.15lf\n",
    //iteracje, wynik_pierwiastka-sqrt(liczba), (wynik_pierwiastka-sqrt(liczba))/sqrt(liczba));


    // 8. zamiana zakoĹczenia funkcji main (z pÄtlÄ for) na zakoĹczenie funkcji
    //    obliczania pierwiastka
    printf("Pierwiastek z liczby 25 wynosi %18.15lf\n", pierwiastek(25.0));
    double suma_pierwiastkow = pierwiastek(9.0) + pierwiastek(16.0);
    printf("Suma pierwiastków z 9 i 16 wynosi %18.15lf\n", suma_pierwiastkow);
    double liczba_double = 16.0;
    double wynik_zagniezdzony = pierwiastek(pierwiastek(liczba_double));
    printf("Podwójny pierwiastek z liczby 16 wynosi %18.15lf\n", wynik_zagniezdzony);
    // ---------------- 3.0 --------------------------------
    
  }

  return 0;
}

double pierwiastek(double arg){
  // funkcja oblicz_pierwiastek oblicza pierwiastek za pomocÄ wzoru Herona
  //               dla dowolnej liczby podwĂłjnej precyzji wiÄkszej od zera
  // czy kontrakt wymaga specjalnych dziaĹaĹ dla liczb ujemnych?
  // wariant 1. funkcja zakĹada, Ĺźe argument jest nie mniejszy niĹź zero
  // wariant 2. dla liczb mniejszych od zera funkcja zwraca kod bĹÄdu: -1
  //   implementacja w kodzie, np.
  //  if(arg<0){
  //    // obsĹuga bĹÄdu wejĹcia, np.
  //    return(-1.0); // wyjaĹnienie w dokumentacji
  //  }
  double pierwiastek = 1.0;
  double temp; int iteracje=0;
  // obliczenia pierwiastka za pomocÄ wzoru Herona
  do{
      iteracje++;
      temp = pierwiastek;
      pierwiastek = 0.5 * (temp + arg/temp);

      // dodatkowe wydruki kontrolne
      // np. do debugowania dziaĹania funkcji

    /*printf("wartoĹÄ %20.15lf, \tbĹÄd  %20.15lf,     bĹÄd kwadratu %20.15lf\n", 
	   pierwiastek, fabs(pierwiastek - temp)/pierwiastek, 
	   fabs(pierwiastek*pierwiastek - arg)/arg);
    */  
      
      // sprawdzenie warunku wyjĹcia z pÄtli - bĹÄd wzglÄdny obliczania pierwiastka
    } while(fabs(pierwiastek*pierwiastek - arg)/arg > ACCURACY); 

    return pierwiastek;
}
