//Perform Inorder, Preorder and Postorder Transversal on the BST tree construction.

#include <stdio.h>
#include <stdlib.h>

enum Traversal {preorder, inorder, postorder};

typedef enum Traversal Traversal;
typedef struct Node Node;

struct Node {
    int value;
    Node* left, *right;
};


Node* init_tree(int data) {
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}

Node* create_node(int data) {
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}
void free_tree(Node* root) {
    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}


void print_tree(Traversal traversal, Node* root) {
    if (!root)
        return;
    switch(traversal) {
        case (preorder):
            printf("%d -> ", root->value);
            print_tree(traversal, root->left);
            print_tree(traversal, root->right);
            break;

        case (inorder):
            print_tree(traversal, root->left);
            printf("%d -> ", root->value);
            print_tree(traversal, root->right);
            break;

        case (postorder):
    
            print_tree(traversal, root->left);
            print_tree(traversal, root->right);
            printf("%d -> ", root->value);
            break;
    }
}

int main() {
    int a;int b;int c;int d;int e;int f;int g;
    printf("Input Seven data for the tree: ");
    scanf("%d\n%d\n%d\n%d\n%d\n%d\n%d", &a, &b, &c, &d, &e, &f, &g);
 
    Node* root = init_tree(a);
    
    root->left = create_node(b);
    root->right = create_node(c);

    root->left->left = create_node(d);
    root->left->right = create_node(e);

    root->right->left = create_node(f);
    root->right->right = create_node(g);

    printf("Preorder Traversal:\n");
    print_tree(preorder, root);
    printf("\n\n");

    printf("Inorder Traversal:\n");
    print_tree(inorder, root);
    printf("\n\n");

    printf("Postorder Traversal:\n");
    print_tree(postorder, root);
    printf("\n\n");

    free_tree(root);
    return 0;
}
