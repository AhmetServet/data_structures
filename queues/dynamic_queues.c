#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *allocate(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    
    new_node->data = data;
    new_node->next = NULL;
    
    return new_node;    
}

int is_empty(){
    if(front == NULL){
        return 1;
    }
    return 0;
}

void enqueue(int data){
    struct node *new_node = allocate(data);
    
    if(is_empty()){
        front = new_node;
        rear = new_node;
    }

    rear->next = new_node;
    rear = new_node;
    
}

void dequeue(){
    if(is_empty()){
        printf("Empty queue");
    }

    struct node *temp = front;
    front = front->next;
    free(temp);
}

void front_element(){
    if(is_empty()){
        printf("Empty queue\n");
    }

    printf("Front: %d\n", front->data);
}

void display(){
    struct node *temp = front;

    printf("Queue: ");

    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void main(){
    printf("Is empty: %d\n", is_empty());
    
    enqueue(8);
    enqueue(5);
    
    front_element();

    enqueue(13);
    dequeue();
    enqueue(2);

    display();
    
    front_element();
    printf("Is empty: %d\n", is_empty());
    
    display();
}