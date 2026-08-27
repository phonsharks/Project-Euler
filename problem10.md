# Problem 10: Summation of Primes

**Kaynak:** https://projecteuler.net/problem=10

## Problem Metni (orijinal, İngilizce)

> The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
>
> Find the sum of all the primes below two million.

## Problem Metni (Türkçe Çeviri)

> 10'dan küçük asal sayıların toplamı 2 + 3 + 5 + 7 = 17'dir.
>
> İki milyondan küçük tüm asal sayıların toplamını bulunuz.

## Kullanılan Algoritma

Kod, her sayıyı tek tek deneme bölmesi (trial division) ile asallık testinden geçiren ve asal çıkanları toplayan bir tarama algoritması kullanır (elek/sieve yöntemi değildir).

- `prime(int numb)` fonksiyonu bir sayının asal olup olmadığını test eder: `numb == 2` özel durumu asal kabul edilir; çift sayılar hemen elenir; kalan tek sayılar için `i = 3`'ten `sqrt(numb)`'a kadar tek adımlarla (`i = i + 2`) bölünebilirlik denenir. Bölen bulunursa asal değildir (`0`), bulunamazsa asaldır (`1`).
- `main()` içinde `i = 2`'den `2000000`'e (iki milyon) kadar her sayı `prime(i)` ile test edilir; asal çıkan her sayı `sum` değişkenine eklenir (`sum += i`).
- Döngü tamamlandığında `sum`, iki milyonun altındaki tüm asal sayıların toplamı olarak yazdırılır.

Yaklaşımın özeti: her aday sayı için bağımsız olarak `O(sqrt(n))` karmaşıklığında bir asallık testi çalıştırılıp sonuçların toplandığı doğrusal bir tarama olduğundan, toplam karmaşıklık yaklaşık `O(n * sqrt(n))` mertebesindedir (n = 2.000.000). Bu, Eratosthenes eleği gibi önceden asal işaretleyen bir yapı kullanmadan, her sayıyı ayrı ayrı test eden daha basit fakat daha yavaş bir yöntemdir.

## Çözüm Dosyası

`problem10.c`
