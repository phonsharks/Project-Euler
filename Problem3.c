/*
13195'in asal çarpanları 5, 7, 13 ve 29'dur.

600851475143 sayısının en büyük asal çarpanı kaçtır?
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
