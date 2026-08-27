# Problem 1: Multiples of 3 or 5

**Kaynak:** https://projecteuler.net/problem=1

## Problem Metni (orijinal, İngilizce)

> If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
>
> Find the sum of all the multiples of 3 or 5 below 1000.

## Problem Metni (Türkçe Çeviri)

> 10'dan küçük tüm doğal sayıları listelediğimizde, 3'ün veya 5'in katı olanlar 3, 5, 6 ve 9'dur. Bu katların toplamı 23'tür.
>
> 1000'den küçük 3'ün veya 5'in katı olan tüm sayıların toplamını bulunuz.

## Kullanılan Algoritma

Çözüm, doğrudan **kaba kuvvet (brute force)** yaklaşımıyla yapılmış tek geçişli bir tarama algoritmasıdır.

- `main` içindeki `for(int i=3;i<=1000;i++)` döngüsü, 3'ten başlayarak 1000'e kadar (1000 dahil) her tam sayıyı tek tek dolaşır.
- Her `i` değeri için `if((i%3==0) || (i%5==0))` koşuluyla sayının 3'e veya 5'e tam bölünüp bölünmediği kontrol edilir (mod alma işlemi).
- Koşulu sağlayan her sayı `sum` değişkenine `sum += i;` ile eklenerek toplam biriktirilir.
- Döngü bittiğinde `sum` değeri ekrana yazdırılır.

Bu, ek bir veri yapısı veya matematiksel formül kullanmadan, aday sayı uzayının tamamını (3'ten 1000'e kadar) tarayarak koşulu sağlayanları toplayan doğrusal bir algoritmadır. Zaman karmaşıklığı O(n)'dir (n = 1000), ek bellek kullanımı O(1)'dir.

Dikkat edilmesi gereken iki nokta: döngü sınırı `i<=1000` olduğundan 1000 dahil taranmaktadır (problem metni "1000'in altında" dediği için sınırın 999'da kalması beklenir, ancak 1000 ne 3'e ne de 5'e tam bölündüğü için sonucu etkilemez); ayrıca `sum` değişkeni döngüden önce açıkça 0'a ilklendirilmemiştir.

## Algorithm Used (English)

The solution is a single-pass scanning algorithm implemented as a straightforward **brute force** approach.

- The loop `for(int i=3;i<=1000;i++)` in `main` starts at 3 and walks through every integer up to and including 1000, one at a time.
- For each value of `i`, the condition `if((i%3==0) || (i%5==0))` checks whether the number is evenly divisible by 3 or by 5 (using the modulo operator).
- Every number that satisfies the condition is accumulated into the `sum` variable via `sum += i;`.
- After the loop finishes, the value of `sum` is printed.

This is a linear algorithm that scans the entire candidate range (from 3 to 1000) and sums the numbers that satisfy the condition, without using any additional data structure or mathematical formula. Its time complexity is O(n) (n = 1000), and its auxiliary space usage is O(1).

Two points worth noting: since the loop bound is `i<=1000`, the value 1000 itself is included in the scan (the problem statement says "below 1000," so the bound would be expected to stop at 999, but since 1000 is divisible by neither 3 nor 5, this does not affect the result); also, the `sum` variable is not explicitly initialized to 0 before the loop.

## Çözüm Dosyası

`Problem1.c`
