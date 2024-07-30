#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define CHAVE_INVALIDA 0
#define FALHA -1

#define TAMANHO_MAXIMO_FILA 100

typedef struct
{
    unsigned int chave;
    unsigned int dado;
} Elemento;

typedef struct
{
    Elemento elementos [TAMANHO_MAXIMO_FILA];
    unsigned int tamanho;
} Fila;

int criarFilaVazia (Fila * fila);
int criarFilaChave (Fila * fila, Elemento elemento);
int tamanhoFila (Fila fila);
void mostrarElemento(Elemento elemento);
void mostrarFila (Fila fila);
Elemento consultaPosicao(Fila fila, unsigned int intPosicao);
int insFinal (Fila * fila, Elemento elemento);
Elemento remInicio (Fila * fila);

int criarFilaVazia(Fila * fila ) 
{
    int i;
    fila->tamanho = 0;
    for (i = 0; (i < TAMANHO_MAXIMO_FILA); i++) 
    {
        fila->elementos[i].chave = CHAVE_INVALIDA;
    }
    return (SUCESSO);
}

int criarFilaChave(Fila * fila, Elemento elemento) 
{
    fila->elementos[0] = elemento;
    fila->tamanho = 1;
    return (SUCESSO);
}

int tamanhoFila(Fila fila ) 
{
    if (fila.tamanho >= 0) {return(fila .tamanho);}
    else {return(FALHA);}
}

void mostrarElemento(Elemento elemento) 
{
    printf("Chave......: %u\n", elemento.chave);
    printf("Dado.......: %u\n", elemento.dado);
}

void mostrarFila(Fila fila)
{
    unsigned int i;
    if (fila.tamanho == 0) {printf("Atencao: A fila esta vazia.\n");}
    else 
    {
        printf("A fila linear possui %u elementos.\n\n", fila.tamanho); 
        for (i = 0; (i < fila.tamanho); i++) 
        {
            printf("Elemento n.: %u\n", (i+1));
            mostrarElemento(fila.elementos[i]);
        }
    }
}

Elemento consultaPosicao(Fila fila , unsigned int intPosicao) 
{
    Elemento elementoResultado;

    if ((intPosicao > 0) && (intPosicao <= fila .tamanho)) 
    {
        elementoResultado = fila.elementos[intPosicao - 1];
    }
    else 
    {
    elementoResultado.chave = CHAVE_INVALIDA;
    }
    return(elementoResultado);
}

int insFinal (Fila * fila , Elemento elemento) {
    unsigned int i; 
    Elemento auxiliar;

    if (fila->tamanho == TAMANHO_MAXIMO_FILA) {return (FALHA);}
    else
    {
        fila->elementos[fila->tamanho] = elemento;
        fila->tamanho++;
        return (SUCESSO);
    }
}

Elemento remInicio(Fila * fila)
{
    unsigned int i;
    Elemento elementoResultado;

    if (fila->tamanho == 0)
    {
        elementoResultado.chave = CHAVE_INVALIDA;
        return(elementoResultado);
    }
    else
    {
        elementoResultado = fila->elementos[0];
        for (i = 0; (i < (fila->tamanho - 1)); i++) {fila->elementos[i] = fila->elementos[i+1];}
        fila->tamanho--;
        return (elementoResultado);
    }
}



//Continuar na página 34