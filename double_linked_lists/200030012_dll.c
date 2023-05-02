#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* rear = NULL;

struct node* allocate(int data){
    struct node* tmp = malloc(sizeof(struct node));
    tmp -> next = NULL;
    tmp -> prev = NULL;
    tmp -> data = data;

    return tmp;
}

int insert_head(int data){

    if(!head){
        head = allocate(data);
        rear = head;

        return 0;
    }

    struct node* tmp = allocate(data);

    tmp -> next = head;
    head -> prev = tmp;
    head = tmp;

    return 0;

}

int insert_rear(int data){
    if(!head){
        head = allocate(data);
        rear = head;

        return 0;
    }

    struct node* tmp = allocate(data);

    tmp -> prev = rear;
    rear -> next = tmp;
    rear = tmp;

    return 0;

}

struct node* find(int data){
    struct node* tmp = head;

    while(tmp && tmp->data != data) tmp = tmp -> next;

    return tmp;

}

int delete(int data){
    struct node* tmp = find(data);
    
    if(tmp == head){
        head = tmp->next;
        head -> prev = NULL;
        free(tmp);

        return -1;
    }

    if(tmp == rear){
        rear = tmp->prev;
        rear -> next = NULL;

        free(tmp);

        return -1;
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;


    free(tmp);
}

void display(){
    struct node* tmp =head;

    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp -> next;
    }
    printf("\n");
}

void display_reverse(){
    struct node* tmp = rear;

    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp -> prev;
    }

    printf("\n");
}

int main(){
    insert_head(1);
    insert_head(2);
    insert_head(3);

    display();
    
    delete(2);

    display();
}