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

## Çözüm Dosyası

`Problem1.c`
