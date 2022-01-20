#include <stdio.h>
#include <math.h>
#include <sys/timeb.h>

int chk(int a){
    int c = a-1;
    int index = 0;
    while(c > 1){
        if(a%c == 0){
            index++;            
        }
        c--;
    }

    if(index == 0){
        printf("%d\n",a);
        return 1;
    }
    return 0;
}

int main(){
    //Prob.8
    struct timeb beginTime, endTime;
    ftime(&beginTime); 
    //Prob.7
    int a;
    int index;
    int index2 = 0;
    scanf("%d", &a);
    for(int i =2; i<a+1; i++){
        index = chk(i);
        if (index ==1){
            index2++;
        }
    }
    printf("There are %d primes less than or equal %d\n", index2, a);

    // Prob. 8
    ftime(&endTime);
    printf("total time %ldms\n",endTime.time*1000+endTime.millitm-beginTime.time*1000-beginTime.millitm);
    return 0;
}