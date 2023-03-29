#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int is_empty(){
    return top == NULL;
}

int main(){

    char *expression = "{(a+b)}*{([c-d])}[(p^q)][(x*y)]";
    int length = strlen(expression);

    for(int i = 0; i < length; i++){
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            push(expression[i]);
        }else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
            if(is_empty() || (expression[i] == ')' && pop() != '(') || (expression[i] == '}' && pop() != '{') || (expression[i] == ']' && pop() != '[')){
                printf("\nParentheses are wrongly matched at character %d\n",i);
                return 0;
            }
        }
    }
    printf("\nParentheses are correctly matched\n");
}