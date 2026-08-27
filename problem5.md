# Problem 5: Smallest Multiple

**Kaynak:** https://projecteuler.net/problem=5

## Problem Metni (orijinal, İngilizce)

> 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
>
> What is the smallest positive number that is evenly divisible with no remainder by all of the numbers from 1 to 20?

## Kullanılan Algoritma

Çözüm, **En Küçük Ortak Kat (EKOK/LCM)** kavramını kullanarak, 1'den 20'ye kadar olan sayıların ortak katını kümülatif biçimde hesaplar.

- `gcd(num1, num2)` fonksiyonu, iki sayının en büyük ortak bölenini **kaba kuvvet doğrusal tarama** ile bulur: `i=1`'den başlayarak `i<=num1 && i<=num2` olduğu sürece her `i` için hem `num1 % i == 0` hem de `num2 % i == 0` koşulu sağlanıyorsa `gcd` değişkeni `i`'ye güncellenir; döngü sonunda bulunan en büyük ortak bölen döner (Öklid algoritması değil, doğrudan deneme yöntemi kullanılmıştır).
- `lcm(num1, num2)` fonksiyonu, klasik `(num1 * num2) / gcd(num1, num2)` formülünü uygular.
- `main` içinde `value = 1` ile başlanır ve `for(int i=2;i<=19;i++)` döngüsünde her adımda `value = lcm(value, i)` hesaplanarak kümülatif EKOK büyütülür; yani sırasıyla `lcm(1,2)`, sonucun `lcm(_,3)` ile devamı, ... şeklinde ilerler.
- Döngü sonunda `value` yazdırılır.

Döngünün üst sınırı `i<=19` olarak yazılmıştır, yani 20 sayısı döngüye doğrudan dahil edilmemiştir (problem metni 1'den 20'ye kadar istemektedir). Ancak bu durum sonucu etkilememektedir: 20 = 2² × 5 olup, bu asal çarpanlar zaten 1-19 aralığındaki 16 (2⁴) ve 5 sayılarından gelen katsayılarla EKOK'a dahil edilmiş durumdadır; dolayısıyla `lcm(1..19)` ile `lcm(1..20)` matematiksel olarak eşittir.

## Çözüm Dosyası

`problem5.c`
