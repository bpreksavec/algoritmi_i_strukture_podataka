#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Ova biblioteka je potrebna za inicijalizaciju generatora pseudoslučajnih brojeva

void gen_arr(float V[], int n, float dg, float gg) {
    int i;
    float range = gg - dg; // Raspon vrijednosti između donje i gornje granice

    // Inicijalizacija generatora pseudoslučajnih brojeva
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        // Generiranje pseudoslučajnog broja u rasponu od dg do gg
        V[i] = dg + (range * rand() / (RAND_MAX + 1.0));
    }
}

int main() {
    int i;
    int n = 10; // Broj elemenata u polju
    float dg = 10.0; // Donja granica
    float gg = 20.0; // Gornja granica
    float polje[n];

    // Generiranje polja pseudoslučajnih brojeva
    gen_arr(polje, n, dg, gg);

    // Ispis generiranog polja
    printf("Generirano polje:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\n", polje[i]);
    }

    return 0;
}
