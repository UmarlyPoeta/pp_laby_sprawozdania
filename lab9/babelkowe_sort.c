#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zamien_wyrazy(int *int_1_p, int *int_2_p) {
    int temp = *int_1_p;
    *int_1_p = *int_2_p;
    *int_2_p = temp;
}

void sortowanie_babelkowe(int* A, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (A[j] > A[j+1]) {
                zamien_wyrazy(&A[j], &A[j+1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &n);

    int *A = (int*)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Blad alokacji pamieci!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100; 
    }

    printf("Tablica przed sortowaniem:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    sortowanie_babelkowe(A, n);

    printf("Tablica po sortowaniu:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}


