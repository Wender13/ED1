#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
typedef struct 
{
    char Grupo;
    int Senha;
} Cliente;
    
typedef struct No
{
    Cliente cliente;
    struct No* prox;
} No;
    
No* NovoNo(char Grupo, int Senha);
void InsCliente(No** fila, char Grupo, int Senha) ;
void ChamarCliente(No** fila, int Caixa);
void MostrarFila(No* fila);
void FinalizarAtendimento(No* fila);
    
int main(int argc, char const *argv[]) 
{
    char escolha; int Senha = 1; No* fila = NULL;
    
    while (1) 
    {
        scanf(" %c", &escolha);
    
        if (escolha == 'I')
        {
            char Grupo;
            scanf(" %c", &Grupo);
            InsCliente(&fila, Grupo, Senha);
            Senha++;
        }
        else if (escolha == 'C')
        {
            int Caixa;
            scanf("%d", &Caixa);
            ChamarCliente(&fila, Caixa);
        } 
        else if (escolha == 'M')
        {
            MostrarFila(fila);
        }
        else if (escolha == 'E')
        {
            FinalizarAtendimento(fila);
        }
    }
    return 0;
}
    
No* NovoNo(char Grupo, int Senha) 
{
    No* novo = (No*) malloc(sizeof(No));
    novo->cliente.Grupo = Grupo;
    novo->cliente.Senha = Senha;
    novo->prox = NULL;
    return novo;
}
    
void InsCliente(No** fila, char Grupo, int Senha) 
{
    No* novo = NovoNo(Grupo, Senha);
    if (*fila == NULL) *fila = novo;
    else 
    {
        No* temp = *fila;
        while (temp->prox != NULL) 
        {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}
    
void ChamarCliente(No** fila, int Caixa) 
{
    if (*fila == NULL) printf("fila vazia\n");
    
    No* Atual = *fila; No* anterior = NULL; No* escolhido = NULL; No* anteriorEscolhido = NULL;
    
    if (Caixa == 1) 
    {
        while (Atual != NULL) 
        {
            if (Atual->cliente.Grupo == 'P') 
            {
                escolhido = Atual;
                break;
            }
            anteriorEscolhido = Atual;
            Atual = Atual->prox;
        }
    }
    
    if (escolhido == NULL) 
    {
        Atual = *fila;
        while (Atual != NULL) 
        {
            if (escolhido == NULL || Atual->cliente.Senha < escolhido->cliente.Senha) 
            {
                escolhido = Atual;
                anteriorEscolhido = anterior;
            }
            anterior = Atual;
            Atual = Atual->prox;
        }
    }
    
    if (escolhido != NULL) 
    {
        if (anteriorEscolhido != NULL) anteriorEscolhido->prox = escolhido->prox;
        else 
        {
            *fila = escolhido->prox;
        }
        printf("%c %d %d\n", escolhido->cliente.Grupo, escolhido->cliente.Senha, Caixa);
        free(escolhido);
    }
}
    
void MostrarFila(No* fila) 
{
    if (fila == NULL) printf("fila vazia\n"); 
    else 
    {
        No* Atual = fila;
        while (Atual != NULL) 
        {
            printf("%c %d\n", Atual->cliente.Grupo, Atual->cliente.Senha);
            Atual = Atual->prox;
        }
    }
}
    
void FinalizarAtendimento(No* fila) 
{
    if (fila == NULL) { printf("fim atendimento\n"); exit(0);} 
    else printf("fila ainda cheia\n");
}