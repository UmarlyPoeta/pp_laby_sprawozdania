#include <stdio.h>

int main(void)
{
    char c;
    for(;;) {  
        printf("\nWprowadź cyfrę od 0 do 5 lub 6 aby zakonczyc program: \n");  
        scanf(" %c", &c); 
        
        if (c == '0') {
            printf("Wprowadzono: 0\n");
        } else if (c == '1') {
            printf("Wprowadzono: 1\n");
            printf("Wprowadzono: 1 lub 2\n");
        } else if (c == '2') {
            printf("Wprowadzono: 1 lub 2\n");
        } else if (c == '3') {
            printf("Wprowadzono: 3\n");
        } else if (c == '4' || c == '5') {
            printf("Wprowadzono: 4 lub 5\n");
        } else if (c == '6') {
            printf("pomyslnie zakonczono program");
            return 0;
        } else {
            printf("Wprowadzono: znak spoza zakresu 0-5\n");
        }
    }
}