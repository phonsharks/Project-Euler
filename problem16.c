
/*2×2'lik bir ızgaranın sol üst köşesinden başlayarak ve sadece sağa ve aşağı doğru hareket edebilerek, sağ alt köşeye giden tam 6 rota vardır.
20×20'lik bir ızgara boyunca böyle kaç rota vardır?
                                    //English
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?
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
