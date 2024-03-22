#include <stdio.h>

int sekv_pret(float V[], int n, float x) {
    int i;

    for (i = 0; i < n; i++) {
        if (V[i] == x) {
            return i; // Pronađeno, vraćamo indeks
        }
    }
    return -1; // Nije pronađeno
}
