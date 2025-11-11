#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void DFSPreorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        DFSPreorder(root->left);
        DFSPreorder(root->right);
    }
}


void DFSInorder(struct Node* root) {
    if (root != NULL) {
        DFSInorder(root->left);
        printf("%d ", root->data);
        DFSInorder(root->right);
    }
}


void DFSPostorder(struct Node* root) {
    if (root != NULL) {
        DFSPostorder(root->left);
        DFSPostorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("DFS Preorder Traversal: ");
    DFSPreorder(root);
    printf("\n");

    printf("DFS Inorder Traversal: ");
    DFSInorder(root);
    printf("\n");

    printf("DFS Postorder Traversal: ");
    DFSPostorder(root);
    printf("\n");

    return 0;
}
