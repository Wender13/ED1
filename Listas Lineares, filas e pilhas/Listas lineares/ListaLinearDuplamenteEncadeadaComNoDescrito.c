#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0

typedef struct Celula* ApontadorCelula;
typedef struct Descritor* ApontadorDescritor;

struct Descritor
{
    ApontadorCelula prim;
    int tam;
    ApontadorCelula ult;
} Descritor;

struct Celula
{
    ApontadorCelula ant;
    int chave;
    int dado;
    ApontadorCelula prox;
} Celula;

int criarListaVazia(ApontadorDescritor * d)
{
    (*d) = (ApontadorDescritor) malloc(sizeof(struct Descritor)); 
    if ((*d) == NULL) {return (FALHA);}
    else 
    {
        (*d)->prim = (ApontadorCelula) NULL;
        (*d)->tam = 0;
        (*d)->ult = (ApontadorCelula) NULL;
        return (SUCESSO);
    }
}

int CriarListaChave (ApontadorDescritor* d, struct Celula celula) 
{
    int intResultado;
    intResultado = CriarListaVazia(d); 
    if (intResultado == FALHA) {return (FALHA);}
    else 
    {
        return (InsInicio(d, celula));
    }
}

int InsInicio (ApontadorDescritor* d, struct Celula celula) 
{
    ApontadorCelula q;

    q = (ApontadorCelula) malloc( sizeof(struct Celula) ); 
    if (q == NULL) {return(FALHA);}
    else
    {
        q->chave = celula.chave;
        q->dado = celula.dado;
        q->ant = (ApontadorCelula) NULL;
        q->prox = (*d)->prim;

        if((*d)->tam == 0) 
        {
            (*d)->prim = q;
            (*d)->ult = q;
        }
        else
        {
            ((*d)->prim)->ant = q;
            (*d)->prim= q;
        }
        (*d)->tam++;
        return (SUCESSO);
    }
}

int InsFinal (ApontadorDescritor* d, struct Celula celula) 
{
    ApontadorCelula q;

    if ((*d)->tam == 0) {return (InsInicio (d, celula));}
    else 
    {
        q = (ApontadorCelula) malloc(sizeof(struct Celula)); 
        if (q == NULL) {return (FALHA);}
        else
        {
            q->chave = celula.chave;
            q->dado = celula.dado;
            q->prox = (ApontadorCelula) NULL;
            q->ant = (*d)->ult;

            ((*d)->ult)->prox = q;
            (*d)->ult = q;
            (*d)->tam++;
            return (SUCESSO);
        }
    }
}

int InsOrdem(ApontadorDescritor* d, struct Celula celula)
{
    ApontadorCelula q, r;

    if ((*d)->tam == 0){return (InsInicio(d, celula));}
    else
    {
        if (celula.chave < ((*d)->prim)->chave) {return (InsInicio(d, celula));}
        else
        {
            if ( celula.chave >= ((*d)->ult)->chave) {return (InsFinal(d, celula));}
            else
            {
                q = (ApontadorCelula) malloc( sizeof(struct Celula)); q->chave = celula.chave;
                q->dado = celula.dado; r = (*d)->prim;
                while (r->chave < celula.chave) 
                {
                    r = r->prox;
                }
                q->prox = r;
                q->ant = r->ant;
                r->ant = q;
                (q->ant)->prox = q;
                (*d)->tam++;
            }
        }
    }
}

int RemChave(ApontadorDescritor* d, int chave) 
{
    ApontadorCelula r;

    if ((*d)->tam == 0){return (FALHA);}
  
    else 
    {
        if ((*d)->tam == 1) 
        {
            if ( ((*d)->prim)->chave == chave ) { return(RemInicio(d));}
            else {return(FALHA);}
        }
        else 
        {
            if ( ((*d)->prim)->chave == chave){return (Reminicio(d));}
            else
            {
                r = (*d)->prim;
                while ((r->chave != chave) && (r->prox != NULL))
                {
                    r = r->prox;
                }
                if (r->prox == NULL)
                {
                    return (FALHA);
                }
                else
                {
                    (r->ant)->prox = r->prox;
                    (r->prox)->ant = r->ant;
                    free(r);
                    (*d)->tam--;
                    return (SUCESSO);
                }
            }
        }
    }
}

int TamLista(ApontadorDescritor *d){return ((*d)->tam);}

ApontadorDescritor ConcatListas(ApontadorDescritor d1, ApontadorDescritor d2)
{
    int intStatusOperacao;
    ApontadorCelula r;
    ApontadorCelula d3;

    intStatusOperacao = criarListaVazia(&d3);
    if (intStatusOperacao == FALHA) { return (FALHA);}
    else
    {
        if (d1->tam != 0)
        {
            r = d1->prim;
            while (r != NULL)
            {
                InsFinal(&d3, (*r));
                r = r->prox;
            }
        }
        if (d2->tam != 0)
        {
            r = d2->prim;
            while (r != NULL)
            {
                InsFinal(&d3, (*r));
                r = r->prox;
            }  
        } 
    }
    return (d3);
}