#include <stdio.h>
#include <math.h>
#include <string.h>

double square(double x) {
    return x*x;
}

double cube(double x) {
    return x*x*x;
}

double integral(double (*f)(double p), int n, double x, double y) {
    double result = 0;
    double temp;
    double dx = (y-x)/n;
    for(int i =0; i<n; i++){
        x = x+dx;
//        printf("%lf\n", x);
//        printf("%lf\n", f(x));
        temp = dx*f(x);
        result = result +temp;
    }
    return result;
}

int main() {
    char fun[100]; // 字元陣列, 下個單元會教到
    int n;
    double x, y;
    double (*f)(double); // pointer to function, 幾個星期後會教到

    while (scanf("%99s",fun) != EOF) { // EOF定義於stdio.h內,一般系統上為-1
        if (strcmp(fun,"square")==0) {
            f = square;
        } else if (strcmp(fun,"cube")==0) {
            f = cube;
        } else if (strcmp(fun,"sqrt")==0) {
            f = sqrt;
        } else if (strcmp(fun,"cbrt")==0) {
            f = cbrt;
        } else if (strcmp(fun,"end")==0) {
            break;
        } else {
            printf("Unknown function\n");
            continue;
        }
        scanf("%d%lf%lf",&n,&x,&y);
        printf("Integral of %s from %lf to %lf is: %lf\n",fun,x,y,integral(f,n,x,y));
    }
    return 0;
}