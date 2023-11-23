#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na árvore
struct Node* insert(struct Node* root, int value) {
    
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Função para inserir um novo nó na árvore
struct Node* createTree(int value) {
    return createNode(value);
}


// Função para percorrer a árvore em ordem
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    // Criando a raiz da árvore
    struct Node* root;

    // Inserindo elementos na árvore
    root = createTree(50);
    insert(root, 50);
    insert(root, 50);
    insert(root, 50);
    insert(root, 30);
    insert(root, 30);
    insert(root, 30);
   
    // Imprimindo a árvore em ordem
    printf("Arvore em ordem: ");
    inorderTraversal(root);

    return 0;
}
