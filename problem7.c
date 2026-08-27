/*
 * Project Euler Problem 7: 10 001st Prime
 * Kaynak: https://projecteuler.net/problem=7
 *
 * Algoritma:
 * prime() fonksiyonu deneme bölmesi (trial division) ile asallık testi yapar:
 * çift sayılar hemen elenir, tek sayılar için sqrt(num)'a kadar yalnızca tek
 * bölenler denenir. main() içinde artan i değerleri tek tek test edilir,
 * asal bulundukça sayaç artırılır ve son bulunan asal (primelast) saklanır;
 * amaç 10001. asal sayıyı bulup yazdırmaktır.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int num){
    if(num==2){
        return 1;
    }
    if(num%2==0){
        return 0;
    }
    
    //burada i=i+2 değğşimi yapacağım
    for(int i=3;i<sqrt(num);i=i+2){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int prime1;
    int primelast;
    int i=1;
    
    while(prime<=10001){
        if(prime(i)){
            prime1++;
            primelast=i;
        }
        i++;
    }
    printf("%i\n",primelast);
    return 0;
}