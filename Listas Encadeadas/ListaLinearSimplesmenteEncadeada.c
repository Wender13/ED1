#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0

typedef struct Celula * ApontadorCelula;

typedef struct 
{
    int chave;
    int dado;
    ApontadorCelula prox;
} Celula;

int CriarListaVazia(ApontadorCelula * p)
{
    (*p) = (ApontadorCelula *) NULL;
    return (SUCESSO);
}

/* ou
ApontadorCelula inicioLista;

int CriarListaVazia() {
    inicioLista = NULL;
    return (SUCESSO);
}
*/

// Continuar na página 95 do arquivo 05-Listas-Lineares.pdf

int main(int argc, char const *argv[])
{
    return 0;
}