/*
 * Project Euler Problem 1: Multiples of 3 or 5
 * Kaynak: https://projecteuler.net/problem=1
 *
 * Algoritma:
 * 3'ten 1000'e kadar (kaba kuvvet) her sayı tek tek dolaşılır.
 * Sayı 3'e veya 5'e tam bölünüyorsa (i%3==0 || i%5==0) sum'a eklenir.
 * Döngü bitince biriken toplam yazdırılır.
 */

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
