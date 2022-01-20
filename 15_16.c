#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int g_j_i(double**, double**, int, int);
void gauss(double**, int, int, int*);
void printMatrix(double**,char*, int, int);
double** readMatrix(int, int);
void determinant();
void inverse();
void times();
void plus();
void swap_row(double**, int, int, int, int*);

int main(){
    char optn[50];
    scanf(" %s", optn);
    if(strcmp(optn, "determinant") == 0){
        determinant();
    }else if(strcmp(optn, "inverse") == 0){
        inverse();
    }else if(strcmp(optn, "*") == 0){
        times();
    }else if(strcmp(optn, "+") == 0){
        plus();
    }else{
        printf("Wrong input!!\n");
    }
    return 0;
}

int g_j_i(double** m, double** i_m, int row, int col){
    double factor;
    int chk_d = 1;
    char m_str[10] = "matrix";
    int s = 0;
    int* r_s_i =&s;
//guass elimination
    for(int i = 0; i < row-1; i++){
        for(int j = 0; j < row-1-i; j++){
            if( m[i][i] == 0){
                swap_row(m, row, col, i, r_s_i);
                swap_row(i_m, row, col, i, r_s_i);
            }
            factor = -1.0*m[i+j+1][i]/m[i][i];
            for(int k = 0; k < col; k++){
                m[i+j+1][k] = m[i+j+1][k] +factor*m[i][k];
                i_m[i+j+1][k] = i_m[i+j+1][k] +factor*i_m[i][k];
            }
        }
    }
//check whether it is inversible or not
    for(int i = 0; i < row; i++){
        chk_d = chk_d*m[i][i];
    }
    if(chk_d == 0){
        return -1;
    }
//the rest of gauss jordan elimination
    for(int i = 0; i < row-1; i++){
        for(int j = 0; j< row-1-i; j++){
            factor = -1.0*m[col-2-i-j][col-1-i]/m[col-1-i][col-1-i];
            for(int k = 0; k < col; k++){
                m[col-2-i-j][k] = m[col-2-i-j][k]+factor*m[col-1-i][k];
                i_m[col-2-i-j][k] = i_m[col-2-i-j][k]+factor*i_m[col-1-i][k];
            }
        }
    }
//turning lhs to 1
    for(int i = 0; i < row; i++){
        factor = m[i][i];
        for(int j = 0; j < col; j++){
            m[i][j] = m[i][j]/factor;
            i_m[i][j] = i_m[i][j]/factor;
        }
    }
    return 0;
}

void gauss(double** m, int row, int col, int* r_s_i){
    double factor;
    char m_str[2] = "12";

    for(int i = 0; i < row-1; i++){
        for(int j = 0; j < row-1-i; j++){
            if( m[i][i] == 0){
                swap_row(m, row, col, i, r_s_i);
            }
            factor = -1.0*m[i+j+1][i]/m[i][i];
            for(int k = 0; k < col; k++){
                m[i+j+1][k] = m[i+j+1][k] +factor*m[i][k];
            }
        }
    }
}

void printMatrix(double** m,char* m_str, int row, int col){
    printf("%s %d %d\n", m_str, row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("% 10lf ", m[i][j]);
        }
        printf("\n");
    }
}

double** readMatrix(int row, int col){
//malloc
    double** m;
    m = (double**) malloc(row*sizeof(double*));
    for(int i = 0; i < row; i++){
        m[i] = (double*) malloc(col*sizeof(double));
    } 
//fill in
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf(" %lf", &m[i][j]);
        }
    }
    return m;
}

void determinant(){
    char m_str[10];
    double **m;
    int row;
    int col;
    int r_s_i = 0;
    double result = 1.0;
    scanf(" %s %d %d", m_str, &row, &col);
//check whether the spelling is correct or not
    if(strcmp(m_str, "matrix") != 0){
        printf("Please check your spelling.\n");
        return;
    }
//check if it is an n*n matrix
    if( row != col){
        printf("Matrix dimension mismatch.\n");
        return;
    }
//set up the matrix
    m = readMatrix(row, col);
//print it out
    printMatrix(m, m_str, row, col);
//Gauss Elimination
    gauss(m, row, col, &r_s_i);
//calculate the determinant
    for(int i = 0; i < row; i++){
        result = result*m[i][i];
    }
    result = result * pow(-1.0,r_s_i);
//free the matrix    
    for(int i = 0; i < row; i++){
        free(m[i]);
    } 
    free(m);
//return the result
    printf("The determinant of this matrix is %lf\n", result);
}

