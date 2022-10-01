/*
İlk altı asal sayıyı listeleyerek: 2, 3, 5, 7, 11 ve 13, 6. asal sayının 13 olduğunu görebiliriz. 
10001. asal sayı kaçtır?
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