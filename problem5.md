# Problem 5: Smallest Multiple

**Kaynak:** https://projecteuler.net/problem=5

## Problem Metni (orijinal, İngilizce)

> 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
>
> What is the smallest positive number that is evenly divisible with no remainder by all of the numbers from 1 to 20?

## Problem Metni (Türkçe Çeviri)

> 2520, 1'den 10'a kadar olan sayıların her birine kalansız bölünebilen en küçük sayıdır.
>
> 1'den 20'ye kadar olan sayıların tamamına kalansız (tam olarak) bölünebilen en küçük pozitif sayı nedir?

## Kullanılan Algoritma

Çözüm, **En Küçük Ortak Kat (EKOK/LCM)** kavramını kullanarak, 1'den 20'ye kadar olan sayıların ortak katını kümülatif biçimde hesaplar.

- `gcd(num1, num2)` fonksiyonu, iki sayının en büyük ortak bölenini **kaba kuvvet doğrusal tarama** ile bulur: `i=1`'den başlayarak `i<=num1 && i<=num2` olduğu sürece her `i` için hem `num1 % i == 0` hem de `num2 % i == 0` koşulu sağlanıyorsa `gcd` değişkeni `i`'ye güncellenir; döngü sonunda bulunan en büyük ortak bölen döner (Öklid algoritması değil, doğrudan deneme yöntemi kullanılmıştır).
- `lcm(num1, num2)` fonksiyonu, klasik `(num1 * num2) / gcd(num1, num2)` formülünü uygular.
- `main` içinde `value = 1` ile başlanır ve `for(int i=2;i<=19;i++)` döngüsünde her adımda `value = lcm(value, i)` hesaplanarak kümülatif EKOK büyütülür; yani sırasıyla `lcm(1,2)`, sonucun `lcm(_,3)` ile devamı, ... şeklinde ilerler.
- Döngü sonunda `value` yazdırılır.

Döngünün üst sınırı `i<=19` olarak yazılmıştır, yani 20 sayısı döngüye doğrudan dahil edilmemiştir (problem metni 1'den 20'ye kadar istemektedir). Ancak bu durum sonucu etkilememektedir: 20 = 2² × 5 olup, bu asal çarpanlar zaten 1-19 aralığındaki 16 (2⁴) ve 5 sayılarından gelen katsayılarla EKOK'a dahil edilmiş durumdadır; dolayısıyla `lcm(1..19)` ile `lcm(1..20)` matematiksel olarak eşittir.

## Algorithm Used (English)

The solution uses the concept of the **Least Common Multiple (LCM)**, cumulatively computing the common multiple of the numbers from 1 to 20.

- The function `gcd(num1, num2)` finds the greatest common divisor of two numbers via a **brute-force linear scan**: starting from `i=1` and continuing while `i<=num1 && i<=num2`, for each `i` it checks whether both `num1 % i == 0` and `num2 % i == 0` hold, and if so updates the `gcd` variable to `i`; at the end of the loop, the greatest common divisor found is returned (this uses direct trial, not the Euclidean algorithm).
- The function `lcm(num1, num2)` applies the classic formula `(num1 * num2) / gcd(num1, num2)`.
- In `main`, execution starts with `value = 1`, and in the loop `for(int i=2;i<=19;i++)` the cumulative LCM is grown at each step by computing `value = lcm(value, i)`; that is, it proceeds sequentially through `lcm(1,2)`, then continues the result with `lcm(_,3)`, and so on.
- At the end of the loop, `value` is printed.

The loop's upper bound is written as `i<=19`, meaning the number 20 is not directly included in the loop (the problem statement asks for 1 through 20). However, this does not affect the result: 20 = 2² × 5, and these prime factors are already included in the LCM through the coefficients coming from 16 (2⁴) and 5, both of which lie in the 1-19 range; therefore `lcm(1..19)` and `lcm(1..20)` are mathematically equal.

## Çözüm Dosyası

`problem5.c`
