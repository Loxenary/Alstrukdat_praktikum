#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "garis.h"



int main(){
    int b;
    int n;
    int i;
    int hasil = 0;
    GARIS L1;
    POINT P1;
    scanf("%d",&b);
    BacaGARIS(&L1);
    scanf("%d",&n);
    for(i=0;i < n;i++){
        BacaPOINT(&P1);
        if(JarakGARIS(L1,P1) <= b){
            hasil++;
        }
    }   
    printf("%d\n",hasil);
    return 0;
}