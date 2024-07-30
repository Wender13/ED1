#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1 // constantes−base para
#define FALHA 0 // para controle de codigo−fonte
#define CHAVE_INVALIDA 0 //

typedef struct Celula * ApontadorCelula;

typedef struct Celula 
{
    unsigned int chave;
    unsigned int dado;
    ApontadorCelula prox;
} Celula;

ApontadorCelula inicioLista;

int CriarListaVazia() 
{
    inicioLista = NULL;
    return (SUCESSO);
}


int InsInicio (Celula celula) 
{
    ApontadorCelula q,r;
    q = (ApontadorCelula) malloc( sizeof (Celula) );

    if (q == NULL) 
    {
        return (FALHA);
    }
    else 
    {
        q->chave = celula.chave;
        q->dado = celula.dado;

        if (inicioLista == NULL) {
            q->prox = NULL;
        }
        else{
            q->prox = inicioLista;
        }
        inicioLista = q;
        return (SUCESSO);
    }
}


int CriarListaChave(Celula celula) 
{
    int statusOperacao;
    inicioLista = NULL;
    statusOperacao = InsInicio(celula);
    return (statusOperacao);
}

int InsFinal (Celula celula) 
{
    ApontadorCelula q, r;

    if (inicioLista == NULL)
        return (InsInicio (celula));
    else
        q = (ApontadorCelula) malloc( sizeof (Celula) );
        if (q == NULL) 
        {
            return (FALHA);
        }
        else
        {
            q->chave = celula.chave;
            q->dado = celula.dado;
            q->prox = NULL;
            r = inicioLista;
            while (r->prox != NULL) 
            {
                r = r->prox;
            }
            r->prox = q;
            return (SUCESSO);
        }
}

int InsOrdem (Celula celula) 
{
    ApontadorCelula q, r, s;

    if (inicioLista == NULL)
    {
        return (InsInicio (celula));
    }
        
    else
    {
        if (inicioLista->prox == NULL) 
        {
            if (celula.chave < inicioLista -> chave) 
            {
                return (InsInicio (celula));
            }
            else
            {
                return (InsFinal (celula));
            }
        }
        else
        {
            if (celula.chave < inicioLista->chave)
                {
                    return (InsInicio (celula));
                }
            else
            {
                q = (ApontadorCelula) malloc( sizeof (Celula) );
                if (q == NULL) 
                {
                    return (FALHA);
                }
                q->chave = celula.chave;
                q->dado = celula.dado;
                r = inicioLista;
                while (((r->chave) < celula.chave) && ((r->prox) != NULL)) 
                {
                    s = r;
                    r = r->prox;
                }
                if (r->chave <= celula.chave) 
                {
                    q->prox = (ApontadorCelula) NULL;
                    r->prox = q;
                }
                else
                {
                    q->prox = r;
                    s->prox = q;
                }
            }
        }
    }
}
int RemInicio () 
{
    ApontadorCelula r;

    if ((inicioLista) == NULL) 
    {
        return (FALHA);
    }
    else
    {
         inicioLista = r->prox;

         r = inicioLista;
         free(r);
         return(SUCESSO);
    }
}

void MostrarLista () 
{
    ApontadorCelula r;
    r = inicioLista;

    while (r != NULL) 
    {
        printf("celula %d %d %p\n", r->chave, r->dado, r->prox);
        r = r->prox;
    }
}


Celula ReceberCelula () 
{
    Celula celula;

    printf("entre com a chave da celula ou com o valor 0 para encerrar entrada das celulas ");
    scanf("%d",&celula.chave);

    if (celula.chave != 0) 
    {
        printf("entre com o dado da celula ");
        scanf("%d",&celula.dado);
        celula.prox = NULL;
        printf("\n");
    }
    return(celula);
}

int main() 
{
    int retorno = 0;
    Celula celula;

    retorno = CriarListaVazia();
    celula = ReceberCelula();

    if (celula.chave == 0) 
    {
        printf("\nLista nao criada\n");
        return(0);
    }

    while (celula.chave != 0) 
    {
        retorno = InsInicio(celula);
        celula = ReceberCelula();
    }

// retorno = RemInicio(inicioLista);


    printf("\nLista criada\n\n");
    MostrarLista();
    return(0);
}