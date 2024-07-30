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
    Cliente Cliente;
    struct No* Prox;
} No;
    
No* NovoNo(char Grupo, int Senha);
void InsCliente(No** Fila, char Grupo, int Senha) ;
void ChamarCliente(No** Fila, int Caixa);
void MostrarFila(No* Fila);
void FinalizarAtendimento(No* Fila);
    
int main(int argc, char const *argv[]) 
{
    char escolha; int Senha = 1; No* Fila = NULL;
    
    while (1) 
    {
        scanf(" %c", &escolha);
    
        if (escolha == 'I')
        {
            char Grupo;
            scanf(" %c", &Grupo);
            InsCliente(&Fila, Grupo, Senha);
            Senha++;
        }
        else if (escolha == 'C')
        {
            int Caixa;
            scanf("%d", &Caixa);
            ChamarCliente(&Fila, Caixa);
        } 
        else if (escolha == 'M')
        {
            MostrarFila(Fila);
        }
        else if (escolha == 'E')
        {
            FinalizarAtendimento(Fila);
        }
    }
    return 0;
}
    
No* NovoNo(char Grupo, int Senha) 
{
    No* novo = (No*) malloc(sizeof(No));
    novo->Cliente.Grupo = Grupo;
    novo->Cliente.Senha = Senha;
    novo->Prox = NULL;
    return novo;
}
    
void InsCliente(No** Fila, char Grupo, int Senha) 
{
    No* novo = NovoNo(Grupo, Senha);
    if (*Fila == NULL) *Fila = novo;
    else 
    {
        No* temp = *Fila;
        while (temp->Prox != NULL) 
        {
            temp = temp->Prox;
        }
        temp->Prox = novo;
    }
}
    
void ChamarCliente(No** Fila, int Caixa) 
{
    if (*Fila == NULL) printf("Fila vazia\n");
    
    No* Atual = *Fila; No* Anterior = NULL; No* escolhido = NULL; No* AnteriorEscolhido = NULL;
    
    if (Caixa == 1) 
    {
        while (Atual != NULL) 
        {
            if (Atual->Cliente.Grupo == 'P') 
            {
                escolhido = Atual;
                break;
            }
            AnteriorEscolhido = Atual;
            Atual = Atual->Prox;
        }
    }
    
    if (escolhido == NULL) 
    {
        Atual = *Fila;
        while (Atual != NULL) 
        {
            if (escolhido == NULL || Atual->Cliente.Senha < escolhido->Cliente.Senha) 
            {
                escolhido = Atual;
                AnteriorEscolhido = Anterior;
            }
            Anterior = Atual;
            Atual = Atual->Prox;
        }
    }
    
    if (escolhido != NULL) 
    {
        if (AnteriorEscolhido != NULL) AnteriorEscolhido->Prox = escolhido->Prox;
        else 
        {
            *Fila = escolhido->Prox;
        }
        printf("%c %d %d\n", escolhido->Cliente.Grupo, escolhido->Cliente.Senha, Caixa);
        free(escolhido);
    }
}
    
void MostrarFila(No* Fila) 
{
    if (Fila == NULL) printf("Fila vazia\n"); 
    else 
    {
        No* Atual = Fila;
        while (Atual != NULL) 
        {
            printf("%c %d\n", Atual->Cliente.Grupo, Atual->Cliente.Senha);
            Atual = Atual->Prox;
        }
    }
}
    
void FinalizarAtendimento(No* Fila) 
{
    if (Fila == NULL) { printf("fim atendimento\n"); exit(0);} 
    else printf("Fila ainda cheia\n");
}