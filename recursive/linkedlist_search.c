#include <stdio.h>
#include <stdlib.h>



struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;

struct node* allocate(struct node* head){
	
	struct node* tmp = malloc(sizeof(struct node));
	tmp -> next = NULL;
	
	return tmp; 
}

int insert(int data){
	if(head == NULL){
		head = allocate(head);
		head -> data = data;
	
		return 0;
	}


	struct node* tmp = allocate(head);
	tmp -> data = data;
	tmp -> next = head;

	head = tmp;

	return 0;
}


int insert_to_tail(int data){
	if(head == NULL){
		head = allocate(head);
		head -> data = data;
	
		return 0;
	}


	struct node* tmp = allocate(head);
	struct node* last_node = head;

	while(last_node && last_node -> next){
		last_node = last_node -> next;
	}

	last_node -> next = tmp;
	tmp -> data = data;
	tmp -> next = NULL;

	return 0;
}

int insert_in_order(int data){
	if(head == NULL){
		head = allocate(head);
		head -> data = data;
	
		return 0;
	}

	struct node* tmp = allocate(head);
	struct node* last_node = head;

	while(last_node && last_node -> next && last_node -> next -> data < data){
		last_node = last_node -> next;
	}

	tmp -> next = last_node -> next;
	last_node -> next = tmp;
	tmp -> data = data;

	return 0;
}

int find(struct node* tmp, int what){

    if(!tmp)
        return -1;

    if(tmp -> data == what)
        return 1;
    
    return find(tmp -> next, what);
}

int delete(int what){
	struct node* tmp = head;
	struct node* prev = NULL;

	while(tmp){
		if(tmp -> data == what){
			if(prev == NULL){
				head = tmp -> next;
				free(tmp);
				return 0;
			}

			prev -> next = tmp -> next;
			free(tmp);
			return 0;
		}

		prev = tmp;
		tmp = tmp -> next;
	}

	printf("%d not found\n",what);
	return -1;
}


int print_list(){
	struct node* tmp = head;

	while(tmp){
		printf("%d ",tmp->data);
		tmp = tmp -> next;
	}

	printf("\n");
	
	return 0; 
}

void main(){
    insert_to_tail(1);
    insert_to_tail(2);
    insert_to_tail(3);
    insert_to_tail(4);
    insert_to_tail(5);
    insert_to_tail(6);
    insert_to_tail(7);
    insert_to_tail(8);
    insert_to_tail(9);
    insert_to_tail(10);
    insert_to_tail(11);
    insert_to_tail(12);
    insert_to_tail(13);

    int isFound = find(head, 14);
    
    print_list();
    printf("isFound: %d", isFound);
}