#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left_child;
    struct node* right_child;
};

struct node* root = NULL;

struct node* new_node(int data){
    struct node* tmp = malloc(sizeof(struct node));
    tmp -> left_child = NULL;
    tmp -> right_child = NULL;
    tmp -> data = data;

    return tmp;
}

int insert(int data){
    if(!root){
        root = new_node(data);
        return 0;
    }

    struct node* tmp = root;
    
    while(tmp){
        if(tmp->data >= data){
            if(tmp->left_child){
                tmp = tmp->left_child;
            }else{
                tmp->left_child = new_node(data);
                return 0;
            }
        }
        else{
            if(tmp->right_child){
                tmp = tmp->right_child;
            }else{
                tmp->right_child = new_node(data);
                return 0;
            }
        }
    }
}

int search(int data){
    struct node* tmp = root;

    while(tmp){
        if(tmp->data == data)
            return 1;
        
        if(tmp->data > data)
            tmp = tmp->left_child;
        else if (tmp->data < data)
            tmp = tmp->right_child;
    }

    return 0;
}

int pre_order(struct node* root){
    if(!root)
        return 0;
    
    printf("%d ", root->data);
    pre_order(root->left_child);
    pre_order(root->right_child);
}

int in_order(struct node* root){
    if(!root)
        return 0;
    
    in_order(root->left_child);
    printf("%d ", root->data);
    in_order(root->right_child);
}

int post_order(struct node* root){
    if(!root)
        return 0;
    
    post_order(root->left_child);
    post_order(root->right_child);
    printf("%d ", root->data);
}

void main(){
    insert(5);
    insert(2);
    insert(7);
    insert(1);
    insert(4);
    insert(3);

    printf("Pre-order:");
    pre_order(root);

    printf("\nIn-order:");
    in_order(root);

    printf("\nPost-order:");
    post_order(root);

    printf("\nDoes the number exist?: %d\n", search(5));
}