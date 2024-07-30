#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da pilha
typedef struct No {
    char dado;
    struct No* proximo;
} No;

// Definição da estrutura da pilha
typedef struct Pilha {
    No* topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha* pilha) {
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

// Função para empilhar um valor na pilha
void empilhar(Pilha* pilha, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(1);
    }
    novoNo->dado = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

// Função para desempilhar um valor da pilha
char desempilhar(Pilha* pilha) {
    if (estaVazia(pilha)) {
        exit(1);
    }
    No* temp = pilha->topo;
    char valorDesempilhado = temp->dado;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return valorDesempilhado;
}

// Função para liberar a memória alocada pela pilha
void liberarPilha(Pilha* pilha) {
    while (!estaVazia(pilha)) {
        desempilhar(pilha);
    }
}

// Função para verificar se os parênteses estão balanceados
int estaBalanceado(char* expressao) {
    Pilha pilha;
    inicializar(&pilha);

    int i;  // Declaração da variável fora do loop for
    for (i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(') {
            empilhar(&pilha, expressao[i]);
        } else if (expressao[i] == ')') {
            if (estaVazia(&pilha)) {
                liberarPilha(&pilha);
                return 0; // Parêntese de fechamento sem correspondente de abertura
            }
            desempilhar(&pilha);
        }
    }

    liberarPilha(&pilha);
    return 1; // Considera "correta" se não houver parênteses de fechamento sem correspondente
}

int main() {
    char expressao[1001];
    fgets(expressao, 1001, stdin);

    if (estaBalanceado(expressao)) {
        printf("correta\n");
    } else {
        printf("incorreta\n");
    }

    return 0;
}