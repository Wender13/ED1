#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 60000

typedef struct {
    int identificadores[MAX_PESSOAS];
    int tamanho;
} Fila;

void removerDaFila(Fila *fila, int identificador) {
    int i, j;
    for (i = 0; i < fila->tamanho; i++) {
        if (fila->identificadores[i] == identificador) {
            // Move todos os elementos após a pessoa removida uma posição para frente
            for (j = i; j < fila->tamanho - 1; j++) {
                fila->identificadores[j] = fila->identificadores[j + 1];
            }
            fila->tamanho--;
            return;
        }
    }
}

int main() {
    int n, s, i;
    Fila fila;

    // Leitura do número de pessoas inicialmente na fila
    scanf("%d", &n);
    fila.tamanho = n;

    // Leitura dos identificadores das pessoas na fila
    for (i = 0; i < n; i++) {
        scanf("%d", &fila.identificadores[i]);
    }

    // Leitura do número de pessoas que deixaram a fila
    scanf("%d", &s);

    // Leitura dos identificadores das pessoas que deixaram a fila e remoção das mesmas
    for (i = 0; i < s; i++) {
        int id;
        scanf("%d", &id);
        removerDaFila(&fila, id);
    }

    // Impressão do estado final da fila
    for (i = 0; i < fila.tamanho; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", fila.identificadores[i]);
    }
    printf("\n");

    return 0;
}