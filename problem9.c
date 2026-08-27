/*
 * Project Euler Problem 9: Special Pythagorean Triplet
 * Kaynak: https://projecteuler.net/problem=9
 *
 * Algoritma:
 * calc(a,b) fonksiyonu sqrt(a^2+b^2) ile c'yi hesaplar. main() içinde iç içe
 * iki döngüyle olası tüm (a,b) çiftleri (brute-force) denenir; her çift için
 * c hesaplanıp a+b+c==1000 şartı kontrol edilir, şart sağlanınca a*b*c
 * çarpımı yazdırılır.
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
