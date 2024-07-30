#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0

#define TAMANHO_MAXIMO_PILHA 100

typedef struct 
{
    unsigned int dado;
    unsigned int chave;
} Elemento;

typedef struct
{
    Elemento elementos [TAMANHO_MAXIMO_PILHA];
    unsigned int tamanho;
} Pilha;

int criarPilhaVazia(Pilha * pilha);
int tamanhoPilha(Pilha pilha);
void mostrarElemento(Elemento elemento);
void mostrarPilha(Pilha pilha);
int push(Pilha * pilha, Elemento elemento);
Elemento pop(Pilha * pilha);

int criarPilhaVazia(Pilha * pilha) 
{
    int i;
    pilha->tamanho = 0;
    for (i = 0; (i < TAMANHO_MAXIMO_PILHA); i++) {pilha->elementos[i].chave = CHAVE_INVALIDA;}
    return (SUCESSO);
}

int tamanhoPilha(Pilha pilha) 
{
    if (pilha.tamanho >= 0) {return (pilha.tamanho);}
    else {return(FALHA);}
}

void mostrarElemento(Elemento elemento) 
{
    printf("Chave......: %u\n", elemento.chave);
    printf("Dado.......: %u\n", elemento.dado);
}

void mostrarPilha(Pilha pilha) 
{
    unsigned int i;
    if (pilha.tamanho == 0) {printf("Atencao: A pilha esta vazia.\n");}
    else
    {
        printf("A pilha possui %u elementos.\n\n", pilha.tamanho);
        for (i = 0; (i < pilha.tamanho); i++) {
            printf("Elemento n.: %u\n", (i+1));
            mostrarElemento(pilha.elementos[i]);
        }        
    }
}

int push (Pilha * pilha , Elemento elemento) 
{
    unsigned int i; 
    Elemento auxiliar;

    if (pilha->tamanho == TAMANHO_MAXIMO_PILHA) {return (FALHA);}
    else
    {
        pilha->elementos[pilha->tamanho] = elemento;
        pilha->tamanho++;
        return(SUCESSO);
    }
}

Elemento pop (Pilha * pilha) 
{
    unsigned int i;
    Elemento elementoResultado;

    if (pilha->tamanho == 0) 
    {
        elementoResultado.chave = CHAVE_INVALIDA; 
        return(elementoResultado);
    }
    else
    {
        elementoResultado = pilha->elementos[((pilha->tamanho) - 1)];
        pilha->tamanho--;
        return(elementoResultado);
    }
}