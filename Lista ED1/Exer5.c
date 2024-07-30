#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUCOES 10
#define MAX_CARACTERES 21

typedef struct Instrucao {
    char direcao[MAX_CARACTERES];
    char rua[MAX_CARACTERES];
} Instrucao;

void inverterDirecao(char* direcao) {
    if (strcmp(direcao, "DIREITA") == 0) {
        strcpy(direcao, "ESQUERDA");
    } else if (strcmp(direcao, "ESQUERDA") == 0) {
        strcpy(direcao, "DIREITA");
    }
}

int main() {
    Instrucao instrucoes[MAX_INSTRUCOES];
    int count = 0;
    int i;

    while (1) {
        Instrucao instrucao;
        fgets(instrucao.direcao, MAX_CARACTERES, stdin);
        instrucao.direcao[strcspn(instrucao.direcao, "\n")] = '\0'; // Remove newline character
        
        fgets(instrucao.rua, MAX_CARACTERES, stdin);
        instrucao.rua[strcspn(instrucao.rua, "\n")] = '\0'; // Remove newline character
        
        instrucoes[count++] = instrucao;

        if (strcmp(instrucao.rua, "ESCOLA") == 0) {
            break;
        }
    }

    for (i = count - 1; i >= 0; i--) {
        inverterDirecao(instrucoes[i].direcao);
        if (i == 0) {
            printf("Vire a %s para chegar em CASA.\n", instrucoes[i].direcao);
        } else {
            printf("Vire a %s na rua %s.\n", instrucoes[i].direcao, instrucoes[i - 1].rua);
        }
    }

    return 0;
}