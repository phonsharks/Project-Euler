
/*
2×2'lik bir ızgaranın sol üst köşesinden başlayarak ve sadece sağa ve aşağı doğru hareket edebilerek, sağ alt köşeye giden tam 6 rota vardır.
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
    //kombinasyon hesaplama(combination calcualated)
    mpz_bin_uiui(result,40,20);
    char result_str[1000];
    mpz_get_str(result_str,10,result);
    mpz_clear(result);
    printf("%s\n",result_str);
    return 0;
}
