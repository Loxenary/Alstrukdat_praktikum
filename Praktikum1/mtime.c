#include "time.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    TIME T1;
    TIME T2;
    TIME TLow;
    TIME Thigh;
    CreateTime(&TLow,23,59,59);
    CreateTime(&Thigh,0,0,0);
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("[%d]\n",i+1);
        BacaTIME(&T1);
        BacaTIME(&T2);
        if(TIMEToDetik(T1) <= TIMEToDetik(T2)){
            printf("%d\n",Durasi(T1,T2));
        }
        else{
            printf("%d\n",Durasi(T2,T1));
        }
        
        if(TIMEToDetik(Thigh) < TIMEToDetik(T1))
        {
            Thigh = T1;
        }
        if(TIMEToDetik(Thigh)< TIMEToDetik(T2)){
            Thigh =T2;
        }
        if(TIMEToDetik(TLow) > TIMEToDetik(T1)){
            TLow = T1;
        }
        if(TIMEToDetik(TLow) > TIMEToDetik(T2)){
            TLow = T2;
        }
    }    
    TulisTIME(TLow);
    printf("\n");
    TulisTIME(Thigh);
    printf("\n");
    return 0;
}