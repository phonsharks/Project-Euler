/*
2520, 1'den 10'a kadar olan sayıların her birine kalansız bölünebilen en küçük sayıdır. 
1'den 20'ye kadar olan sayıların tamamına tam bölünebilen en küçük pozitif sayı kaçtır?
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//En büyük ortak bölen buluyoruz
//GCD calculate

int gcd(int num1,int num2){
    int gcd=1;
    for(int i=1;i<=num1 && i<=num2;i++){
        if((num1%i==0) && (num2%i==0)){
            gcd=i;
        }
    }
    return gcd;
}

//En küçük ortak kat buluyoruz
//LCM calculate

int lcm(long int num1,long int num2){
    return(num1*num2)/gcd(num1,num2);
}

int main(){
    int value=1;
    for(int i=2;i<=19;i++){
        value=lcm(value,i);
    }
    printf("%i",value);
    return 0;
}