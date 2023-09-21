#include <stdio.h>
#include <string.h>

// Definição da estrutura de pilha
#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Função para inicializar a pilha
void initialize(struct Stack *s) {
    s->top = -1;
}

// Função para empilhar um elemento na pilha
void push(struct Stack *s, char item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Pilha cheia! Não é possível adicionar mais elementos.\n");
    } else {
        s->top++;
        s->items[s->top] = item;
    }
}

// Função para desempilhar um elemento da pilha
char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Pilha vazia! Não é possível remover elementos.\n");
        return '\0';
    } else {
        char item = s->items[s->top];
        s->top--;
        return item;
    }
}

// Função para verificar se os parênteses estão balanceados
int areParenthesesBalanced(char expression[]) {
    struct Stack s;
    initialize(&s);
    unsigned int i;

    for (i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&s, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (s.top == -1) {
                return 0; // Parênteses desbalanceados
            }

            char top = pop(&s);

            if ((expression[i] == ')' && top != '(') ||
                (expression[i] == ']' && top != '[') ||
                (expression[i] == '}' && top != '{')) {
                return 0; // Parênteses desbalanceados
            }
        }
    }

    return (s.top == -1); // Verifica se a pilha está vazia
}

int main() {
    char expression[100];
    printf("Digite a expressao: ");
    scanf("%s", expression);

    if (areParenthesesBalanced(expression)) {
        printf("Expressao balanceada.\n");
    } else {
        printf("Expressao nao balanceada.\n");
    }

    return 0;
}
