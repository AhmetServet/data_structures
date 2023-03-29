#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node* top = NULL;

struct node* allocate(struct node* head){
    struct node* tmp = malloc(sizeof(struct node));
    tmp -> next = NULL;

    return tmp;
}



int push(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;

}

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

int insert_to_tail(int data){
    push(data);
    
    if(head == NULL){
        head = allocate(head);
        head -> data = data;
        tail = head;

        return 0;
    }


    struct node* tmp = allocate(head);
    tail -> next = tmp;
    tmp -> data = data;
    tmp -> next = NULL;
    tail = tmp;

}

int reverse(){
    struct node* tmp = head;
    
    while(tmp -> next != NULL){
        tmp -> data = pop();
        tmp = tmp -> next;
    }

    tmp -> data = pop();

}

int display(){
    struct node* tmp = head;

    printf("\n");
    while(tmp){
        printf("%d ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");
}

int main(){

    insert_to_tail(10);
    insert_to_tail(20);
    insert_to_tail(30);
    insert_to_tail(40);
    insert_to_tail(50);
    insert_to_tail(60);
    insert_to_tail(70);
    insert_to_tail(80);
    insert_to_tail(90);
    insert_to_tail(100);

    display();
    
    reverse();

    display();

    return 0;
}