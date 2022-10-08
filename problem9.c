/*
Bir Pisagor üçlüsü, a < b < c olmak üzere üç doğal sayı kümesidir. a^2 + b^2 = c^2
Örneğin, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
a + b + c = 1000 olan tam olarak bir Pisagor üçlüsü vardır. abc durumunu bulun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calc(int a,int b){
    return sqrt((a*a)+(b*b));
}


//ilgili şartara göre kodlama
//coding according to relevant conditions
int main(){
    for(int i=0;i<=100;i<i++){
        for(int j=0;j<i;j++){
            float k=calc(i,j);
            if(i+j+k==1000){
                printf("%i\n",(i*j*k));
            }
        }
    }
    return 0;
}
