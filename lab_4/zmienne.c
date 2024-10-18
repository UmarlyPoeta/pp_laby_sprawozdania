// //** zmienne.c - prosty program ilustrujÄcy wykorzystanie i drukowanie zmiennych oraz
// //**             ewentualne problemy z precyzjÄ przechowywania

// //** sĹowo USES informuje, Ĺźe w pliku bÄdÄ uĹźywane funkcje opisane w plikach nagĹĂłwkowych
#include <stdio.h> // USES - deklaracje funkcji wejĹcia/wyjĹcia
#include <math.h> // USES - deklaracje funkcji matematycznych
#include <stdbool.h> // for _Bool type

// //** definicja symbolu - w kodzie uĹźywany jest symbol, preprocesor zamienia kaĹźde wystÄpienie
// //** symbolu w kodzie na podany ĹaĹcuch znakĂłw
#define TOLERANCE 1e-12 // tolerancja - wartoĹÄ wzglÄdnej rĂłĹźnicy liczb (l1-l2)/l1
                        // //** poniĹźej ktĂłrej dwie liczby zmiennoprzecinkowe sÄ uznawane za rĂłwne
// //** UWAGA: tolerancja powinna byÄ rĂłĹźna dla float i double (tutaj wartoĹÄ typowa dla double)
#define JednaTrzeciaFloat (1.0f/3.0f) // 1/3 z dokĹadnoĹciÄ float (czasem nazwa zastÄpuje komentarz)
#define JednaTrzecia (1.0/3.0) // uwaga na odczyt przy podstawieniu (rola nawiasĂłw)
#define BEZ_NAWIASOW 1.0/3.0
#define DODAWANIE 1.0 + 2.0

#define SIEDEM 7 // wystÄpienia symbolu SIEDEM sÄ w kodzie zamieniane na 7
#define OSIEM 8
#define PIEC 5
// //** bez uĹźycia #define i nazwanych wartoĹci (np. TOLERANCE - moĹźna jeszcze zwiekszyÄ czytelnoĹÄ nazwy)
// //** w kodzie pojawiajÄ siÄ tzw. "magic numbers" - liczby w kodzie, o ktĂłrych po pewnym czasie
// //** nikt nie wie co oznaczajÄ, dlaczego tyle wynoszÄ, skÄd siÄ wziÄĹy


