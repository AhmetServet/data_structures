#include <stdio.h>

int queue[5];
int maxSize = 5;

int front;
int rear;
int counter;

int is_empty(){
    if(counter == 0){
        return 1;
    }
    return 0;
}

int is_full(){
    if(counter == maxSize){
        return 1;
    }
    return 0;
}

void enqueue(int data){
    if(!is_full()){
        if(front == rear){
            queue[rear] = data; 
            rear++;
        }
        else{   
            rear = rear % maxSize;
            queue[rear] = data;
            rear++;
        }

        counter++;
    }
}

void dequeue(){
    if(!is_empty()){
        front = front % maxSize;
        queue[front] = 0;
        front++;
        counter--;
    }
}
 
void display(){
    for(int i = 0; i< maxSize; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void main(){
    enqueue(6);
    enqueue(99);
    enqueue(15);
    enqueue(72);
    enqueue(68);
    
    dequeue();
    dequeue();
    
    enqueue(14);
    enqueue(7);
    enqueue(21);
    
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    enqueue(1);

    dequeue();
    display();
}
