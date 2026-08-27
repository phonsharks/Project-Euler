# Problem 7: 10 001st Prime

**Kaynak:** https://projecteuler.net/problem=7

## Problem Metni (orijinal, İngilizce)

> By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
>
> What is the 10,001st prime number?

## Problem Metni (Türkçe Çeviri)

> İlk altı asal sayıyı sıralayarak: 2, 3, 5, 7, 11 ve 13, 6. asal sayının 13 olduğunu görebiliriz.
>
> 10.001'inci asal sayı nedir?

## Kullanılan Algoritma

Kod, deneme bölmesi (trial division) yöntemiyle çalışan bir asallık testi ve bu testi kullanan bir sayaç döngüsünden oluşuyor.

- `prime(int num)` fonksiyonu bir sayının asal olup olmadığını test eder:
  - `num == 2` özel durumu doğrudan asal kabul edilir.
  - Çift sayılar (`num % 2 == 0`) hemen elenir (asal değildir).
  - Kalan tek sayılar için, `i = 3`'ten başlayarak `sqrt(num)`'a kadar yalnızca tek sayılarla (`i = i + 2` artışıyla) bölünebilirlik denenir; çift bölenler zaten önceden elendiği için tek bölenlerin kontrol edilmesi yeterlidir. Bölen bulunursa `0` (asal değil), döngü sonuna kadar bölen bulunamazsa `1` (asal) döndürülür.
  - Bu, klasik `O(sqrt(n))` karmaşıklığında bir asallık testidir.
- `main()` içinde `i = 1`'den başlanarak artan tam sayılar `prime(i)` ile test edilir. Bir sayı asal çıktığında `prime1` sayaç değişkeni artırılır ve bulunan asal `primelast` değişkenine yazılır. Döngünün amacı, asal sayaç 10001'e ulaşana kadar (`while(prime <= 10001)` koşuluyla) bu taramayı sürdürmek ve en son bulunan asalı (`primelast`), yani 10001. asal sayıyı, ekrana yazdırmaktır (`printf("%i\n", primelast)`).

Yaklaşımın özeti: sayıları tek tek artan sırada dolaşıp her birine deneme bölmesiyle asallık testi uygulayan, asal sayıldıkça sayaç tutan doğrusal bir tarama (brute-force sayma) algoritmasıdır.

## Algorithm Used (English)

The code consists of a primality test based on trial division, combined with a counting loop that uses this test.

- The function `prime(int num)` tests whether a number is prime:
  - The special case `num == 2` is directly accepted as prime.
  - Even numbers (`num % 2 == 0`) are immediately rejected (not prime).
  - For the remaining odd numbers, divisibility is tested starting from `i = 3` up to `sqrt(num)`, stepping only through odd values (incrementing by `i = i + 2`); since even divisors have already been ruled out, it is sufficient to check only odd divisors. If a divisor is found, `0` (not prime) is returned; if no divisor is found by the end of the loop, `1` (prime) is returned.
  - This is a classic primality test with `O(sqrt(n))` complexity.
- In `main()`, starting from `i = 1`, increasing integers are tested with `prime(i)`. Whenever a number turns out to be prime, the counter variable `prime1` is incremented, and the prime found is written into the variable `primelast`. The purpose of the loop is to keep scanning until the prime counter reaches 10001 (the condition `while(prime <= 10001)`), and then print the last prime found (`primelast`), i.e., the 10001st prime, to the screen (`printf("%i\n", primelast)`).

Summary of the approach: it is a linear scan (brute-force counting) algorithm that walks through numbers one by one in increasing order, applies a trial-division primality test to each one, and keeps a counter as primes are found.

## Çözüm Dosyası

`problem7.c`
