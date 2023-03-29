#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

void print_array(int* a, int size);
int* allocate_array(int size);
int* resize_array(int* a, int size);
int* expand(int* a, int orgsize, int n);
int* contract(int* a, int orgsize, int n);


int main()
{	

	int* a = allocate_array(SIZE);

	for(int i=0; i<SIZE; i++)
	{
		a[i] = i;
	}

	
	print_array(a, SIZE);

	/* a = resize_array(a, SIZE * 2);
	print_array(a, SIZE * 2);
	printf("\n"); */
	
	a = expand(a, SIZE, 5);
	
  	 for(int i=SIZE+1; i<=SIZE+5; i++){
		a[i] = i;
	} 
	print_array(a, SIZE);

        printf("\n");
        
        a = contract(a, SIZE, 2);
        print_array(a, SIZE);
        printf("\n");

	return EXIT_SUCCESS;
}

int* allocate_array(int size)
{
	int* a = malloc(size * sizeof(int)); 
	memset(a, 0, SIZE*sizeof(int));

	return a;
}
int* expand(int* a, int orgsize, int n){
  return resize_array(a, orgsize + n);
	
}

int* contract(int* a, int orgsize, int n){
  return resize_array(a, orgsize - n);
}

int* resize_array(int* a, int size)
{
	int* new_a = realloc(a, size * sizeof(int));
        printf("\nSize of the array: %d\n",sizeof(new_a));
	return new_a;
}


void print_array(int* a, int size)
{
	
	printf("Array starts at %p\n", a);
	
	for(int i=0; i<size; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

