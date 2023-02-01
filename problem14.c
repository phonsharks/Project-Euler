/*
Aşağıdaki yinelemeli dizi pozitif tamsayılar kümesi için tanımlanmıştır:

n → n/2 (n çifttir)
n → 3n + 1 (n tektir)

Yukarıdaki kuralı kullanarak ve 13 ile başlayarak aşağıdaki diziyi oluştururuz:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
Bu dizinin (13'ten başlayıp 1'de biten) 10 terim içerdiği görülebilir. Henüz kanıtlanmamış olmasına rağmen (Collatz Problemi), tüm başlangıç sayılarının 1'de bittiği düşünülmektedir.

Bir milyonun altındaki hangi başlangıç sayısı en uzun zinciri oluşturur?

NOT: Zincir başladıktan sonra terimlerin bir milyonun üzerine çıkmasına izin verilir.

                                    //English
                                    
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), 
it is thought that all starting numbers finish at 1.Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
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
