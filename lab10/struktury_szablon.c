#include <stdio.h>
#include <string.h>

// definicja typu strukturalnego (można podać obie postacie i korzystać później z jednej z nich)
// 3.a bez użycia typedef

// Definicja struktury
typedef struct  {
    char nazwa[50];
    int liczba;
    double wartosc;
} Obiekt;

// 3.b z użyciem typedef

// Definicja struktury
struct Obiekt {
    char nazwa[50];
    int liczba;
    double wartosc;
};

// 5.1.a deklaracja funkcji fun_strukt

// 5.3.a deklaracja funkcji fun_strukt_out

// 5.5.a deklaracja funkcji fun_strukt_wsk

void fun_strukt(struct Obiekt obiekt);
struct Obiekt fun_strukt_out(struct Obiekt obiekt);
void fun_strukt_wsk(struct Obiekt *obiekt);

int main (void)
{

    // 4.1 definicja zmiennej (np. obiekt_1) typu strukturalnego
    struct Obiekt obiekt_1;

    // 4.2 nadanie wartości pól zmiennej obiekt_1 z pomocą operatora .
    strcpy(obiekt_1.nazwa, "Obiekt1");
    obiekt_1.liczba = 10;
    obiekt_1.wartosc = 100.0;

    // 4.3 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
    //    np. printf("Początkowe wartości pól obiekt_1: ....", ....);
    printf("Początkowe wartości pól obiekt_1: %s, %d, %.2f\n", obiekt_1.nazwa, obiekt_1.liczba, obiekt_1.wartosc);

    // 5.2.1 wywołanie funkcji fun_strukt (po deklaracji w p. 5.1.a i definicji w p. 5.1.b)
    //      z obiektem 1 jako argumentem 
    fun_strukt(obiekt_1);

    // 5.2.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
    //    np. printf("Po wywołaniu fun_strukt - wartości pól obiekt_1: ....", ....);
    printf("Po wywołaniu fun_strukt - wartości pól obiekt_1: %s, %d, %.2f\n", obiekt_1.nazwa, obiekt_1.liczba, obiekt_1.wartosc);

    // 5.4.1 wywołanie funkcji fun_strukt_out (po deklaracji w p. 5.3.a i definicji w p. 5.3.b)
    //      z obiektem_1 jako argumentem i przepisaniem wyniku z powrotem do obiektu_1
    obiekt_1 = fun_strukt_out(obiekt_1);

    // 5.4.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
    //    np. printf("Po wywołaniu fun_strukt_out i przypisaniu wyniku do obiekt_1\n");
    //        printf("- wartości pól obiekt_1: ....", ....);
    printf("Po wywołaniu fun_strukt_out i przypisaniu wyniku do obiekt_1\n");
    printf("- wartości pól obiekt_1: %s, %d, %.2f\n", obiekt_1.nazwa, obiekt_1.liczba, obiekt_1.wartosc);

    // 4.4 definicja drugiej zmiennej typu strukturalnego  (np. obiekt_2)
    //    połączona z inicjowaniem za pomocą listy wartości
    struct Obiekt obiekt_2 = {"Obiekt2", 20, 200.0};

    // 4.5 definicja wskaźnika (np. obiekt_2_wsk) do struktury zainicjowanego adresem obiektu_2
    struct Obiekt *obiekt_2_wsk = &obiekt_2;

    // 4.6 wypisanie wartości pól obiektu_2 z pomocą wskaźnika do obiektu i operatora ->
    //    np. printf("Początkowe wartości pól obiekt_2: ....", ....);
    printf("Początkowe wartości pól obiekt_2: %s, %d, %.2f\n", obiekt_2_wsk->nazwa, obiekt_2_wsk->liczba, obiekt_2_wsk->wartosc);

    // 5.6.1 wywołanie funkcji fun_strukt_wsk (po deklaracji w p. 5.5.a i definicji w p. 5.5.b)
    //      ze zmienną obiekt_2_wsk jako argumentem
    fun_strukt_wsk(obiekt_2_wsk);

    // 5.6.2 wypisanie wartości pól zmiennej obiekt_2 z pomocą wskaźnika do obiektu i operatora ->
    //    np. printf("Po wywołaniu fun_strukt_wsk - wartości pól obiekt_2: ....", ....);
    printf("Po wywołaniu fun_strukt_wsk - wartości pól obiekt_2: %s, %d, %.2f\n", obiekt_2_wsk->nazwa, obiekt_2_wsk->liczba, obiekt_2_wsk->wartosc);

    // 4.7 definicja trzeciej zmiennej typu strukturalnego  (np. obiekt_3)
    //    połączona z inicjowaniem za pomocą przepisania zawartości obiektu_2 w jednej
    //    operacji przypisania
    struct Obiekt obiekt_3 = obiekt_2;

    // 4.8 wypisanie wartości pól zmiennej obiekt_3 z pomocą operatora .
    //    np. printf("Początkowe wartości pól obiekt_3: ....", ....);
    printf("Początkowe wartości pól obiekt_3: %s, %d, %.2f\n", obiekt_3.nazwa, obiekt_3.liczba, obiekt_3.wartosc);

  printf("Koniec programu.\n");
}

