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

void print_postfix(char *postfix){
    int i = 0;
    printf("Postfix expression:\n");

    while(postfix[i] != '\0'){
        printf("%c", postfix[i]);
        i++;
    }
    printf("\n");
}

int display(){
    if(top == NULL){
        printf("Stack underflow\n");
        return -1;
    }

    printf("\nStack Elements\n----------------\n");

    struct node *temp = top;
    while(temp != NULL){
        printf("| %c |\n", temp->data);
        temp = temp->next;
    }
    printf("=========\n");
}


int main(){
    char *infix = "L+M/(N*O^P)-(S+Q*R)";
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i = 0, j = 0;

    while(infix[i] != '\0'){
        if(isalpha(infix[i])){
            postfix[j] = infix[i];        

            i++;
            j++;
        }
        else if(infix[i] == '(' || infix[i] == '[' || infix[i] == '{' || infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            push(infix[i]);
            display();
            i++;
        }
        else if(infix[i] == ')' || infix[i] == ']' || infix[i] == '}'){
            while(peek() != '(' && peek() != '[' && peek() != '{'){
                postfix[j] = pop();
                display();

                j++;
            }
            pop();
            i++;
            display();

            while(top != NULL){
                postfix[j] = pop();
                display();
                j++;
            }
        }
        else{
            printf("Infix expression is invalid\n");
            
        }
    }
    print_postfix(postfix);
}