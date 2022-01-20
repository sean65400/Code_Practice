#include <stdio.h>

void square(int n) {
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void right_triangle(int n) {
    for(int i =0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void left_triangle(int n) {
    for(int i =0; i < n; i++){
        for(int j =0; j< n-i-1; j++){
            printf(" ");
        }
        for(int j = 0; j < i+1; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void mid_triangle(int n) {
    for(int i =0; i < n; i++){
        for(int j =0; j< n-i-1; j++){
            printf(" ");
        }
        for(int j = 0; j < 2*(i+1)-1; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void diamond(int n) {
    for(int i =0; i < n; i++){
        for(int j =0; j< n-i-1; j++){
            printf(" ");
        }
        for(int j = 0; j < 2*(i+1)-1; j++){
            printf("*");
        }
        printf("\n");
    }
    n--;
    for(int i =0; i < n; i++){
        for(int j =0; j< i+1; j++){
            printf(" ");
        }
        for(int j = 0; j < 2*(n-i)-1; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void empty_diamond(int n) {
    for(int i = 0; i < 2*n+1; i++){
        printf("*");
    }
    printf("\n");

    for(int i =0; i < n; i++){
        for(int j =0; j< n-i; j++){
            printf("*");
        }
        for(int j = 0; j < 2*(i+1)-1; j++){
            printf(" ");
        }
        for(int j =0; j< n-i; j++){
            printf("*");
        }
        printf("\n");
    }
    n--;
    for(int i =0; i < n; i++){
        for(int j =0; j< i+2; j++){
            printf("*");
        }
        for(int j = 0; j < 2*(n-i)-1; j++){
            printf(" ");
        }
        for(int j =0; j< i+2; j++){
            printf("*");
        }
        printf("\n");
    }

    n++;
    for(int i = 0; i < 2*n+1; i++){
        printf("*");
    }
    printf("\n");
}

int main() {
    int size;
    printf("Please input the graph size: \n");
    scanf("%d",&size);

    square(size);
    right_triangle(size);
    left_triangle(size);
    mid_triangle(size);
    diamond(size);
    empty_diamond(size);
    return(0);
}