// //** zwrot kodu bĹÄdu lub sukcesu (zwyczajowo kod sukcesu -> 0)
int main(void)
{

  /* 1. STANDARDOWE DEKLARACJE-DEFINICJE I WYPISYWANIE WARTOĹCI ZMIENNYCH */

  // //** definicje
    int n; // nazwy zmiennych - znaczÄce, niekoniecznie krĂłtkie, z duĹźymi i maĹymi literami
  //        // nazwy krĂłtkie, nieznaczÄce dla zmiennych pomocniczych stosowanych lokalnie
    char znak_do_testowania;

  // //** podstawianie wartoĹci - inicjowanie
    n = 7; // instrukcja przypisania - staĹe liczbowe i podstawowe operacje
    znak_do_testowania = 'a'; // staĹa znakowa

    printf("\nwartoĹÄ zmiennej n = %d, wartoĹÄ zmiennej znak_do_testowania = %c\n", n, znak_do_testowania );

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WĹASNE (po odkomentowaniu powyĹźszego kodu i sprawdzeniu poprawnoĹci jego dziaĹania)
  // //** - zdefiniowanie po jednej zmiennej kaĹźdego z omawianych na wykĹadzie typĂłw - w tym typĂłw
  // //**   z okreĹleniami: short, long, unsigned
  // //** - podstawienie do kaĹźdej zmiennej dowolnie wybranej, poprawnej wartoĹci
  // //** - zdefiniowanie poĹÄczone z nadaniem wartoĹci (zainicjowniem) ponownie dla jednej zmiennej
  // //**   kaĹźdego z omawianych na wykĹadzie typĂłw
  // //** - wypisanie wartoĹci zdefiniowanych zmiennych na ekranie w oknie terminala: dobranie odpowiedniego
  // //**   symbolu formatowania dla kaĹźdego typu - sprawdzenie poprawnoĹci dziaĹania (czyli wydrukowania
  // //**   nadanej wartoĹci)
  // //** - sprawdzenie efektu bĹÄdnego uĹźycia symbolu formatowania: kiedy wydruk przestaje byÄ poprawny
  // //**   (np. zmienna typu unsigned drukowana jako int, zmienna float drukowana jako int itd., itp,)
    short int d01 = 42; // mniejszy int
    unsigned long long d02 = 10000000000000000; // naturalne bardzo duże
    float d03 = 5.32; // zmiennoprzecinkowa 
    double d04 = 5.231324; // zmiennoprzecinkowa ale dokladniejsza do wiekszej miejsc po przecinku
    char d05 = 'd'; // znak ascii
    int d06 = 0; // calkowite
    printf("%d %llu %f %lf %c %d\n\n", d01, d02, d03, d04, d05, d06);

    printf("bledne uzynie\n");
    printf("%c %llu %d %lf %d %f", d01, d02, d03, d04, d05, d06);


  /* 2. PROSTE OPERACJE */

  // //** operatory i ich priorytety
    int m;
    m = 2 * n + 3;
    int o = 2 * (n + 3); // definicja z inicjowaniem
    printf("\nn = %d, (2 * n + 3) = %d != (2 * (n + 3)) = %d\n", n, m, o);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WĹASNE (po odkomentowaniu powyĹźszego kodu i sprawdzeniu poprawnoĹci jego dziaĹania)
  // //** - napisanie kilku (2-3) wyraĹźeĹ arytmetycznych, w ktĂłrych wynik zaleĹźaĹ bÄdzie od kolejnoĹci
  // //**   zapisu i priorytetĂłw wykonywanych operacji - testowanie poprawnego uĹźycia nawiasĂłw
    int e01 = (4 + 5 * 2) / 8;
    int e02 = ((41 - 12) * 12) / (2 + 10);
  // //** operatory jednoargumentowe i ich priorytety
    int p = n++;  
    n--; // powrĂłt do poczÄtkowej wartoĹci n
    int q = ++n;  
    n--; // powrĂłt do poczÄtkowej wartoĹci n
    printf("\nn = %d, wynik podstawienia: 'p = n++;' - %d, wynik podstawienia: 'q = ++n;' - %d\n", n, p, q);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WĹASNE (po odkomentowaniu powyĹźszego kodu i sprawdzeniu poprawnoĹci jego dziaĹania)
  // //** - napisanie kilku (2-3) wyraĹźeĹ arytmetycznych z operatorami jednoargumentowymi, w ktĂłrych wynik
  // //** zaleĹźaĹ bÄdzie od priorytetĂłw wykonywanych operacji - testowanie poprawnego uĹźycia nawiasĂłw
    int z01 = (p++) + ++q;
    int z02 = (q++) / (p++);
  
  // //** operatory / - dzielenie caĹkowite i % - modulo
    n = 1574;
    m = n % 7;
    o = n / 7;
    printf("\nn = %d, n/7 = %d, reszta - n%7 = %d, n = (n/7)*7 + (n%7) = %d\n", n, o, m, o*7+m);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WĹASNE (po odkomentowaniu powyĹźszego kodu i sprawdzeniu poprawnoĹci jego dziaĹania)
  // //** - napisanie kilku (2-3) wyraĹźeĹ arytmetycznych z funkcjÄ modulo:
  // //**   - sprawdzanie podzielnoĹci jednych liczb przez inne
  // //**   - dzielenie z resztÄ i uzyskiwanie pierwotnej wartoĹci (dla innych liczb niĹź w przykĹadzie
  // //**     powyĹźej)
    int z03 = 4 % 3;
    printf("4 \% 3 = %d ", z03);
    z03 = (4 / 3) + z03;
    printf("z powrotem to %d", z03);


  /* 3. DEFINICJE STAĹYCH SYMBOLICZNYCH */

  // //**** UWAGA: definicje symboli #define powinny byÄ na poczÄtku pliku (po #include) !!!!!!!!!!
           // //** kompilator w pierwszej fazie dziaĹania zastÄpi wszystkie wystÄpienia
           // //** symboli odpowiednimi wyraĹźeniami z #define
  
    int r = SIEDEM; // w assemblerze r jest zmiennÄ - ma adres, SIEDEM znika zamienione na 7
    printf("\nr = %d, staĹa SIEDEM = %d\n", r, SIEDEM); 

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WĹASNE (po odkomentowaniu powyĹźszego kodu i sprawdzeniu poprawnoĹci jego dziaĹania)
  // //** - nadanie wartoĹci kilku symbolom - wartoĹci powinny byÄ staĹymi rĂłĹźnych typĂłw liczbowych
  // //** - podstawienie do zmiennych wartoĹci za pomocÄ symboli okreslonych w #define i wydrukowanie
  // //**   wartoĹci zmiennych (UWAGA: po podstawieniu za symbol napisu stanowiÄcego zapis liczby,
  // //**   funkcjonuje on w kodzie jako liczba okreĹlonego typu - jak w przykĹadzie powyĹźej - drukujÄc
  // //**   go naleĹźy odpowiednio dobraÄ formatowanie)
    printf("piec to %d, osiem to %d", PIEC, OSIEM);

    
  /* 4. ZMIENNE ZMIENNOPRZECINKOWE: FLOAT I DOUBLE */

  // //**** UWAGA na dokĹadnoĹÄ:
  // //** wygodne wyraĹźanie w postaci liczby cyfr znaczÄcych:
  // //** x = 123456789.123456789123456
  // //**   - dla liczb pojedynczej precyzji co najmniej 6 cyfr znaczÄcych 
  // //**       pierwsze cyfry 123456 - na pewno sensowne, reszta cyfr moĹźe byÄ bez znaczenia (Ĺmieci)
  // //**         (czyli zapisana w zmiennej liczba to ok. 1234560000 +/- 10000),
  // //**   - dla liczb podwĂłjnej precyzji co najmniej 15 cyfr znaczÄcych
  // //**       123456789.123456 - na pewno sensowne 
  // //**         (zapisana liczba to ok. 123456789.123456 +/- 0.0000001)
 
  // //** definicja z inicjowaniem 
    float f = 1.0f/3.0f;  // zapis staĹej float z literkÄ f
    float g = 1.0f/3.0; 
    double d = 1.0/3.0; 
    double e = 1.0f/3.0; 

  
    printf("\nliczby zmiennoprzecinkowe:\n");
    printf("float  -  f = 1.0f/3.0f = %f  (dokĹadnie: %20.15f)\n", f, f);
    printf("float  -  g = 1.0f/3.0  = %f  (dokĹadnie: %20.15f)\n", g, g);
    printf("double -  d =  1.0/3.0  = %lf  (dokĹadnie: %20.15lf)\n", d, d);
    printf("double -  e = 1.0f/3.0  = %lf  (dokĹadnie: %20.15lf)\n", e, e);
    int s = 1/3;
    printf("(liczba caĹkowita s = 1/3 = %d - dzielenie caĹkowite)\n", s);
    int t = 1.0/3.0;
    printf("(liczba caĹkowita t = 1.0/3.0 = %d - obciÄcie przy konwersji)\n", t);
    printf("\n");
    printf("float  -  f = 1.0f/3.0f = %e  (dokĹadnie: %20.15e)\n", f, f);
    printf("double -  d =  1.0/3.0  = %le  (dokĹadnie: %20.15le)\n", d, d);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WĹASNE (po odkomentowaniu powyĹźszego kodu i sprawdzeniu poprawnoĹci jego dziaĹania)
  // //** - zdefiniowanie kilku zmiennych typĂłw float i double oraz nadanie im wartoĹci
  // //**   za pomocÄ staĹych typu float i double
  // //** - wydrukowanie wartoĹci zdefiniowanych i zainicjowanych zmiennych z wystarczajÄcÄ liczbÄ cyfr,
  // //**   tak aby zobaczyÄ jaka jest dokĹadnoĹÄ (jaki jest bĹÄd wartoĹci zmiennej w stosunku do podstawianej 
// //**   matematycznej wartoĹci (moĹźe to dotyczyÄ takĹźe prostych uĹamkĂłw dziesiÄtnych, np. 0.1, 0.2, 0.3)  
    float z05 = 4.2131123123f;
    double z06 = 2.123123123;
    printf("normalnie: %f a dokladniej %20.15f\n", z05, z05);
    printf("normalnie: %lf a dokladniej %20.15lf\n", z06, z06);

    // Obliczanie błędu wartości matematycznych
    float expected_z05 = 4.2131123123f;
    double expected_z06 = 2.123123123;
    float error_z05 = expected_z05 - z05;
    double error_z06 = expected_z06 - z06;

    printf("Blad dla z05: %f\n", error_z05);
    printf("Blad dla z06: %lf\n", error_z06);
  //-------------------------------------------- 3.0 --------------------------------------------


  /* 5. OPERATORY RELACJI I WARTOĹCI LOGICZNE  */

  // //** wartoĹÄ logiczna wyraĹźeĹ - obliczanie i zapis w zmiennych
    bool a = n<m || n>m ;
    _Bool b = n<m || n>m ;
    printf("\nWartoĹÄ logiczna wyraĹźenia: %d<%d wynosi %d (int a = n<m = %d)\n", 
  	 n, m, n<m, a);
    printf("\nWartoĹÄ logiczna wyraĹźenia: %d<%d lub %d>%d wynosi %d (_Bool b = n<m||n>m = %d)\n", 
  	 n, m, n, m, (n<m)||(n>m), b);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WĹASNE (po odkomentowaniu powyĹźszego kodu i sprawdzeniu poprawnoĹci jego dziaĹania)
  // //** - skonstruowanie kilku zĹoĹźonych wyraĹźeĹ logicznych, ktĂłre bÄdÄ np. sprawdzaÄ zasady rachunku zdaĹ:
  // //**   (p lub q) i r  =? (p i r) lub (q i r) - czy jest to rĂłwnowaĹźne
  // //**   (p i q) lub r  =? (p lub r) i (q lub r) - czy jest to rĂłwnowaĹźne
  // //** - jaka jest kolejnoĹÄ operacji i wynik w przypadku usuwania kolejnych nawiasĂłw
    int l01 = ((p || q) && r) == ((p && r) || (q && r)); // prawo rozdzielnosci koniunkcji wzgledem alternatywy - prawda
    int l02 = ((p && q) || r) == ((p || r) && (q || r)); // prawo rozdzielnosci alternatywy wzgledem koniunkcji - prawda
    int l03 = (p && q || r) == (p || r && q || r);

    printf("l01 %d l02 %d l03 %d", l01, l02, l03);

  /* 6. Operatory oraz niejawne i jawne konwersje typĂłw  */
  
   e = f; // e typu double, f typu float 
   d = 1111 + 1000 * n; // d = (double) ...;
   n = f + 2.5; // n = (int) ...;
   printf("\nNiejawne i jawne konwersje typĂłw:\n");
   printf("n = %d, f = %f, d = %lf, e = %le\n", n, f, d, e);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WĹASNE (po odkomentowaniu powyĹźszego kodu i sprawdzeniu poprawnoĹci jego dziaĹania)
  // //** - zapisanie kilku wyraĹźeĹ z operacjami na zmiennych rĂłĹźnych typĂłw i zapisie do zmiennej
  // //** - sprawdzenie otrzymanego wyniku: jakich konwersji dokonaĹ kompilator?
  // //** - zapisanie kilku wyraĹźeĹ z jawnÄ konwersjÄ typĂłw, obserwacja otrzymanych wynikĂłw (np.
  // //**   dla kilku wariantĂłw podstawienia do f:  n / 3 , (double) n / 3 ,  n / 3.0 , (double) (n / 3)
  int m01 = 4 / 3;
  int m02 = 4 / e;
  int m03 = (float) (4 / 3);
  int m04 = (float) (4.0 / 3.0);
  int m05 = (int) (((char) 97) - 'a');
  
  
    /* 7. DEFINICJE STAĹYCH SYMBOLICZNYCH (CD.) */

  // //** UWAGA: definicje symboli #define powinny byÄ na poczÄtku pliku (po #include) !!!!!!!!!!
  // //** najlepszym sposobem na "magic numbers" jest umieszczenie ich na poczÄtku pliku
  // //** zakodowanych w postaci "staĹych nazwanych" (RAZEM Z ODPOWIEDNIMI KOMENTARZAMI), np.:
           // //** brak nawiasĂłw moĹźe spowodowaÄ problemy z kolejnoĹciÄ wykonywania operacji
           // //** 3.0*1.0/3.0 moĹźe byÄ rĂłĹźne od 3.0*(1.0/3.0)
           // //** (3*1)/3 jest na pewno rĂłĹźne od 3*(1/3)
           // //** 3*1/3 moĹźe byÄ rĂłĹźne od 3*(1/3)


  // //** Precyzja staĹych i zmiennych
  // //** (uwaga na mozliwe modyfikacje dokonywane przez kompilator (np. (1.0f/3.0f)*3.0f -> 1.0)
    d = JednaTrzecia * 3.0;
    e = JednaTrzeciaFloat * 3.0;
    printf("\nPrecyzja staĹych i niejawne konwersje:\n");
    printf("(1.0/3.0)*3.0: \tJednaTrzecia -> d = %20.15lf; \n\t\tJednaTrzeciaFloat -> e = %20.15lf\n", d, e);

// //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)

    double wynik = (1.0/3.0) / BEZ_NAWIASOW;
    printf("\nWynik operacji (1.0/3.0) / BEZ_NAWIASOW = %lf\n", wynik);


    
    double wynik2 = 3.0 * DODAWANIE;
    printf("Wynik operacji 3.0 * DODAWANIE = %lf\n", wynik2);

  //-------------------------------------------- 4.0 --------------------------------------------
  
  // //** WĹASNE EKSPERYMENTY
  // //** ze zmiennymi caĹkowitymi, operatorami i ich priorytetami
  // //** np. sprawdzenie efektu operacji m+n, m++n, m+++n, m++++n, m+++++n, m+++n++++, itd.
  //printf("\nn = %d, m = %d\n", n, m);
  //o = m...n;
  //printf("\tpo operacji o = m...n = %d: n = %d, m = %d\n", o, n, m);
    printf("\nWŁASNE EKSPERYMENTY:\n");
    printf("n = %d, m = %d\n", n, m);

    o = m + n;
    printf("o = m + n = %d: n = %d, m = %d\n", o, n, m);

    o = m++ + n;
    printf("o = m++ + n = %d: n = %d, m = %d\n", o, n, m);
    m = 2 * n + 3; 
    o = m + ++n;
    printf("o = m + ++n = %d: n = %d, m = %d\n", o, n, m);

    m = 2 * n + 3; 
    o = m++ + ++n;
    printf("o = m++ + ++n = %d: n = %d, m = %d\n", o, n, m);

    m = 2 * n + 3; 
    o = m++ + n++;
    printf("o = m++ + n++ = %d: n = %d, m = %d\n", o, n, m);

    m = 2 * n + 3; 
    o = ++m + ++n;
    printf("o = ++m + ++n = %d: n = %d, m = %d\n", o, n, m);

  /* 7. PROBLEMY Z PRECYZJÄ LICZB ZMIENNOPRZECINKOWYCH */

  //  printf("\nProblemy z precyzjÄ zmiennych float i double:\n");

  // //** kĹopoty z precyzjÄ:
    float fx1 = 1.23e7f;
    float fx2 = 1.23e-7f;

    printf("\nfloat: fx1 = %20.15f, fx2 = %20.15f, \n", fx1, fx2);
    if( (fx1+fx2)-fx1 == fx2 ){
      printf("\n(fx1+fx2)-fx1 == fx2 (dla float)\n");
    }
    else {
      printf("\n(fx1+fx2)-fx1 != fx2 (dla float) ( (fx1+fx2)-fx1 = %.15lf )\n",
    	   (fx1+fx2)-fx1);
    }

  // //** kĹopoty z precyzjÄ:
    double dx1 = 1.23e7;
    double dx2 = 1.23e-7;


    printf("\ndouble: dx1 = %20.15lf, dx2 = %20.15lf, \n",
    	 dx1, dx2);
    if( (dx1+dx2)-dx1 == dx2 ){
      printf("\n(dx1+dx2)-dx1 == dx2 (dla double)\n");
    }
    else {
      printf("\n(dx1+dx2)-dx1 != dx2 (nawet dla double!) ( (dx1+dx2)-dx1 = %.15lf )\n",
    	   (dx1+dx2)-dx1);
    }
 

  // //** obsĹuga bĹÄdĂłw - temat rzeka
  // //** wariant prosty:

  // //** chcemy obliczyÄ 1 / ( (fx1+fx2)-fx1 ) - powinno byÄ rĂłwne 1/fx2

  // //** prĂłba unikniÄcia dzielenia przez zero:
   //** if( fx2 != 0.0 ){ - bĹÄdy: 1. (fx1+fx2)-fx1 != fx2, 2. porĂłwnanie float

   //** poprawna prĂłba unikniÄcia dzielenia przez zero lub utraty precyzji:
   //** (naleĹźy wczeĹniej odkomentowaÄ definicje staĹej nazwanej TOLERANCE na poczÄtku pliku)
    if( fabs ((fx1+fx2)-fx1) < TOLERANCE){
      printf("\nPrĂłba dzielenia przez liczbÄ bliskÄ zero! Przerwanie programu!\n");    
    return(-1); 
     //** lub exit(-1) - exit przerywa wykonanie caĹego programu, nie tylko aktualnej funkcji    
    }
    float fx3 = 1.0f / ((fx1+fx2)-fx1); // powinno byc rĂłwne 1/fx2...
    printf("\n1.0f / ((fx1+fx2)-fx1) = %20.15lf\n", fx3);
  
    float dx3 = 1.0 / ((dx1+dx2)-dx1); // powinno byc rĂłwne 1/dx2...
    printf("\n1.0/((dx1+dx2)-dx1) = %.12lf  != 1.0/dx2 = %.12lf\n", dx3, 1.0/dx2);
    printf("ZostaĹy tylko trzy cyfry znaczÄce na skutek skoĹczonej precyzji...\n");
    printf("ZostaĹy tylko trzy cyfry znaczÄce na skutek skoĹczonej precyzji...\n");

// //** !!!!!!!! ******* !!!!!!!!
// //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu jego działania)
// //**(opis działania kodu z wyjaśnieniem przyczyn problemów z precyzją powinien znaleźć się w sprawozdaniu)
// //** - zadania rozszerzające z tematu laboratorium  

// Definicje zmiennych float i double
    // float fx1 = 1.23e7f;
    // float fx2 = 1.23e-7f;
    // double dx1 = 1.23e7;
    // double dx2 = 1.23e-7;

// Wypisanie wartości zmiennych
    printf("\nProblemy z precyzją zmiennych float i double:\n");
    printf("float: fx1 = %20.15f, fx2 = %20.15f\n", fx1, fx2);
    printf("double: dx1 = %20.15lf, dx2 = %20.15lf\n", dx1, dx2);

// Sprawdzenie precyzji operacji dodawania i odejmowania
    if ((fx1 + fx2) - fx1 == fx2) {
        printf("(fx1 + fx2) - fx1 == fx2 (dla float)\n");
    } else {
        printf("(fx1 + fx2) - fx1 != fx2 (dla float) ( (fx1 + fx2) - fx1 = %.15f )\n", (fx1 + fx2) - fx1);
    }

    if ((dx1 + dx2) - dx1 == dx2) {
        printf("(dx1 + dx2) - dx1 == dx2 (dla double)\n");
    } else {
        printf("(dx1 + dx2) - dx1 != dx2 (dla double) ( (dx1 + dx2) - dx1 = %.15lf )\n", (dx1 + dx2) - dx1);
    }

// Próba uniknięcia dzielenia przez zero lub utraty precyzji
    if (fabs((fx1 + fx2) - fx1) < TOLERANCE) {
        printf("\nPróba dzielenia przez liczbę bliską zero! Przerwanie programu!\n");
        return -1;
    }

    float tx3 = 1.0f / ((fx1 + fx2) - fx1); // powinno być równe 1/fx2...
    printf("\n1.0f / ((fx1 + fx2) - fx1) = %20.15f\n", tx3);

    double zx3 = 1.0 / ((dx1 + dx2) - dx1); // powinno być równe 1/dx2...
    printf("\n1.0 / ((dx1 + dx2) - dx1) = %.15lf != 1.0 / dx2 = %.15lf\n", zx3, 1.0 / dx2);
    printf("Zostały tylko trzy cyfry znaczące na skutek skończonej precyzji...\n");
    printf("\nProgram dotarĹ do koĹca\n");
    return(0);
}