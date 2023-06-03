#include <stdio.h>

int sigma(int n){
    if(n == 1)
        return 1;

    return n + sigma(n-1);    
}


int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sigma(%d) = %d", n, sigma(n));
    return 0;
}