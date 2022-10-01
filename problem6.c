/*
İlk on doğal sayının karelerinin toplamı,
1^2 + 2^2 + ... + 10^2 = 385
İlk on doğal sayının toplamının karesi,
(1 + 2 + ... + 10)^2 = 55^2 = 3025
Dolayısıyla ilk on doğal sayının kareleri toplamı ile toplamın karesi arasındaki fark 3025 - 385 = 2640'tır.
İlk yüz doğal sayının kareleri toplamı ile toplamın karesi arasındaki farkı bulun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int sum1=0;
    int sum2=0;
    for(int i=1;i<=100;i++){
        printf("%i\n",sum1);
        sum1+=i*i;
        sum2+=i;
    }
    sum2*=sum2;
    printf("%i\n",sum2-sum1);
    return 0;
}