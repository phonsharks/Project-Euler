# Problem 6: Sum Square Difference

**Kaynak:** https://projecteuler.net/problem=6

## Problem Metni (orijinal, İngilizce)

> The sum of the squares of the first ten natural numbers is,
>
> 1² + 2² + ... + 10² = 385.
>
> The square of the sum of the first ten natural numbers is,
>
> (1 + 2 + ... + 10)² = 55² = 3025.
>
> Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
>
> Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

## Kullanılan Algoritma

Çözüm, tanım gereği doğrudan **tek geçişli kaba kuvvet** hesaplamasıdır; kapalı form formülleri (ör. `n(n+1)/2` ve `n(n+1)(2n+1)/6`) kullanılmamış, iki toplam da döngü içinde birikimli olarak hesaplanmıştır.

- `sum1` (kareler toplamı) ve `sum2` (sayıların toplamı) 0'a ilklendirilir.
- `for(int i=1;i<=100;i++)` döngüsü 1'den 100'e kadar her sayıyı dolaşır; her adımda `sum1 += i*i;` ile o sayının karesi kareler toplamına eklenir, `sum2 += i;` ile sayının kendisi toplam biriktiricisine eklenir.
- Döngü bittikten sonra `sum2 *= sum2;` satırıyla toplamın karesi hesaplanır (yani `(1+2+...+100)²`).
- Son olarak `sum2 - sum1` (toplamın karesi eksi kareler toplamı) yazdırılır; bu problemin istediği farktır.

Döngü içinde ayrıca `printf("%i\n",sum1);` satırı bulunur; bu, `sum1` değerinin her adımda (o adımdaki `i*i` eklenmeden önceki hâliyle) konsola yazdırılması amaçlı bir ek çıktıdır ve nihai sonucu (`sum2-sum1`) etkilemez. Zaman karmaşıklığı O(n)'dir (n = 100), ek bellek kullanımı O(1)'dir.

## Çözüm Dosyası

`problem6.c`
