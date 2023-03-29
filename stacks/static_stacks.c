#include <stdio.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

int pop(){
    if(top <= -1){
        printf("Stack underflow\n");
        return -1;
    }

    return stack[top--];

}

int push(int data){
    if(top >= SIZE - 1){
        printf("Stack overflow\n");
        return -1;
    }

    stack[++top] = data;
    return data;
}

int peek(){
    if(top <= -1){
        printf("Stack underflow\n");
        return -1;
    }

    return stack[top];
}

int is_empty(){
    return top == -1;
}

int display(){
    if(top <= -1){
        printf("Stack underflow\n”");
        return -1;
    }
    
    printf("\nStack Elements\n----------------\n");

    for(int i = top; i >= 0; i--){
        printf("[%d]| %d |\n", i, stack[i]);
    }
    printf("=========\n");
}
int main(){

    display();

    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    pop();

    display();

    pop();
    pop();

    display();

}