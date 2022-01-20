#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c;
    if(scanf("%lf %lf %lf", &a, &b, &c) != 3){
        return 0;
    }

    if(a == 0 && b == 0 && c == 0){
        printf("ax^2+bx+c=0 has infinite solutions\n");
        return 0;
    }

    if(a == 0){
        printf("ax^2+bx+c=0 has only one solution: %lf\n",-c/b);
        return 0;
    }

    double det;
    det = pow(b,2)-4*a*c;
    double sol1,sol2;
    sol1=(-b+pow(det,0.5))/(2*a);
    sol2=(-b-pow(det,0.5))/(2*a);    

    if(det == 0){
        printf("ax^2+bx+c=0 has only one solution: %lf\n", sol1);
    }else if(det <0){
        printf("ax^2+bx+c=0 has no solution\n");
    }else{
        printf("ax^2+bx+c=0 has two solutions: %lf and %lf\n", sol1, sol2);
    }

    return 0;
}