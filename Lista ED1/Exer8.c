#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[21];
    char telefone[10];
    int ligacoes;
} Contato;

Contato agenda[100];
int numContatos = 0;

void inserirContato(char *nome, char *telefone, int ligacoes) {
    strcpy(agenda[numContatos].nome, nome);
    strcpy(agenda[numContatos].telefone, telefone);
    agenda[numContatos].ligacoes = ligacoes;
    numContatos++;
}

void removerContato(char *nome) {
    int i, j;
    for (i = 0; i < numContatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            for (j = i; j < numContatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            numContatos--;
            break;
        }
    }
}

void registrarLigacao(char *nome) {
    int i;
    for (i = 0; i < numContatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            agenda[i].ligacoes++;
            break;
        }
    }
}

int compararContatos(const void *a, const void *b) {
    Contato *contatoA = (Contato *)a;
    Contato *contatoB = (Contato *)b;
    if (contatoB->ligacoes != contatoA->ligacoes) {
        return contatoB->ligacoes - contatoA->ligacoes;
    }
    return 0;
}

void listarContatos() {
    int i;
    qsort(agenda, numContatos, sizeof(Contato), compararContatos);
    for (i = 0; i < numContatos; i++) {
        printf("%s - %s %d\n", agenda[i].nome, agenda[i].telefone, agenda[i].ligacoes);
    }
}

int main() {
    char comando;
    char nome[21], telefone[10];
    int ligacoes;

    // Inserir os contatos iniciais
    inserirContato("Hermanoteu", "4523-2248", 300);
    inserirContato("Ooloneia", "4523-4887", 299);

    while (1) {
        scanf(" %c", &comando);
        if (comando == 'F') {
            break;
        }

        switch (comando) {
            case 'I':
                scanf("%s %s %d", nome, telefone, &ligacoes);
                inserirContato(nome, telefone, ligacoes);
                break;
            case 'R':
                scanf("%s", nome);
                removerContato(nome);
                break;
            case 'L':
                scanf("%s", nome);
                registrarLigacao(nome);
                break;
        }
    }

    listarContatos();
    return 0;
}
