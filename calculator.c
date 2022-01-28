#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct number{
    double num;
    int start_loc;
    int end_loc;
}Number;

typedef struct operator{
    char optr;
    int loc;
}Operator;

void PrintNumSet(Number* num_set, int num_cnt){
    for(int i = 0; i < num_cnt; i++){
        printf("num_set[%d].num = %f\n", i, num_set[i].num);
        printf("num_set[%d].start_loc = %d\n", i, num_set[i].start_loc);
        printf("num_set[%d].end_loc = %d\n", i, num_set[i].end_loc);
    }
}

void PrintOptrSet(Operator* optr_set, int optr_cnt){
    for(int i = 0; i < optr_cnt; i++){
        printf("optr_set[%d].optr = %c\n", i, optr_set[i].optr);
        printf("optr_set[%d].loc = %d\n", i, optr_set[i].loc);
    }
}

int main(){
    char input[1000] = {'-','1','2','3','+','4','5','6','*','7','8','9','/','7','4','1'};
//    scanf("%s", input);
    char input_forPara[1000];
    strcpy(input_forPara, input);
//find string length
    int str_len = strlen(input);
//find operator and number count
    int optr_cnt = 0;
    for (int i = 1; i < str_len; i++){
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' ){
            optr_cnt++;
        }
    }
    int num_cnt = optr_cnt+1;
//set up operator set
    Operator* optr_set;
    optr_set = (Operator*) malloc(optr_cnt*sizeof(Operator));
    int j =0;
    for(int i = 1; i < str_len; i++){
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            optr_set[j].optr = input[i];
            optr_set[j].loc = i;
            j++;
        }
    }
    PrintOptrSet(optr_set, optr_cnt);
//set up number set
    Number* num_set;
    num_set = (Number*) malloc(num_cnt*sizeof(Number));
    j = 0;
    for(int i = 1; i < str_len; i++){
        if(input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9' || input[i] == '0'){
            num_set[j].start_loc = i;    
        }
        for(int k = i; k < str_len+1; k++){
            if(input[k] == '+' || input[k] == '-' || input[k] == '*' || input[k] == '/' || input[k] == '(' || input[k] == ')' || input[k] == '\0'){
                /*if(k == (str_len-1)){
                    num_set[j].end_loc = k;
                    goto stop;
                }*/
                num_set[j].end_loc = k-1;
                j++;
                i=k;
                break;
            }    
        }
    }
    //stop:
    num_set[0].start_loc = 0;  

    char* divider = "+-*/()";
    char** num_in_str;
    num_in_str = (char**) malloc(num_cnt*sizeof(char*));
    num_in_str[0] = strtok(input, divider);
    for(int i = 1; i < num_cnt; i++){
        num_in_str[i] = strtok(NULL, divider);
    }
    for(int i = 0; i < num_cnt; i++){
        num_set[i].num = atof(num_in_str[i]);
    }

    if(input[0] == '-'){
        num_set[0].num = num_set[0].num*(-1.0);
    }

    PrintNumSet(num_set, num_cnt);
    
    free(optr_set);
    free(num_set);
    free(num_in_str);
    return 0;
}