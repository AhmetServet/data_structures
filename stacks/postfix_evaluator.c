#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    char *postfix = "3 5 1 * + 9 -";
    
    int i=0;
    while(postfix[i] != '\0'){
        if(isdigit(postfix[i])){
            push(postfix[i] - '0');
            display();
            
        }else if(postfix[i] != ' '){
            int op1 = pop();
            int op2 = pop();

            switch(postfix[i]){
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op2 - op1);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
            }
            
        }
        i++;
    }           

    printf("\nResult: %d\n", pop());
}