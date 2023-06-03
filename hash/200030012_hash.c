#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

char* arr[TABLE_SIZE] = {NULL, };

int hash(char* str){
    int hash = 0;
    while(*str){
        hash += *str;
        str++;
    }
    return hash % TABLE_SIZE;
}

int hash2(char* str){
    int hash = 0;
    
    for(int i=0; str[i] != '\0'; i++){
        hash += str[i];
    }
    return hash % TABLE_SIZE;
}

int insert(char* str){
    int hash_key = hash(str);

    while(arr[hash_key] != NULL){
        hash_key = (hash_key + 1) % TABLE_SIZE;
    }
    

    arr[hash_key] = strdup(str);

    return hash_key;    
}

int search(char* str) {
    int key = hash(str);
    if (strcmp(arr[key], str) == 0) {
        printf("\"%s\" found at: %d\n", str, key);    
        return 0;
    } else {
        printf("Not found\n");
        return -1;
    }
}



void dump(){
    for(int i=0; i<TABLE_SIZE; i++){
        printf("%d - %s\n", i, arr[i]);
    }
}

int main(){
    // printf("hash: %d\n", hash("Test"));
    // printf("hash: %d\n", hash("Ttes"));
    // printf("hash2: %d\n", hash2("Ttes"));
    // printf("hash2: %d\n", hash2("Ttes"));
    
    insert("Ahmet");
    insert("Servet");
    insert("Polat");
    insert("Mahmut");
    insert("Mehmet");
    insert("Ali");
    insert("Veli");
    insert("Sena");
    insert("Sevim");
    insert("murmur");

    dump();

    search("Ahmet");
    search("Polat");
    search("mirmir");
    search("Mahmut");

    return 0;
}