// 5.1.b definicja funkcji fun_strukt

//{

  // wypisanie wartości pól struktury przesłanej jako argument
  // np. printf("Wewnątrz fun_strukt - wartości pól obiektu argumentu: ...", ...);

  // modyfikacja wartości pól struktury

  // wypisanie zmodyfikowanych wartości pól struktury 
  // np. printf("Wewnątrz fun_strukt - zmodyfikowane wartości pól obiektu argumentu: ...", ...);

//}
void fun_strukt(struct Obiekt obiekt) {
    printf("Wewnątrz fun_strukt - wartości pól obiektu argumentu: %s, %d, %.2f\n", obiekt.nazwa, obiekt.liczba, obiekt.wartosc);
    obiekt.liczba += 10;
    obiekt.wartosc *= 2;
    printf("Wewnątrz fun_strukt - zmodyfikowane wartości pól obiektu argumentu: %s, %d, %.2f\n", obiekt.nazwa, obiekt.liczba, obiekt.wartosc);
}

// 5.3.b definicja funkcji fun_strukt_out

//{

  // wypisanie wartości pól struktury przesłanej jako argument

  // modyfikacja wartości pól struktury

  // wypisanie zmodyfikowanych wartości pól struktury 

  // zwrócenie struktury ze zmodyfikowanymi wartościami pól do funkcji wywołującej

//}
struct Obiekt fun_strukt_out(struct Obiekt obiekt) {
    printf("Wewnątrz fun_strukt_out - wartości pól obiektu argumentu: %s, %d, %.2f\n", obiekt.nazwa, obiekt.liczba, obiekt.wartosc);
    obiekt.liczba += 20;
    obiekt.wartosc *= 3;
    printf("Wewnątrz fun_strukt_out - zmodyfikowane wartości pól obiektu argumentu: %s, %d, %.2f\n", obiekt.nazwa, obiekt.liczba, obiekt.wartosc);
    return obiekt;
}

// 5.5.b definicja funkcji fun_strukt_wsk

//{

  // wypisanie wartości pól struktury wskaźnik do której został przesłany jako argument

  // modyfikacja wartości pól struktury

  // wypisanie zmodyfikowanych wartości pól struktury 

//}

void fun_strukt_wsk(struct Obiekt *obiekt) {
    printf("Wewnątrz fun_strukt_wsk - wartości pól obiektu argumentu: %s, %d, %.2f\n", obiekt->nazwa, obiekt->liczba, obiekt->wartosc);
    obiekt->liczba += 30;
    obiekt->wartosc *= 4;
    printf("Wewnątrz fun_strukt_wsk - zmodyfikowane wartości pól obiektu argumentu: %s, %d, %.2f\n", obiekt->nazwa, obiekt->liczba, obiekt->wartosc);
}






