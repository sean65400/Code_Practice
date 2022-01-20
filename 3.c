#include <stdio.h>

int main(){
    double degree;
    char unit;
    double c, f, k;

    printf("請輸入攝氏(C),華氏(F)或絕對溫度(K),如25C,78F,300K: ");
    scanf("%lf %c", &degree, &unit);
    printf("degree = %f\n", degree);
    printf("unit =%c\n", unit);
    switch(unit){
        case 'C':
            if(degree<-273){
                printf("輸入的溫度小於絕對0度.\n");
            }else{
                f = degree*1.8+32;
                k = degree+273;
                printf("%lfF, %lfK\n", f, k);
            }
            break;
        case 'F':
            c = (degree-32)*5.0/9;
            k = (degree-32)*5.0/9+273;
            if(c<-273){
                printf("輸入的溫度小於絕對0度.\n");
            }else{
                printf("%lfC, %lfK\n", c, k);
            }
            break;
        case 'K':
            if(degree<0){
                printf("輸入的溫度小於絕對0度.\n");            
            }else{
                c = degree-273;
                f = (degree-273)*1.8+32;
                printf("%lfC, %lfF\n", c, f);
            }
            break;
        default:
            printf("請以數字加上CFK的格式輸入.\n");
            break;
    }
    return 0;
}