
/*
Project Euler Problem 15: Lattice Paths
Kaynak: https://projecteuler.net/problem=15

Algoritma:
n×n'lik bir ızgarada sol üstten sağ alta sadece sağa ve aşağı hareketle
gidilen yol sayısı, toplam 2n hareket içinden n tanesinin "sağ" (kalanı
"aşağı") olarak seçilmesi ile aynıdır; yani C(2n, n) kombinasyonuna eşittir.
20×20'lik ızgara için bu değer C(40,20)'dir. Kod, GMP kütüphanesinin
mpz_bin_uiui(result,40,20) fonksiyonu ile bu binom katsayısını doğrudan
(taşma riski olmadan, keyfi hassasiyetle) hesaplar ve mpz_get_str ile
ondalık dizeye çevirip yazdırır.
*/



#include <stdio.h>
#include <math.h>
#include <gmp.h>

int main(){
    mpz_t(result);
    mpz_init(result);
    //kombinasyon hesaplama(combination calcualated)
    mpz_bin_uiui(result,40,20);
    char result_str[1000];
    mpz_get_str(result_str,10,result);
    mpz_clear(result);
    printf("%s\n",result_str);
    return 0;
}
