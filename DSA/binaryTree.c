#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) { 
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node* current;
    struct node *parent;

    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;

    if (root == NULL) {
        root = temp;
    } else {
        current = root;
        parent = NULL;

        while (1) {
            parent = current;

            if (data < parent->data) {
                current = current->leftChild;

                if (current == NULL) {
                    parent->leftChild = temp;
                    return;
                }
            } else {
                current = current->rightChild;

                if (current == NULL) {
                    parent->rightChild = temp;
                    return;
                }
            }
        }
    }
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

struct node* search(int data) {
    struct node *current = root;
    printf("Visiting elements: ");

    while (current->data != data) {
        if (current != NULL) {
            printf("%d ", current->data);

            if (current->data > data) {
                current = current->leftChild;
            } else {
                current = current->rightChild;
            }

            if (current == NULL) {
                return NULL;
            }
        }
    }

    return current;
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->leftChild);
        printf("%d ", root->data);
        inOrder(root->rightChild);
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%d ", root->data);
    }
}

int main() {
    insert(11);
    insert(20);
    insert(3);
    insert(42);

    preOrder(root);
    printf("\n");

    struct node * temp = search(20);
    if(temp != NULL){
        printf("Element found.\n");
        printf("( %d )",temp->data);
        printf("\n");
    } else {
        printf("Element not found.\n");
    }
}