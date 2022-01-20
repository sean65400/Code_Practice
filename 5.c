#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int max = n*2-1;
    int indx;
    for(int i = 0; i < 2*n; i++){
        if(i<n){
            for(int j = 0; j < n-i-1; j++){
                printf(" ");
            }
            for(int j = 0; j < 2*n-1-2*(n-i-1); j++){
                printf("*");
            }
            printf("\n");
        }else{
            indx = (n % 2 == 0) ? n-1 : n -2;  
            //indx = TRUE ? TRUE statement : FALSE statement
            for(int j = 0; j < (2*n-1-indx)*0.5; j++){
                printf(" ");
            }
            for(int j = 0; j < indx; j++){
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}