void inverse(){
    char m_str[10];
    double **m, **i_m;
    int test_result;
    int row;
    int col;
    int chk_d = 0;
    scanf(" %s %d %d", m_str, &row, &col);
//check whether the spelling is correct or not
    if(strcmp(m_str, "matrix") != 0){
        printf("Please check your spelling.\n");
        return;
    }
//check if it is an n*n matrix
    if( row != col){
        printf("Matrix dimension mismatch.\n");
        return;
    }
//will check whether determinant is 0 or not in the Gauss-Jordan Elimination
//set up the matrix
    m = readMatrix(row, col);
    printMatrix(m, m_str, row, col);
//set up the Identity matrix
    i_m = (double**) malloc(row*sizeof(double*));
    for(int i = 0; i < row; i++){
        i_m[i] = (double*) malloc(col*sizeof(double));
    }
    for(int i = 0; i < row; i++){
        i_m[i][i] = 1.0;
    }
//combine Gauss-Jordan Elimination with an Identity matrix
    chk_d = g_j_i(m, i_m, row ,col);
//check determinant
    if (chk_d == -1){
        printf("the matrix is inversible due to determinant = 0\n");
        return;
    }
//print it out
    printf("The inverse matrix is\n");
    printMatrix(i_m, m_str, row, col);
//free the Identity matrix
    for(int i = 0; i < row; i++){
        free(m[i]);
    } 
    free(m);
    for(int i = 0; i < row; i++){
        free(i_m[i]);
    } 
    free(i_m);
}

void times(){
    double **a, **b, **result;
    char m_str[10];
    int a_row;
    int a_col;
    int b_row;
    int b_col;
    scanf(" %s %d %d", m_str, &a_row, &a_col);
//check whether the spelling is correct or not
    if(strcmp(m_str, "matrix") != 0){
        printf("Please check your spelling.\n");
        return;
    }
//setup a
    a = readMatrix(a_row, a_col);
    scanf(" %s %d %d", m_str, &b_row, &b_col);
//check whether the spelling is correct or not
    if(strcmp(m_str, "matrix") != 0){
        printf("Please check your spelling.\n");
        return;
    }
//setup b
    b = readMatrix(b_row, b_col);
//check if it is an it is possible to multiply matrix
    if( a_col != b_row){
        printf("Matrix unable to multiply.\n");
        return;
    }
//receiver
    result = (double**) malloc(a_row*sizeof(double*));
    for(int i = 0; i < a_row; i++){
        result[i] = (double*) malloc(b_col*sizeof(double));
    }
//multiply
    for(int i = 0; i < a_row; i++){
        for(int j = 0; j < b_col; j++){
            for(int k = 0; k < a_col; k++){
                result[i][j] = result[i][j] +a[i][k]*b[k][j];
            }
        }
    }
//print
    printMatrix(a, m_str, a_row, a_col);
    printf("*\n");
    printMatrix(b, m_str, b_row, b_col);
    printf("=\n");
    printMatrix(result, m_str, a_row, b_col);
//free
    for(int i = 0; i < a_row; i++){
        free(a[i]);
    } 
    free(a);
    for(int i = 0; i < b_row; i++){
        free(b[i]);
    } 
    free(b);
    for(int i = 0; i < a_row; i++){
        free(result[i]);
    } 
    free(result);
}

void plus(){
    double **a, **b, **result;
    char m_str[10];
    int a_row;
    int a_col;
    int b_row;
    int b_col;
    scanf(" %s %d %d", m_str, &a_row, &a_col);
//check whether the spelling is correct or not
    if(strcmp(m_str, "matrix") != 0){
        printf("Please check your spelling.\n");
        return;
    }
//setup a
    a = readMatrix(a_row, a_col);
    scanf(" %s %d %d", m_str, &b_row, &b_col);
//check whether the spelling is correct or not
    if(strcmp(m_str, "matrix") != 0){
        printf("Please check your spelling.\n");
        return;
    }
//setup b
    b = readMatrix(b_row, b_col);

//check if it is an it is possible to multiply matrix
    if((a_row != b_row) || (a_col != b_col)){
        printf("Matrix unable to add.\n");
        return;
    }
//receiver
    result = (double**) malloc(a_row*sizeof(double*));
    for(int i = 0; i < a_row; i++){
        result[i] = (double*) malloc(b_col*sizeof(double));
    }
//add
    for(int i = 0; i < a_row; i++){
        for(int j = 0; j < a_col; j++){
                result[i][j] =a[i][j]+b[i][j];
        }
    }
//print
    printMatrix(a, m_str, a_row, a_col);
    printf("+\n");
    printMatrix(b, m_str, b_row, b_col);
    printf("=\n");
    printMatrix(result, m_str, a_row, b_col);
//free
    for(int i = 0; i < a_row; i++){
        free(a[i]);
    } 
    free(a);
    for(int i = 0; i < b_row; i++){
        free(b[i]);
    } 
    free(b);
    for(int i = 0; i < a_row; i++){
        free(result[i]);
    } 
    free(result);
}

void swap_row(double** m, int row, int col, int tgt, int* r_s_i){
    if(tgt == row){
        return;
    }
    double* tmp;    
    tmp = (double*) malloc(col*sizeof(double));
    
    for(int i = 0; i< col; i++){
        tmp[i] = m[tgt][i];
        m[tgt][i] = m[tgt+1][i];
        m[tgt+1][i] = tmp[i];
    }
    free(tmp);
    *r_s_i = *r_s_i+1;
}