#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int isValidExpression(const char *expression) {
    Stack s;
    initStack(&s);
    int i;
    for (i = 0; expression[i]; i++) {
        if (expression[i] == '(') {
            push(&s, '(');
        } else if (expression[i] == ')') {
            if (isEmpty(&s)) {
                return 0; // Mismatched parentheses
            }
            pop(&s);
        }
    }
    return isEmpty(&s);
}

void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int k = 0;
    int i;
    for (i = 0; infix[i]; i++) {
        if (isspace(infix[i])) continue;
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, '(');
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = ' ';
                postfix[k++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        } else if (isOperator(infix[i])) {
            postfix[k++] = ' ';
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
                postfix[k++] = ' ';
            }
            push(&s, infix[i]);
        }
    }
    while (!isEmpty(&s)) {
        postfix[k++] = ' ';
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    int t, i;
    scanf("%d", &t);
    getchar(); // Consume newline character after the number of cases
    for (i = 0; i < t; i++) {
        char infix[MAX];
        char postfix[MAX * 2] = "";
        fgets(infix, MAX, stdin);
        infix[strcspn(infix, "\n")] = '\0'; // Remove newline character if present

        if (!isValidExpression(infix)) {
            printf("mal-formada\n");
        } else {
            infixToPostfix(infix, postfix);
            printf("%s\n", postfix);
        }
    }
    return 0;
}
