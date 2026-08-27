/*
Project Euler Problem 16: Power Digit Sum
Kaynak: https://projecteuler.net/problem=16

Algoritma:
2^1000 sayısı normal tamsayı türlerine sığmayacak kadar büyük (~302 basamak)
olduğundan, GMP kütüphanesinin mpz_ui_pow_ui(result,2,1000) fonksiyonu ile
keyfi hassasiyetli (arbitrary precision) olarak hesaplanır. Sonuç
mpz_get_str ile ondalık bir karakter dizesine (result_str) dönüştürülür.
Ardından bu dize üzerinde gezilerek her karakterin rakam değeri
(result_str[i] - '0') toplanır; döngü, dizenin sonundaki null sonlandırıcı
karaktere (ASCII değeri 0) ulaşıldığında i < result_str[i] koşulunun
sağlanamamasıyla durur (bu davranış kod içindeki yorumda da açıklanmıştır).
*/



#include <stdio.h>
#include <math.h>
#include <gmp.h>

int main(){
    mpz_t(result);
    mpz_init(result);
    mpz_ui_pow_ui(result,2,1000);
    char result_str[1000];
    mpz_get_str(result_str,10,result);
    mpz_clear(result); 
    int sum=0;
    /*
    Döngü içerisinde ascii tablosuna göre null yani sıfır da duracağını bildirerek
    de ilerlenebilir --> [result_str != '0']
    (
    By declaring that it will stop at null, that is, zero according to the ascii table in the loop
    can also be progressed --> [result_str != '0']
    )
                        |
                        |
                        |
                        V
    */
    for(int i=0;i<result_str[i];i++){
        sum+=result_str[i] - '0';
    }
    printf("%d\n",sum);
    return 0;
}
