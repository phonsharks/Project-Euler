/*
 * Project Euler Problem 6: Sum Square Difference
 * Kaynak: https://projecteuler.net/problem=6
 *
 * Algoritma:
 * 1'den 100'e kadar döngüyle hem kareler toplamı (sum1 += i*i) hem
 * de sayıların toplamı (sum2 += i) biriktirilir. Döngü sonunda
 * sum2 karesi alınır ve sum2 - sum1 (toplamın karesi ile kareler
 * toplamı arasındaki fark) yazdırılır.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int sum1=0;
    int sum2=0;
    for(int i=1;i<=100;i++){
        printf("%i\n",sum1);
        sum1+=i*i;
        sum2+=i;
    }
    sum2*=sum2;
    printf("%i\n",sum2-sum1);
    return 0;
}