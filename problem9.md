# Problem 9: Special Pythagorean Triplet

**Kaynak:** https://projecteuler.net/problem=9

## Problem Metni (orijinal, İngilizce)

> A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a² + b² = c².
>
> For example, 3² + 4² = 9 + 16 = 25 = 5².
>
> There exists exactly one Pythagorean triplet for which a + b + c = 1000.
>
> Find the product abc.

## Problem Metni (Türkçe Çeviri)

> Pisagor üçlüsü, a < b < c olacak şekilde a² + b² = c² eşitliğini sağlayan üç doğal sayıdan oluşan bir kümedir.
>
> Örneğin, 3² + 4² = 9 + 16 = 25 = 5².
>
> a + b + c = 1000 olacak şekilde tam olarak bir Pisagor üçlüsü vardır.
>
> abc çarpımını bulunuz.

## Kullanılan Algoritma

Kod, olası `a` ve `b` değerlerini tek tek deneyen bir brute-force (kaba kuvvet) arama uyguluyor.

- `calc(int a, int b)` fonksiyonu, verilen `a` ve `b` için `sqrt(a*a + b*b)` hesaplayarak Pisagor bağıntısını (`a² + b² = c²`) sağlayacak `c` değerini üretir.
- `main()` içinde iç içe iki döngü kullanılır: dış döngü `i` değişkenini (a rolünde) `0`'dan `100`'e kadar, iç döngü `j` değişkenini (b rolünde) `0`'dan `i`'ye kadar dener. Böylece olası tüm `(a, b)` çiftleri taranır.
- Her `(i, j)` çifti için `k = calc(i, j)` ile karşılık gelen `c` değeri hesaplanır.
- Eğer `i + j + k == 1000` koşulu (yani `a + b + c = 1000` şartı) sağlanıyorsa, üçlünün çarpımı (`i * j * k`, yani `a * b * c`) ekrana yazdırılır.

Yaklaşımın özeti: problemde belirtilen `a + b + c = 1000` kısıtını sağlayan tek Pisagor üçlüsünü bulmak için, olası `a` ve `b` değer çiftlerini sırayla deneyip her seferinde `c`'yi Pisagor bağıntısından türeterek toplam şartını kontrol eden `O(n²)` karmaşıklığında bir arama algoritmasıdır.

## Algorithm Used (English)

The code performs a brute-force search that tries possible `a` and `b` values one by one.

- The function `calc(int a, int b)` computes `sqrt(a*a + b*b)` for the given `a` and `b`, producing the value of `c` that would satisfy the Pythagorean relation (`a² + b² = c²`).
- In `main()`, two nested loops are used: the outer loop tries the variable `i` (playing the role of a) from `0` to `100`, and the inner loop tries the variable `j` (playing the role of b) from `0` to `i`. This way, all possible `(a, b)` pairs are scanned.
- For each `(i, j)` pair, the corresponding `c` value is computed as `k = calc(i, j)`.
- If the condition `i + j + k == 1000` holds (i.e., the constraint `a + b + c = 1000` is satisfied), the product of the triplet (`i * j * k`, i.e., `a * b * c`) is printed to the screen.

Summary of the approach: this is a search algorithm with `O(n²)` complexity that, in order to find the single Pythagorean triplet satisfying the constraint `a + b + c = 1000` given in the problem, tries the possible `a` and `b` value pairs in sequence, deriving `c` from the Pythagorean relation each time and checking the sum condition.

## Çözüm Dosyası

`problem9.c`
