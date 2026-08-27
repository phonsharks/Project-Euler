/*
 * Project Euler Problem 3: Largest Prime Factor
 * Kaynak: https://projecteuler.net/problem=3
 *
 * Algoritma:
 * get_prime, 3'ten sqrt(numb)'a kadar tek sayılarla deneme bölmesi
 * yaparak numb'ın en küçük asal çarpanını bulur (bölen yoksa numb
 * asaldır ve kendisi döner). main içindeki döngü bulunan asal
 * çarpanla numb'ı günceller ve tekrar get_prime çağırır.
 */

#include <stdio.h>
#include <math.h>

long int get_prime(long int numb){
    if(numb==2) return numb;
    for(int i = 3 ; i<sqrt(numb);i+=2){
        if(numb % i == 0){
            return i;
        }
    }
    return numb;
}

int main()
{
    long int numb = 600851475143;
    int prime=get_prime(numb);
    while(numb/prime != 1){
        numb = prime;
        prime = get_prime(numb);
    }
    printf("%i\n",prime);
}
