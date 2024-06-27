#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 1
#define TAMANHO_MAXIMO_LISTA 100

typedef struct 
{
    unsigned int chave;
    unsigned int dado;
} Celula;

typedef struct 
{
    Celula celulas [TAMANHO_MAXIMO_LISTA];
    unsigned int tamanho;
} ListaLinear;

int criarListaVazia(ListaLinear * lista)
{
    int i;
    for (i = 0; (i < TAMANHO_MAXIMO_LISTA); i++)
    {
        lista->celulas[i].chave = CHAVE_INVALIDA;
    }
    lista->tamanho = 0;
    return (SUCESSO);
}

int criarListaChave(ListaLinear * lista, Celula celula)
{
    int i;
    for (i = 0; (i < TAMANHO_MAXIMO_LISTA); i++)
    {
        lista->celulas[i].chave = CHAVE_INVALIDA;
    }
    lista->celulas[0] = celula;
    lista->tamanho = 1;
    return (SUCESSO);
}

int tamanhoLista(ListaLinear lista)
{
    if (lista.tamanho >= 0)
    {
        return (lista.tamanho);
    }
    else
    {
        return (FALHA);
    }
}

void mostrarCelula(Celula celula)
{
    printf("Chave.....: %u", celula.chave);
    printf("Dado......: %u", celula.dado);
}

void mostrarLista(ListaLinear lista)
{
    int i;

    if(lista.tamanho == 0)
    {
        printf("A lista está vazia!\n");
    }
    else
    {
        printf("A lista possui %u elementos.\n\n", lista.tamanho);
        for (i = 0; (i < lista.tamanho); i++)
        {
            printf("Elemento nº: %u\n", (i+1));
            mostrarCelula(lista.celulas[i]);
        }
        
    }
}

Celula consultarListaPosicao(ListaLinear lista, unsigned int intPosicao)
{
    Celula celulaResultado;

    if ((intPosicao > 0) && (intPosicao <= lista.tamanho))
    {
        celulaResultado = lista.celulas[intPosicao - 1];
    }
    else
    {
        celulaResultado.chave = CHAVE_INVALIDA;
    }
    return (celulaResultado);
}

Celula consultarListaPosicao(ListaLinear lista, Celula celula)
{
    unsigned int i;

    for (i = 0; (i < lista.tamanho); i++)
    {
        if (lista.celulas[i].chave == celula.chave)
        {
            return (lista.celulas[i]);
        }
    }
    celula.chave = CHAVE_INVALIDA;
    return (celula);
}

int insInicio(ListaLinear * lista, Celula celula)
{
    unsigned int i;

    if(lista->tamanho == TAMANHO_MAXIMO_LISTA)
    {
        return (FALHA); //Lista cheia
    }
    else
    {
        for (i = lista->tamanho; (i > 0); i--)
        {
            lista->celulas[i] = lista->celulas[i-1];
        }
        lista->celulas[0] = celula; //Inserção da célula
        lista->tamanho++;
        return (SUCESSO);
    }
}

int insFinal(ListaLinear * lista, Celula celula)
{
    unsigned int i;
    Celula auxiliar;

    if(lista->tamanho == TAMANHO_MAXIMO_LISTA)
    {
        return (FALHA); //Lista cheia
    }
    else
    {
        lista->celulas[lista->tamanho] = celula; //Inserção da célula
        lista->tamanho++;
        return (SUCESSO);
    }
}

//Continuar a partir da paǵina 49

int main(int argc, char const *argv[])
{
    
    return 0;
}