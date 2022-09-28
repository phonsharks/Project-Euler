/*
Palindromik bir sayı her iki şekilde de aynı şekilde okunur. 
İki basamaklı iki sayının çarpımından yapılan en büyük palindrom 9009 = 91 × 99'dur.
3 basamaklı iki sayının çarpımından oluşan en büyük palindromu bulun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int polindrom(int num){
    //boş değerlendirebilirim
    char nums[12];
    printf("%d",num);
    int last=strlen(nums)-1;
    for(int i=last;i>=0;i--){
        if(nums[i] !=nums[last-i]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int largest=0;
    for(int number1=999;number1>=100;number1--){
        for(int number2=999;number2>=100;number2--){
            int result=number1*number2;
            if(polindrom(result) && result > largest){
                largest=result;
            }
        }
    }
    printf("%i\n",largest);
    return 0;
}
