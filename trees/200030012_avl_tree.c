#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* allocate_node();
struct node* insert(struct node* root, int data);
struct node* balance(struct node* n);
struct node* rotate_rright(struct node* p);
struct node* rotate_right_left(struct node* p);
struct node* rotate_left_right(struct node* p);
struct node* rotate_lleft(struct node* p);
int height(struct node* n);
int diff(struct node* n);
int inorder(struct node* n);
int preorder(struct node* n);
int postorder(struct node* n);




void main(){
    
    struct node* root = allocate_node();

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    printf("Height: %d\n", height(root));
    printf("Inorder:\n");
    inorder(root);
}



struct node* allocate_node(){
    struct node* n = calloc(1, sizeof(struct node));
    return n;
}

struct node* insert(struct node* root, int data){

    if(!root){
        struct node* root = allocate_node();
        root->data = data;
        return root;
    }

    if(root->data > data){
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return balance(root);
}

struct node* balance(struct node* n){
    int balance_factor = diff(n);

    if(balance_factor > 1){
        if(diff(n->left) > 0){
            n = rotate_lleft(n);
        } else {
            n = rotate_left_right(n);
        }
    } else if(balance_factor < -1){
        if(diff(n->right) > 0){
            n = rotate_right_left(n);
        } else {
            n = rotate_rright(n);
        }
    }

    return n;
}

int diff(struct node* n){
    int left_height = height(n->left);
    int right_height = height(n->right);
    int balance_factor = left_height - right_height;
    return balance_factor;
}

int height(struct node* n){
    if (!n) return 0;

    int left_height = height(n->left);
    int right_height = height(n->right);

    return left_height > right_height ? left_height+1 : right_height+1;
}

struct node* rotate_rright(struct node* p){

    struct node* tmp = p->right;
    p->right = tmp->left;
    tmp->left = p;

    return tmp;
}

struct node* rotate_right_left(struct node* p){
    struct node* tmp = p->right;
    p->right = rotate_lleft(tmp);
    
    return rotate_rright(p);
}

struct node* rotate_left_right(struct node* p){
    struct node* tmp = p->left;
    p->left = rotate_rright(tmp);

    return rotate_lleft(p);
}

struct node* rotate_lleft(struct node* p){
    struct node* tmp = p->left;
    p->left = tmp->right;
    tmp->right = p;

    return tmp;
}

int inorder(struct node* n){
    if(!n) return 0;

    inorder(n->left);
    printf("%d\n", n->data);
    inorder(n->right);

    return 1;
}

int preorder(struct node* n){
    if(!n) return 0;

    printf("%d\n", n->data);
    preorder(n->left);
    preorder(n->right);

    return 1;
}

int postorder(struct node* n){
    if(!n) return 0;

    postorder(n->left);
    postorder(n->right);
    printf("%d\n", n->data);

    return 1;
}