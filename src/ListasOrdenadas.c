#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0
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
    printf("\nChave.....: %u", celula.chave);
    printf("\nDado......: %u", celula.dado);
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

Celula consultarListaChave(ListaLinear lista, Celula celula)
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

int insOrdem(ListaLinear * lista, Celula celula)
{
    unsigned int i,j;

    if(lista->tamanho == TAMANHO_MAXIMO_LISTA)
    {
        return (FALHA);
    }
    else
    {
        if (lista->tamanho == 0)
        {
            return (insInicio(lista,celula));
        }
        else {
            if (celula.chave < lista->celulas[0].chave)
            {
                return (insInicio(lista, celula));
            }
            else
            {
                if (celula.chave >= lista->celulas[lista->tamanho - 1].chave)
                {
                    return(insFinal(lista, celula));
                }
                else
                {
                    i = 0;

                    while ((celula.chave >= lista->celulas[i].chave) && (i < lista->tamanho))
                    {
                        i++;
                    }
                    if (i == lista->tamanho)
                    {
                        return (insFinal(lista, celula));
                    }
                    else
                    {
                        for (j = lista->tamanho;(j > i); j--)
                        {
                            lista->celulas[j] = lista->celulas[j-1];
                        }
                        lista->celulas[i] = celula;
                        lista->tamanho++;
                        return(SUCESSO);
                    }
                }
            }
        }
    }
}

Celula remInicio(ListaLinear * lista)
{
    unsigned int i;
    Celula celulaResultado;

    if (lista->tamanho == 0)
    {
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else
    {
        celulaResultado = lista->celulas[0];
        for (i = 0; (i < lista->tamanho - 1); i++)
        {
            lista->celulas[i] = lista->celulas[i + 1];
        }
        lista->tamanho--;
        return (celulaResultado);
    }
}

Celula remFinal(ListaLinear * lista)
{
    unsigned int i;
    Celula celulaResultado;

    if (lista->tamanho == 0)
    {
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else
    {
        celulaResultado = lista->celulas[lista->tamanho - 1];
        lista->tamanho--;
        return (celulaResultado);
    }
}

Celula remChave(ListaLinear * lista, Celula celula){
    unsigned int i,j,k;
    unsigned int intQuantidadeRemocoes;

    Celula celulaResultado;

    if(lista->tamanho == 0)
    {
        celulaResultado.chave = CHAVE_INVALIDA;
        return (celulaResultado);
    }
    else
    {
        if (celula.chave == lista->celulas[0].chave)
        {
            while (celula.chave == lista->celulas[0].chave)
            {
                celulaResultado = remInicio(lista);
                if (celulaResultado.chave == CHAVE_INVALIDA)
                {
                    return (celulaResultado);
                }
            }
            
        }
        else
        {
            if (celula.chave == lista->celulas[lista->tamanho - 1].chave)
            {
                while (celula.chave == lista->celulas[lista->tamanho - 1].chave)
                {
                    celulaResultado = remFinal(lista);
                    if (celulaResultado.chave == CHAVE_INVALIDA)
                    {
                        return (celulaResultado);
                    }
                }
                
            }
            else
            {
                i = 0;
                while ((celula.chave > lista->celulas[i].chave) && (i < lista->tamanho))
                {
                    i++;
                }
                if (i == lista->tamanho)
                {
                    celulaResultado.chave = CHAVE_INVALIDA;
                    return (celulaResultado);
                }
                else
                {
                    intQuantidadeRemocoes = 0;
                    j = i;
                    while ((celula.chave == lista->celulas[j].chave) && (j < lista->tamanho))
                    {
                        intQuantidadeRemocoes++;
                        j++;
                    }
                    if (intQuantidadeRemocoes == 0)
                    {
                        celulaResultado.chave = CHAVE_INVALIDA;
                        return (celulaResultado);
                    }
                    else
                    {
                        celulaResultado = lista->celulas[i];
                        for (j = i; (j < (lista->tamanho - intQuantidadeRemocoes)); j++)
                        {
                            if (j + intQuantidadeRemocoes < lista->tamanho)
                            {
                                lista->celulas[j] = lista->celulas[j + intQuantidadeRemocoes];
                            }
                            lista->tamanho -= intQuantidadeRemocoes;
                            return (celulaResultado);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    Celula cel = {1,13};
    mostrarCelula(cel);

    ListaLinear lista;

    criarListaVazia(&lista);
    mostrarLista(lista);

    insInicio(&lista, cel);
    mostrarLista(lista);
    
    return 0;
}