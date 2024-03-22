#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcija za generiranje polja pseudoslučajnih brojeva
void gen_arr(float V[], int n, float dg, float gg) {
    int i;
    float range = gg - dg;

    // Inicijalizacija generatora pseudoslučajnih brojeva
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        // Generiranje pseudoslučajnog broja u rasponu od dg do gg
        V[i] = dg + (range * rand() / (RAND_MAX + 1.0));
    }
}

// Funkcija za sekvencijalno pretraživanje u polju
int sekv_pret(float V[], int n, float x) {
    int i;

    for (i = 0; i < n; i++) {
        if (V[i] == x) {
            return i; // Pronađeno, vraćamo indeks
        }
    }
    return -1; // Nije pronađeno
}

// Funkcija za sortiranje niza uzlazno
void sort(float V[], int n) {
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (V[j] > V[j + 1]) {
                // Zamjena elemenata
                temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }
}

// Funkcija za binarno pretraživanje u sortiranom polju
int bin_pret(float V[], int n, float x) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (V[mid] == x) {
            return mid; // Pronađeno, vraćamo indeks
        } else if (V[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Nije pronađeno
}

int main() {
    int n;
    printf("Unesite broj elemenata polja: ");
    scanf("%d", &n);

    float *polje = (float *)malloc(n * sizeof(float));

    if (polje == NULL) {
        printf("Greška pri alociranju memorije.\n");
        return 1;
    }

    float dg = 1.0; // Donja granica
    float gg = 100.0; // Gornja granica
    float trazeni_broj;

    // Generiranje polja pseudoslučajnih brojeva
    gen_arr(polje, n, dg, gg);

    // Ispis generiranog polja
    printf("Generirano polje:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", polje[i]);
    }
    printf("\n");

    // Traženi broj
    printf("Unesite broj kojeg tražite u polju: ");
    scanf("%f", &trazeni_broj);

    // Sekvencijalno pretraživanje
    int rezultat_sekv = sekv_pret(polje, n, trazeni_broj);
    if (rezultat_sekv != -1) {
        printf("Broj %.2f se nalazi na poziciji %d u polju (sekvencijalno pretraživanje).\n", trazeni_broj, rezultat_sekv);
    } else {
        printf("Broj %.2f nije pronađen u polju (sekvencijalno pretraživanje).\n", trazeni_broj);
    }

    // Sortiranje polja
    sort(polje, n);

    // Binarno pretraživanje
    int rezultat_bin = bin_pret(polje, n, trazeni_broj);
    if (rezultat_bin != -1) {
        printf("Broj %.2f se nalazi na poziciji %d u polju (binarno pretraživanje).\n", trazeni_broj, rezultat_bin);
    } else {
        printf("Broj %.2f nije pronađen u polju (binarno pretraživanje).\n", trazeni_broj);
    }

    // Oslobađanje memorije
    free(polje);

    return 0;
}
