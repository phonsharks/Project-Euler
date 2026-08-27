/*
Project Euler Problem 14: Longest Collatz Sequence
Kaynak: https://projecteuler.net/problem=14

Algoritma:
count() fonksiyonu, verilen n için Collatz zincirini doğrudan simüle eder:
n çiftse n/2, tekse 3n+1 uygulanır ve n değeri 1'e ulaşana kadar adımlar
sayılır (memoizasyon yapılmaz, her başlangıç değeri için zincir sıfırdan
hesaplanır). main() içinde 0'dan 999999'a kadar her i için count(i)
hesaplanır; en uzun zinciri veren başlangıç sayısı (m_i) ve o zincirin
uzunluğu (m_c) takip edilerek sonunda en uzun zinciri üreten başlangıç
sayısı yazdırılır.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count(int n){
    int c=0;
    while (n>1){
        n=n%2==0 ? n/2 : 3*n+1;
        c++;
    }
    return c+1;
}


int main(){
    int m_i=0,m_c=0;
    for(int i=0;i<1000000;i++){
        int c=count(i);
        if(c>m_c){
            m_c=c;
            m_i=i;
        }
    }
    /*
    işaretsiz yazdırma için %u kullandım
    (I used %u for unsigned printing)
    */
    printf("%u\n",m_i);

    return 0;
}
