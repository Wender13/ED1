#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarArvore(int chave);
void inserirNoArvore(No** raizArvore, int chave);
int removerNoArvore(No** raizArvore, int chave);
void listarArvorePreOrdem(No* raizArvore);
void listarArvoreOrdem(No* raizArvore);
void listarArvorePosOrdem(No* raizArvore);
int obterValorMaximoArvore(No* raizArvore);
int obterValorMinimoArvore(No* raizArvore);
No* obterNoValor(No* raizArvore, int chave);
int obterNivelNo(No* raizArvore, int chave, int nivel);
No* obterSucessorNo(No* raizArvore, int chave);
No* obterAntecessorNo(No* raizArvore, int chave);

int main() {
    No* raiz = NULL;
    int opcao, chave, resultado, nivel; 
    No* no;

    do {
        printf("entre com a operacao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Inserir raiz
                printf("entre com o valor da chave da raiz: ");
                scanf("%d", &chave);
                raiz = criarArvore(chave);
                break;

            case 2: // Inserir no
                printf("entre com o valor do no a ser inserido: ");
                scanf("%d", &chave);
                inserirNoArvore(&raiz, chave);
                break;

            case 3: // Remover no
                printf("entre com o valor do no a ser removido: ");
                scanf("%d", &chave);
                resultado = removerNoArvore(&raiz, chave);
                if (resultado == 1) {
                    printf("nao existe no com este valor na arvore\n");
                }
                break;

            case 4: // Listar em pré-ordem
                printf("configuracao da arvore: ");
                listarArvorePreOrdem(raiz);
                printf("\n");
                break;

            case 5: // Listar em ordem
                printf("configuracao da arvore: ");
                listarArvoreOrdem(raiz);
                printf("\n");
                break;

            case 6: // Listar em pos-ordem
                printf("configuracao da arvore: ");
                listarArvorePosOrdem(raiz);
                printf("\n");
                break;

            case 7: // Obter valor maximo
                resultado = obterValorMaximoArvore(raiz);
                if (resultado != -1) {
                    printf("valor maximo contido na arvore: %d\n", resultado);
                }
                break;

            case 8: // Obter valor minimo
                resultado = obterValorMinimoArvore(raiz);
                if (resultado != -1) {
                    printf("valor minimo contido na arvore: %d\n", resultado);
                }
                break;

            case 9: // Obter nó com valor
                printf("entre com o valor do no procurado: ");
                scanf("%d", &chave);
                no = obterNoValor(raiz, chave);
                if (no != NULL) {
                    nivel = obterNivelNo(raiz, chave, 0);
                    printf("no encontrado no nivel %d da arvore\n", nivel);
                } else {
                    printf("nao existe no com este valor na arvore\n");
                }
                break;

            case 10: // Obter sucessor de um nó
                printf("entre com o valor do no para o qual se procura o sucessor: ");
                scanf("%d", &chave);
                no = obterSucessorNo(raiz, chave);
                if (no != NULL) {
                    printf("valor do no sucessor: %d\n", no->chave);
                } else {
                    printf("nao existe sucessor para o no com este valor\n");
                }
                break;

            case 11: // Obter antecessor de um nó
                printf("entre com o valor do no para o qual se procura o antecessor: ");
                scanf("%d", &chave);
                no = obterAntecessorNo(raiz, chave);
                if (no != NULL) {
                    printf("valor do no antecessor: %d\n", no->chave);
                } else {
                    printf("nao existe antecessor para o no com este valor\n");
                }
                break;

            case 0: // Sair
                printf("fim\n");
                break;

            default:
                printf("opcao invalida. Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}

No* criarArvore(int chave) {
    No* no = (No*)malloc(sizeof(No));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void inserirNoArvore(No** raizArvore, int chave) {
    if (*raizArvore == NULL) {
        *raizArvore = criarArvore(chave);
        return;
    }
    if (chave == (*raizArvore)->chave) {
        printf("valor já inserido anteriormente\n");
        return;
    }
    if (chave < (*raizArvore)->chave) {
        inserirNoArvore(&(*raizArvore)->esquerda, chave);
    } else {
        inserirNoArvore(&(*raizArvore)->direita, chave);
    }
}

int removerNoArvore(No** raizArvore, int chave) {
    if (*raizArvore == NULL) return 1;

    if (chave < (*raizArvore)->chave) {
        return removerNoArvore(&(*raizArvore)->esquerda, chave);
    } else if (chave > (*raizArvore)->chave) {
        return removerNoArvore(&(*raizArvore)->direita, chave);
    } else {
        No* temp;
        if ((*raizArvore)->esquerda == NULL && (*raizArvore)->direita == NULL) {
            free(*raizArvore);
            *raizArvore = NULL;
        } else if ((*raizArvore)->esquerda == NULL) {
            temp = *raizArvore;
            *raizArvore = (*raizArvore)->direita;
            free(temp);
        } else if ((*raizArvore)->direita == NULL) {
            temp = *raizArvore;
            *raizArvore = (*raizArvore)->esquerda;
            free(temp);
        } else {
            temp = (*raizArvore)->direita;
            while (temp->esquerda != NULL) {
                temp = temp->esquerda;
            }
            (*raizArvore)->chave = temp->chave;
            return removerNoArvore(&(*raizArvore)->direita, temp->chave);
        }
        return 0;
    }
}

void listarArvorePreOrdem(No* raizArvore) {
    if (raizArvore != NULL) {
        printf("%d ", raizArvore->chave);
        listarArvorePreOrdem(raizArvore->esquerda);
        listarArvorePreOrdem(raizArvore->direita);
    }
}

void listarArvoreOrdem(No* raizArvore) {
    if (raizArvore != NULL) {
        listarArvoreOrdem(raizArvore->esquerda);
        printf("%d ", raizArvore->chave);
        listarArvoreOrdem(raizArvore->direita);
    }
}

void listarArvorePosOrdem(No* raizArvore) {
    if (raizArvore != NULL) {
        listarArvorePosOrdem(raizArvore->esquerda);
        listarArvorePosOrdem(raizArvore->direita);
        printf("%d ", raizArvore->chave);
    }
}

int obterValorMaximoArvore(No* raizArvore) {
    if (raizArvore == NULL) {
        printf("A árvore está vazia.\n");
        return -1;
    }
    No* atual = raizArvore;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual->chave;
}

int obterValorMinimoArvore(No* raizArvore) {
    if (raizArvore == NULL) {
        printf("A árvore está vazia.\n");
        return -1;
    }
    No* atual = raizArvore;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual->chave;
}

No* obterNoValor(No* raizArvore, int chave) {
    if (raizArvore == NULL) return NULL;
    if (chave == raizArvore->chave) return raizArvore;
    if (chave < raizArvore->chave) return obterNoValor(raizArvore->esquerda, chave);
    else return obterNoValor(raizArvore->direita, chave);
}

int obterNivelNo(No* raizArvore, int chave, int nivel) {
    if (raizArvore == NULL) {
        return -1; // Nó não encontrado
    }

    if (chave == raizArvore->chave) {
        return nivel; // Nó encontrado
    }

    int nivelEsquerda = obterNivelNo(raizArvore->esquerda, chave, nivel + 1);
    if (nivelEsquerda != -1) {
        return nivelEsquerda; // Nó encontrado na subárvore esquerda
    }

    return obterNivelNo(raizArvore->direita, chave, nivel + 1); // Busca na subárvore direita
}

No* obterSucessorNo(No* raizArvore, int chave) {
    No* noAtual = raizArvore;
    No* sucessor = NULL;
    while (noAtual != NULL) {
        if (chave < noAtual->chave) {
            sucessor = noAtual;
            noAtual = noAtual->esquerda;
        } else if (chave > noAtual->chave) {
            noAtual = noAtual->direita;
        } else {
            if (noAtual->direita != NULL) {
                noAtual = noAtual->direita;
                while (noAtual->esquerda != NULL) {
                    noAtual = noAtual->esquerda;
                }
                return noAtual;
            }
            break;
        }
    }
    return sucessor;
}

No* obterAntecessorNo(No* raizArvore, int chave) {
    No* noAtual = raizArvore;
    No* antecessor = NULL;
    while (noAtual != NULL) {
        if (chave < noAtual->chave) {
            noAtual = noAtual->esquerda;
        } else if (chave > noAtual->chave) {
            antecessor = noAtual;
            noAtual = noAtual->direita;
        } else {
            if (noAtual->esquerda != NULL) {
                noAtual = noAtual->esquerda;
                while (noAtual->direita != NULL) {
                    noAtual = noAtual->direita;
                }
                return noAtual;
            }
            break;
        }
    }
    return antecessor;
}