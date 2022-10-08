/*
10'un altındaki asal sayıların toplamı 2 + 3 + 5 + 7 = 17'dir. 
İki milyonun altındaki tüm asal sayıların toplamını bulun
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//asal sayı bulan fonksiyon kodlamam
//find prime numbers

int prime(int numb){
    if(numb==2)
        return 1;
        
    if(numb%2==0)
        return 0;
        
    for(int i=3;i<sqrt(numb);i=i+2);{
        if(numb%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    long int sum=0;
    for(int i=2;i<2000000;i++){
        if(prime(i)){
            sum+=i;
        }
    }
    printf("%li\n",sum);
    return 0;
}
