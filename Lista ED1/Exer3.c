#include <stdio.h>
#include <stdlib.h>

#define MAX_ANOES 1000
#define MAX_CORES 1000
#define MAX_FOTOS 1000

typedef struct {
    int bonita;
    int cor;
} ResultadoFoto;

void analisarFoto(int fila[], int n, int i, int j, int c, ResultadoFoto *resultado) {
    int frequencia[MAX_CORES + 1] = {0}; // Frequência de cada cor na foto
    int k;
    int maxFrequencia = 0;
    int corPredominante = 0;
    int totalAnoes = j - i + 1;

    // Contar a frequência de cada cor na foto
    for (k = i - 1; k < j; k++) {
        frequencia[fila[k]]++;
    }

    // Verificar qual a cor com maior frequência
    for (k = 1; k <= c; k++) {
        if (frequencia[k] > maxFrequencia) {
            maxFrequencia = frequencia[k];
            corPredominante = k;
        }
    }

    // Verificar se a foto é bonita
    if (maxFrequencia > totalAnoes / 2) {
        resultado->bonita = 1;
        resultado->cor = corPredominante;
    } else {
        resultado->bonita = 0;
    }
}

int main() {
    int n, c, m;
    int fila[MAX_ANOES];
    int i, j;
    int k;

    ResultadoFoto resultados[MAX_FOTOS];

    // Leitura do número de anões e cores
    scanf("%d %d", &n, &c);

    // Leitura da fila de anões com as cores das toucas
    for (k = 0; k < n; k++) {
        scanf("%d", &fila[k]);
    }

    // Leitura do número de fotos
    scanf("%d", &m);

    // Análise de cada foto
    for (k = 0; k < m; k++) {
        scanf("%d %d", &i, &j);
        analisarFoto(fila, n, i, j, c, &resultados[k]);
    }

    // Impressão dos resultados após toda a análise
    for (k = 0; k < m; k++) {
        if (resultados[k].bonita) {
            printf("bonita %d\n", resultados[k].cor);
        } else {
            printf("feia\n");
        }
    }

    return 0;
}