#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf(" %d",&n);
//set up the array
    int** arr = (int**) malloc(n*sizeof(int*));  //malloc rows
    for(int i = 0; i < n; i++){  //malloc columns
        arr[i] = (int*) malloc((i+1)*sizeof(int));
    }
//fill in the array
    for(int i = 0; i < n; i++){  //switch between rows
        for(int j = 0; j < i+1; j++){  //fill in the columns
            if(j == 0){
                arr[i][j] = 1;
            }else if(j == i){
                arr[i][j] = 1;
                break;
            }else{
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
            }        
        }
    }
//print
    for(int i = 0; i < n; i++){  //switch between rows
        for(int j = 0; j < n-i-1; j++){  //print blank
            printf("   ");
        }
        for(int j = 0; j < i+1; j++){  //print array
            printf("%3d   ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++){  //free
        free(arr[i]);
    }
    free(arr);

    return 0;
}