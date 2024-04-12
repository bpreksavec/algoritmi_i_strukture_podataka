#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struktura za čvor povezanog popisa
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Funkcija za stvaranje novog čvora
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Greška prilikom alociranja memorije.");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Funkcija za dodavanje čvora na kraj povezanog popisa
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Funkcija za ispis povezanog popisa
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Funkcija za sekvencijalno pretraživanje niza
int sequentialSearchArray(int* array, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

// Funkcija za sekvencijalno pretraživanje povezanog popisa
int sequentialSearchList(Node* head, int key) {
    int index = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

int main() {
    int N;
    printf("Unesite broj elemenata niza: ");
    scanf("%d", &N);

    // Generiranje slučajnog niza
    int* array = (int*)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Greška prilikom alociranja memorije.");
        return 1;
    }
    srand(time(0)); // Inicijalizacija generatora slučajnih brojeva
    printf("Generirani niz: ");
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 100; // Generiranje slučajnog broja od 0 do 99
        printf("%d ", array[i]);
    }
    printf("\n");

    // Kreiranje povezanog popisa iz niza
    Node* head = NULL;
    for (int i = 0; i < N; i++) {
        append(&head, array[i]);
    }

    int key;
    printf("\nUnesite ključ koji želite pronaći: ");
    scanf("%d", &key);

    // Mjerimo vrijeme za pretraživanje niza
    clock_t startArraySearch = clock();
    int indexArray = sequentialSearchArray(array, N, key);
    clock_t endArraySearch = clock();
    double timeArraySearch = (double)(endArraySearch - startArraySearch) / CLOCKS_PER_SEC;

    // Mjerimo vrijeme za pretraživanje povezanog popisa
    clock_t startListSearch = clock();
    int indexList = sequentialSearchList(head, key);
    clock_t endListSearch = clock();
    double timeListSearch = (double)(endListSearch - startListSearch) / CLOCKS_PER_SEC;

    if (indexArray != -1) {
        printf("Ključ %d pronađen na indeksu %d u nizu.\n", key, indexArray);
    } else {
        printf("Ključ %d nije pronađen u nizu.\n", key);
    }

    if (indexList != -1) {
        printf("Ključ %d pronađen na indeksu %d u povezanom popisu.\n", key, indexList);
    } else {
        printf("Ključ %d nije pronađen u povezanom popisu.\n", key);
    }

    printf("Vrijeme potrebno za pretraživanje niza: %.6f sekundi\n", timeArraySearch);
    printf("Vrijeme potrebno za pretraživanje povezanog popisa: %.6f sekundi\n", timeListSearch);

    // Oslobađanje memorije
    free(array);
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}