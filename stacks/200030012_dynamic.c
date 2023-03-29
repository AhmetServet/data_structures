#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

int pop(){
    if(top == NULL){
        printf("Stack underflow\n");
        return -1;
    }

    struct node *temp = top;
    int data = temp->data;
    top = top->next;
    free(temp);
    
    return data;
}

int push(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;

    return data;
}

int peek(){
    if(top == NULL){
        printf("Stack underflow\n");
        return -1;
    }

    return top->data;
}

int is_empty(){
    return top == NULL;
}

int display(){
    if(top == NULL){
        printf("Stack underflow\n");
        return -1;
    }

    printf("\nStack Elements\n----------------\n");

    struct node *temp = top;
    while(temp != NULL){
        printf("| %d |\n", temp->data);
        temp = temp->next;
    }
    printf("=========\n");
}



int main(){
    
        display();
    
        push(10);
        push(20);
        push(30);
    
        display();

        printf("Peek: %d", peek());


        pop();
        pop();

        display();

        pop();
        pop();
    
}

