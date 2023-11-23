#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Estrutura para representar um nó da árvore
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Função para criar um novo nó
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para pular espaços na string de expressão
void skipSpaces(char* expression, int* index) {
    while (expression[*index] == ' ') {
        (*index)++;
    }
}

// Função para verificar se um caractere é um operador
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Função para obter a precedência de um operador
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0; // Não é um operador
    }
}

// Função para construir a árvore a partir da expressão
TreeNode* buildExpressionTree(char* expression, int* index) {
    skipSpaces(expression, index);

    char token = expression[*index];
    (*index)++; // Avançar para o próximo caractere

    if (token == '(') {
        // Encontrou uma expressão, crie um nó para o operador
        skipSpaces(expression, index);
        token = expression[*index];
        (*index)++; // Avançar para o próximo caractere
        TreeNode* newNode = createNode(token);

        // Construir recursivamente as subárvores para o operando esquerdo e direito
        newNode->left = buildExpressionTree(expression, index);
        newNode->right = buildExpressionTree(expression, index);

        // Avançar para o próximo caractere para fechar a expressão ')'
        skipSpaces(expression, index);
        if (expression[*index] == ')') {
            (*index)++;
        } else {
            printf("Erro: Esperado ')' não encontrado\n");
            exit(EXIT_FAILURE);
        }

        return newNode;
    } else if (isdigit(token) || (token == '-' && isdigit(expression[*index]))) {
        // Encontrou um número, crie um nó folha para o número
        return createNode(token);
    } else {
        printf("Caractere inesperado: %c\n", token);
        exit(EXIT_FAILURE);
    }
}

// Função para avaliar a expressão na árvore binária
int evaluateExpressionTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (isdigit(root->data) || (root->data == '-' && root->left == NULL)) {
        return root->data - '0';
    } else {
        int leftValue = evaluateExpressionTree(root->left);
        int rightValue = evaluateExpressionTree(root->right);

        switch (root->data) {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                if (rightValue != 0) {
                    return leftValue / rightValue;
                } else {
                    printf("Erro: Divisão por zero\n");
                    exit(EXIT_FAILURE);
                }
            default:
                printf("Operador desconhecido: %c\n", root->data);
                exit(EXIT_FAILURE);
        }
    }
}

// Função para liberar a memória da árvore
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void printTree(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, level + 1);

    int i;
    for (i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%c\n", root->data);

    printTree(root->left, level + 1);
}

int main() {
    //char expression[] = "(+ (+ 5 3) (* 2 4))";
    //char expression[] = "(+ 3 4)";
    //char expression[] = "(- (* 5 2) 3)";
    //char expression[] = "(/ (* (+ 2 3) 4) 2)";
    //char expression[] = "(+ (+ (+ 1 2) 3) 4)";
    char expression[] = "(- (* 2 (+ 3 4)) (/ 8 2))";

    int index = 0;

    // Construir a árvore a partir da expressão
    TreeNode* root = buildExpressionTree(expression, &index);

    // Avaliar a expressão
    int result = evaluateExpressionTree(root);
    printf("Resultado da expressao: %d\n", result);
    printTree(root,0);

    printf("%c", root->data);
    // Liberar a memória da árvore
    freeTree(root);

    return 0;
}
