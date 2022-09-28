/*
10'un altında 3 veya 5'in katı olan tüm doğal sayıları listelersek 3, 5, 6 ve 9 elde ederiz. Bu katların toplamı 23'tür.

1000'in altındaki 3 veya 5'in tüm katlarının toplamını bulun.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int sum;
    for(int i=3;i<=1000;i++){
        if((i%3==0) || (i%5==0)){
            sum+=i;
        }
    }
    printf("%d",sum);
    return 0;
}
