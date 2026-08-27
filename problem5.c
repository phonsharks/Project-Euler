/*
 * Project Euler Problem 5: Smallest Multiple
 * Kaynak: https://projecteuler.net/problem=5
 *
 * Algoritma:
 * gcd() iki sayının en büyük ortak bölenini doğrusal taramayla bulur;
 * lcm() = (num1*num2)/gcd(num1,num2) formülünü uygular. main içinde
 * value=1'den başlayarak 2..19 arası her sayı için value=lcm(value,i)
 * ile kümülatif en küçük ortak kat (EKOK) hesaplanır.
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