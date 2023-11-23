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
    } else if (value >= root->data) {
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

// Função para percorrer a árvore em ordem
int maxDepth(struct Node* root, int depth) {
    if (root != NULL) {
        int d1 = maxDepth(root->left, depth +1);
        int d2 = maxDepth(root->right, depth +1);
        return d1 > d2 ? d1 : d2;
    }
    else{
        return depth-1;
    }
}

// Função para percorrer a árvore em ordem
int search(struct Node* root, int value, int depth) {
    if (root != NULL) {
        if(root->data == value){
            printf("\nAchou %d com profundidade %d", value, depth);
            return depth;
        }
        else {
            if(value >= root->data){
                return search(root->right, value, ++depth);
            }
            else {
                return search(root->left, value, ++depth);
            }
        }
    }
    else {
        printf("\nNao tem %d", value);
        return -1;
    }
}

int main() {
    // Criando a raiz da árvore
    struct Node* root;

    // Inserindo elementos na árvore
    root = createTree(50);
    insert(root, 40);
    insert(root, 30);
    insert(root, 25);
    insert(root, 60);
    insert(root, 70);
     insert(root, 170);
      insert(root, 270);
       insert(root, 370);
    insert(root, 55);
   
    // Imprimindo a árvore em ordem
    printf("Arvore em ordem: ");
    inorderTraversal(root);

    int i;
    for(i=0; i < 100; i++){
        search(root, i,1);    
    }

    printf("\nMax Depth %d", maxDepth(root,1));
    
    return 0;
}
