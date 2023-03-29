#include <stdio.h>
#include <stdlib.h>


int* allocate_array(int size);
int* resize_array(int* arr, int new_size);
int* fill_array(int* arr, int size);
int* print_array(int* arr, int size);


int main(void)
{
	int size;
	int process;
	int resizeNum;
	
	while (1){
		printf("1. Allocate Array\n2. Resize Array\nEnter the number of the process you want to run:");
		scanf("%d",&process);


		switch (process){
		
		case 1:
		
			printf("Number of items: \n");
			scanf("%d", &size);
			

			int* arr = allocate_array(size);

			print_array(arr, size);

			break;
		
		case 2: 
			printf("New Number of items: \n");
			scanf("%d", &resizeNum);

			int* resized_arr = resize_array(arr, resizeNum);

			print_array(resized_arr, resizeNum);



	

			break;
		}


		//printf("Array Size:%d\n", sizeof(arr)/sizeof(int));
		// It is a logical error. We want to print the size of the array, but
		// we cant reach it with giving the param "arr". Because it is a pointer
		// and the function shows the size of the pointer instead of array.


				



	}



		

	
	


	return 0;
}

int* allocate_array(int size){

	int* arrptr = (int*) calloc(size, sizeof(int));

	fill_array(arrptr, size);
	  
	return arrptr;
}

int* fill_array(int* arr, int size){
	for(int i=0; i<size; i++)
		arr[i] = i;

	return arr;
}

int* print_array(int* arr, int size){
	for(int i=0; i<size+10; i++){
	printf("%d ",arr[i]);
	}
	printf("\n");
}

int* resize_array(int* arr, int new_size){
	free(arr);
	int* new_arr = (int*)realloc(arr, new_size*sizeof(int));

	fill_array(new_arr, new_size);

	return new_arr;
}
