#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA 0 
#define CHAVE_INVALIDA 0 

typedef struct Celula * ApontadorCelula;

int CriarListaVazia (ApontadorCelula* p);
int CriarListaChave (ApontadorCelula* p, Celula celula);
void MostraLista (ApontadorCelula p);
void MostraListaReversa (ApontadorCelula p);
int InsInicio (ApontadorCelula * p, Celula celula);
int InsFinal (ApontadorCelula * p, Celula celula);
int InsOrdem (ApontadorCelula * p, Celula celula);
int RemInicio (ApontadorCelula * p);
int RemFinal (ApontadorCelula * p);
int RemChave (ApontadorCelula * p, Celula celula);
int concatListas (ApontadorCelula p, ApontadorCelula q, ApontadorCelula * lista);

typedef struct Celula 
{
    unsigned int chave;
    unsigned int dado;
    ApontadorCelula ant;
    ApontadorCelula prox;
} Celula;

ApontadorCelula prim;

int CriarListaVazia (ApontadorCelula * p)
{
    (*p) = (ApontadorCelula) NULL;
    return (SUCESSO);
}

int CriarListaChave (ApontadorCelula * p, Celula celula)
{
    (*p) = (ApontadorCelula) malloc (sizeof(ApontadorCelula *));
    if ((* p) == NULL)
    {
        return FALHA;
    }
    else
    {
        return (InsInicio(p, celula));
    }
}

int InsInicio(ApontadorCelula * p, Celula celula)
{
    ApontadorCelula q;

    q = (ApontadorCelula) malloc (sizeof(ApontadorCelula *));
    if (q == NULL)
    {
        return (FALHA);
    }
    else
    {
        q->chave = celula.chave;
        q->dado = celula.dado;
        q->ant = (ApontadorCelula) NULL;
        q->prox = (* p);
        (* p) = q;
        return (SUCESSO);
    }
}

int InsFinal (ApontadorCelula * p, Celula celula)
{
    ApontadorCelula q,r;

    if ((* p) == NULL) 
    {
        return (InsInicio(p, celula));
    }
    else
    {
       q = (ApontadorCelula) malloc(sizeof(ApontadorCelula *));
       if (q == NULL)
       {
        return (FALHA);
       }
        else
        {
            q->chave = celula.chave;
            q->dado = celula.dado;
            r = (*p);
            while (r->prox != NULL)
            {
                r = r->prox;
            }
            q->ant = r;
            q->prox = r->prox;
            r->prox = q;
            return (SUCESSO);            
        }
    }
    
}

int InsOrdem (ApontadorCelula * p, Celula celula)
{
    ApontadorCelula q, r;

    if ((*p) == NULL)
    {
        return (InsInicio(p, celula));
    }
    else
    {
        if (celula.chave < ((*p)->chave))
        {
            return (InsInicio(p, celula));
        }
        else
        {
            q = (ApontadorCelula)malloc(sizeof(ApontadorCelula *));
            if (q == NULL)
            {
                return (FALHA);
            }
            else
            {
                q->chave = celula.chave;
                q->dado = celula.dado;
                r = (*p);
                while ((r->chave <= q->chave) && (r->prox != NULL))
                {
                    r = r->prox;
                }
                if (r->prox == NULL)
                {
                    if (q->chave < r->chave)
                    {
                        q->ant = r->ant;
                        q->prox = r;
                        (*(r->ant)).prox = q;
                        r->ant = q;
                    }
                    else
                    {
                        q->ant = r;
                        q->prox = r->prox;
                        r->prox = q;
                    }
                }
                else
                {
                    q->ant = r->ant;
                    q->prox = r;
                    (*(r->ant)).prox = q;
                    r->ant = q;
                }
                return (SUCESSO);
            }
        }
    }
    
}

int RemChave (ApontadorCelula* p, Celula celula) 
{
    int intResultado; 
    ApontadorCelula r, n;
    if ((*p) == NULL) { return (FALHA); } 
    else 
    {
        r = (*p);
        if (r->prox == NULL) 
        {
            if (r->chave == celula.chave) { return(RemInicio(p)); }
            else { return(FALHA); }
        }
        else 
        {
            /* Bloco da remocao de chave */

            while (r != NULL)
            {
                if (r->chave == celula.chave)
                {
                    if (r->ant == NULL) 
                    {
                        intResultado = RemInicio(p);
                        if (intResultado == FALHA) { return(FALHA); } 
                        else { r = (*p); }
                    }
                    else
                    {
                        n = r->prox;
                        (*(r->ant)).prox = n;
                        if (n != NULL)
                        {
                            n->ant = r->ant;
                        }
                        free(r); n = r;
                    }
                }
                else
                {
                    r = r->prox;
                }
            }
        }
        return(SUCESSO);
    }
}

int TamLista(ApontadorCelula p) 
{
    int intTam; 
    ApontadorCelula r;
    if (p == NULL) {return(0);}
    else 
    {
        intTam = 1;
        r = p;
        while (r->prox != NULL) 
        {
            intTam++;
            r = r->prox;
        }
    }
    return(intTam);
}

//Continuar na página 159