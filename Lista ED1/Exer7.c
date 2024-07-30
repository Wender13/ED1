#include <stdio.h>
#include <stdlib.h>
    
// Estrutura de nó para a lista ligada
typedef struct Node {
    int value;
    struct Node* next;
} Node;
    
// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
    
// Função para inserir um novo nó após um nó específico
void insertAfter(Node** head, int newValue, int afterValue) {
    Node* current = *head;
    while (current != NULL && current->value != afterValue) {
        current = current->next;
    }
    if (current != NULL) {
        Node* newNode = createNode(newValue);
        newNode->next = current->next;
        current->next = newNode;
        printf("inserido %d\n", newValue);
    }
}
    
// Função para remover um nó da lista
void removeNode(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("removido %d\n", value);
    }
}
    
// Função para contar os nós entre dois valores
void countBetween(Node* head, int a, int b) {
    Node* current = head;
    int count = 0;
    int startCounting = 0;
    
    while (current != NULL) {
        if (current->value == a || current->value == b) {
            if (startCounting) {
                printf("quantidade %d\n", count);
                return;
            }
            startCounting = 1;
        } else if (startCounting) {
            count++;
        }
        current = current->next;
    }
}
    
// Função para mostrar a lista
void showList(Node* head) {
    if (head == NULL) {
        printf("lista vazia\n");
        return;
    }
    printf("lista ");
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}
    
int main() {
    int n, i, value;
    scanf("%d", &n);
    
    Node* head = NULL;
    Node* tail = NULL;
    
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    char command;
    while (1) {
        scanf(" %c", &command);
        if (command == 'I') {
            int p, e;
            scanf("%d %d", &p, &e);
            insertAfter(&head, p, e);
        } else if (command == 'R') {
            int p;
            scanf("%d", &p);
            removeNode(&head, p);
        } else if (command == 'C') {
            int a, b;
            scanf("%d %d", &a, &b);
            countBetween(head, a, b);
        } else if (command == 'M') {
            showList(head);
        } else if (command == 'F') {
            printf("fim\n");
            break;
        }
    }
    
    // Liberar a memória alocada
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}