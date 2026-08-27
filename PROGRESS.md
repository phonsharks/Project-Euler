# Project Euler — İlerleme Takibi

Kaynak: [projecteuler.net/archives](https://projecteuler.net/archives) — toplam 997 problem, 20 sayfa (50'şer problem).

## Strateji

1. 1-17 arasındaki boşluklar (8, 11, 12) dolduruldu.
2. Sırada: 18-50 arası, klasik teknikleri (DP, permütasyon, büyük Fibonacci, vb.) kapsayan "temel seviye" problemler.
3. 50'den sonra strict sıralı gitmek yerine, PE sitesindeki zorluk yüzdesine göre seçici ilerleme.
4. Dil seçimi duruma göre: performans/brute-force ağırlıklı problemlerde **C** (gerektiğinde GMP ile büyük sayı desteği), büyük sayı/string/kombinatorik ağırlıklı problemlerde **Python**.

## Durum Tablosu (1-50)

| # | Başlık | Dil | Durum | Tarih |
|---|--------|-----|-------|-------|
| 1 | Multiples of 3 or 5 | C | ✅ Çözüldü | 2025-09-28 |
| 2 | Even Fibonacci Numbers | C | ✅ Çözüldü | 2025-09-28 |
| 3 | Largest Prime Factor | C | ✅ Çözüldü | 2025-09-28 |
| 4 | Largest Palindrome Product | C | ✅ Çözüldü | 2025-09-28 |
| 5 | Smallest Multiple | C | ✅ Çözüldü | 2025-10-01 |
| 6 | Sum Square Difference | C | ✅ Çözüldü | 2025-10-01 |
| 7 | 10001st Prime | C | ✅ Çözüldü | 2025-10-01 |
| 8 | Largest Product in a Series | C | ✅ Çözüldü | 2026-08-28 |
| 9 | Special Pythagorean Triplet | C | ✅ Çözüldü | 2025-10-08 |
| 10 | Summation of Primes | C | ✅ Çözüldü | 2025-10-08 |
| 11 | Largest Product in a Grid | C | ✅ Çözüldü | 2026-08-28 |
| 12 | Highly Divisible Triangular Number | C | ✅ Çözüldü | 2026-08-28 |
| 13 | Large Sum | C (GMP) | ✅ Çözüldü | 2026-01-31 |
| 14 | Longest Collatz Sequence | C | ✅ Çözüldü | 2026-02-01 |
| 15 | Lattice Paths | C | ✅ Çözüldü | 2026-02-04 |
| 16 | Power Digit Sum | C | ✅ Çözüldü | 2026-02-04 |
| 17 | Number Letter Counts | Python | ✅ Çözüldü | 2025-12-17 |
| 18 | Maximum Path Sum I | — | ⏳ Beklemede | |
| 19 | Counting Sundays | — | ⏳ Beklemede | |
| 20 | Factorial Digit Sum | — | ⏳ Beklemede | |
| 21 | Amicable Numbers | — | ⏳ Beklemede | |
| 22 | Names Scores | — | ⏳ Beklemede | |
| 23 | Non-Abundant Sums | — | ⏳ Beklemede | |
| 24 | Lexicographic Permutations | — | ⏳ Beklemede | |
| 25 | 1000-digit Fibonacci Number | — | ⏳ Beklemede | |
| 26 | Reciprocal Cycles | — | ⏳ Beklemede | |
| 27 | Quadratic Primes | — | ⏳ Beklemede | |
| 28 | Number Spiral Diagonals | — | ⏳ Beklemede | |
| 29 | Distinct Powers | — | ⏳ Beklemede | |
| 30 | Digit Fifth Powers | — | ⏳ Beklemede | |
| 31 | Coin Sums | — | ⏳ Beklemede | |
| 32 | Pandigital Products | — | ⏳ Beklemede | |
| 33 | Digit Cancelling Fractions | — | ⏳ Beklemede | |
| 34 | Digit Factorials | — | ⏳ Beklemede | |
| 35 | Circular Primes | — | ⏳ Beklemede | |
| 36 | Double-base Palindromes | — | ⏳ Beklemede | |
| 37 | Truncatable Primes | — | ⏳ Beklemede | |
| 38 | Pandigital Multiples | — | ⏳ Beklemede | |
| 39 | Integer Right Triangles | — | ⏳ Beklemede | |
| 40 | Champernowne's Constant | — | ⏳ Beklemede | |
| 41 | Pandigital Prime | — | ⏳ Beklemede | |
| 42 | Coded Triangle Numbers | — | ⏳ Beklemede | |
| 43 | Sub-string Divisibility | — | ⏳ Beklemede | |
| 44 | Pentagon Numbers | — | ⏳ Beklemede | |
| 45 | Triangular, Pentagonal, and Hexagonal | — | ⏳ Beklemede | |
| 46 | Goldbach's Other Conjecture | — | ⏳ Beklemede | |
| 47 | Distinct Primes Factors | — | ⏳ Beklemede | |
| 48 | Self Powers | — | ⏳ Beklemede | |
| 49 | Prime Permutations | — | ⏳ Beklemede | |
| 50 | Consecutive Prime Sum | — | ⏳ Beklemede | |

**Not:** 1-17 arası tarihler, git commit geçmişinden alınmıştır; 5-7 arası ve 9-10 arası commit'ler aynı gün gruplanmış olabilir. 8, 11, 12 için önceden (2022) yarım kalmış bir problem8.c denemesi vardı, `git log` geçmişinde revert edilmiş halde duruyor; bu sefer sıfırdan ve test edilmiş şekilde yazıldı.

51'den 997'ye kadar olan problemler ilerledikçe bu tabloya yeni bölümler halinde eklenecek.
