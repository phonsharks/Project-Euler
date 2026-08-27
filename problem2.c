/*
 * Project Euler Problem 2: Even Fibonacci Numbers
 * Kaynak: https://projecteuler.net/problem=2
 *
 * Algoritma:
 * Fibonacci dizisi num1=1, num2=2 ile başlatılıp yinelemeli olarak
 * (num1,num2 -> num2,num1+num2) 4.000.000'u aşana kadar üretilir.
 * Her üretilen terim çiftse sum'a eklenir; sonunda sum yazdırılır.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum;
    int tmp;
    int num1;
    int num2;
    sum = 0;
    num1= 1;
    num2 = 2;
    while(num2<=4000000){
        if(num2%2==0){
            sum+=num2;
        }
        //burada 1,1,2,3 .. ilk indexlere yönelik başlatma yaptım.
        int tmp = num1 + num2;
		num1 = num2;
		num2 = tmp;
    }
    printf("%d",sum);
    return 0;
}
