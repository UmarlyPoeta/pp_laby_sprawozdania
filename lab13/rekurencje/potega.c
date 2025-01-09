#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 0. numeracja kolejnych krokĂłw ÄwiczeĹ odpowiada numeracji w temacie laboratorium
//    - poczÄtek modyfikacji kodu (po wstÄpnym uruchomieniu programu za pomocÄ
//      utworzonego pliku Makefile) -> p.4 w funkcji power_int_rekur

// obliczanie n-tej potegi (caĹkowitej) liczby caĹkowitej base
int power_int(int base, int n);

// obliczanie n-tej potegi (caĹkowitej) liczby caĹkowitej base w sposĂłb rekurencyjny
int power_int_rekur(int m, int n);

int my_atoi(char s[]);

int main (int argc, char** argv) 
{
    // cd. 5 - sprawdzenie poprawnoĹci wywoĹania (np. modyfikujÄc poniĹźszy kod)
    if(argc <= 2) { 
        printf("Usage: %s <base> <exponent>\n", argv[0]); 
        exit(0); 
    }
    
    // cd. 5 uzyskanie argumentĂłw liczbowych z przesĹanych napisĂłw w linii komend
    int base = my_atoi(argv[1]);
    int exp = my_atoi(argv[2]);
    
    // sprawdzajÄca asercja?
    assert(exp >= 0);
    
    // wykonanie operacji na przesĹanych argumentach
    printf("Dane z linii poleceĹ: %d^%d=%d\n", base, exp, power_int(base, exp));

    // koniec p. 5 -> p. 6 w funkcji power_int_rekur

    int i;
    for (i = 0; i < 10; ++i){
        printf("iteracyjnie:   \t%d^%d = %3d \t%d^%d = %6d\n",
         2, i, power_int(2,i), -3, i, power_int(-3,i));
        
        // 4.1.a 
        printf("rekurencyjnie: \t%d^%d = %3d \t%d^%d = %6d\n",
                     2, i, power_int_rekur(2,i), -3, i, power_int_rekur(-3,i));
    }

    int base_f=0, exp_f=0;
    // 7. wczytywanie argumentĂłw z pliku (i ewentualny zapis do pliku)
    //
    // 7.a definicja wskaĹşnika do pliku
    FILE *file;
    // 7.b otwarcie pliku (sciezka np. ./dane.txt, tryb odczytu)
    file = fopen("./dane.txt", "r");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku.\n");
        exit(1);
    }
    // 7.c wczytanie argumentĂłw z pliku
    fscanf(file, "%d %d", &base_f, &exp_f);
    // 7.d zamkniÄcie pliku
    fclose(file);
    // 7.e wykonanie operacji na argumentach
    // 7.f wydruk sprawdzajÄcy
    printf("Dane z pliku: %d^%d=%d\n", base_f, exp_f, power_int(base_f, exp_f));

    // ewentualnie:
    // 7.g otwarcie pliku (tryb dopisywania)
    file = fopen("./dane.txt", "a");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku.\n");
        exit(1);
    }
    // 7.h dopisanie wyniku do pliku
    fprintf(file, "\n%d^%d=%d", base_f, exp_f, power_int(base_f, exp_f));
    // 7.i zamkniÄcie pliku
    fclose(file);

    // koniec p.7 ------------------------- 3.0 -------------------------
    
    return 0;
}

// obliczanie n-tej potegi (caĹkowitej) liczby caĹkowitej base
int power_int(int base, int n)
{
    int i, p;
    p=1;
    for (i = 1; i <= n; ++i){
        p = p * base;
    }
    return p;
}

// obliczanie n-tej potegi (caĹkowitej) liczby caĹkowitej base w sposĂłb rekurencyjny
int power_int_rekur(int m, int n){

    // 4.2. umieszczenie wewnÄtrz funkcji makra assert sprawdzajÄcego n>=0
    assert(n >= 0);

    // 6. wprowadzenie zmiennej statycznej zliczajÄcej liczbÄ wywoĹaĹ funkcji power_int_rekur
    static int call_count = 0;
    call_count++;
    printf("nr %d funkcji power_int_rekur\n", call_count);

    // 4.1 napisanie wersji rekurencyjnej dla funkcji obliczania potÄgi
    if (n == 0) {
        return 1;
    } else {
        return m * power_int_rekur(m, n - 1);
    }

    // koniec p. 6
}

// funkcja pomocnicza przeksztaĹcajÄca napis (liczbÄ zapisanÄ literowo) w liczbÄ caĹkowitÄ
int my_atoi(char s[])
{
    int sign=1; // = (s[0]=='-') ? -1 : 1;
    if(s[0]=='-') sign=-1;
    int i=0;
    if (s[0]=='+' || s[0]=='-') i++;  
    int n = 0;
    while( s[i] >= '0' && s[i] <= '9' ) {
        n = 10 * n + (s[i] - '0');
        i++;
    }
    return sign*n;
}
