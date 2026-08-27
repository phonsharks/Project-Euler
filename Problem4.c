/*
 * Project Euler Problem 4: Largest Palindrome Product
 * Kaynak: https://projecteuler.net/problem=4
 *
 * Algoritma:
 * 999'dan 100'e kadar tüm 3 basamaklı sayı çiftleri (number1, number2)
 * kaba kuvvetle denenir. Her çarpım polindrom() ile test edilir;
 * palindrom olan ve o ana kadarki en büyükten büyük olan çarpım
 * largest değişkeninde tutulur ve sonunda yazdırılır.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int polindrom(int num){
    //boş değerlendirebilirim
    char nums[12];
    printf("%d",num);
    int last=strlen(nums)-1;
    for(int i=last;i>=0;i--){
        if(nums[i] !=nums[last-i]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int largest=0;
    for(int number1=999;number1>=100;number1--){
        for(int number2=999;number2>=100;number2--){
            int result=number1*number2;
            if(polindrom(result) && result > largest){
                largest=result;
            }
        }
    }
    printf("%i\n",largest);
    return 0;
}
