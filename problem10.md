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

## Algorithm Used (English)

The code uses a scanning algorithm that runs each number through a primality test based on trial division and sums up the ones that turn out to be prime (it is not a sieve method).

- The function `prime(int numb)` tests whether a number is prime: the special case `numb == 2` is accepted as prime; even numbers are immediately rejected; for the remaining odd numbers, divisibility is tested in odd steps (`i = i + 2`) from `i = 3` up to `sqrt(numb)`. If a divisor is found, the number is not prime (`0`); if none is found, it is prime (`1`).
- In `main()`, every number from `i = 2` up to `2000000` (two million) is tested with `prime(i)`; every number that turns out to be prime is added to the `sum` variable (`sum += i`).
- Once the loop completes, `sum` is printed as the sum of all prime numbers below two million.

Summary of the approach: since an independent primality test of `O(sqrt(n))` complexity is run for each candidate number and the results are summed in a linear scan, the overall complexity is on the order of approximately `O(n * sqrt(n))` (n = 2,000,000). This is a simpler but slower method that tests each number individually, without using a structure that pre-marks primes such as the Sieve of Eratosthenes.

## Çözüm Dosyası

`problem10.c`
