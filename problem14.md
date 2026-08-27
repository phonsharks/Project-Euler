# Problem 14: Longest Collatz Sequence

**Kaynak:** https://projecteuler.net/problem=14

## Problem Metni (orijinal, İngilizce)

> The following iterative sequence is defined for the set of positive integers:
>
> n → n/2 (n is even)
> n → 3n + 1 (n is odd)
>
> Using the rule above and starting with 13, we generate the following sequence: 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1.
>
> It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
>
> Which starting number, under one million, produces the longest chain?
>
> NOTE: Once the chain starts the terms are allowed to go above one million.

## Kullanılan Algoritma

Çözüm, Collatz zincirini her başlangıç değeri için doğrudan (brute-force) simüle eden basit bir yaklaşım kullanır:

1. **`count(int n)` fonksiyonu:** Verilen `n` değeri için Collatz zincirinin uzunluğunu hesaplar. `while(n>1)` döngüsü içinde, `n` çift ise `n = n/2`, tek ise `n = 3*n+1` uygulanır ve her adımda `c` sayacı bir artırılır. Döngü `n` değeri 1'e ulaştığında biter; fonksiyon `c+1` döndürür (son adımdaki `n=1` teriminin de zincire dahil edilmesi için +1 eklenir).

2. **`main()` fonksiyonu:** `i` değişkeni 0'dan 999999'a kadar (yani milyonun altındaki her başlangıç sayısı için) döner. Her `i` için `count(i)` çağrılarak zincir uzunluğu hesaplanır. Eğer bu uzunluk (`c`) şimdiye kadar bulunan en büyük uzunluktan (`m_c`) büyükse, `m_c` ve karşılık gelen başlangıç sayısı `m_i` güncellenir.

3. Döngü bittiğinde `m_i`, milyonun altında en uzun Collatz zincirini üreten başlangıç sayısını tutar ve `printf("%u\n", m_i)` ile yazdırılır.

Bu yaklaşımda **memoizasyon (önbellekleme) kullanılmaz** — her başlangıç sayısı için zincir sıfırdan hesaplanır; daha önce hesaplanmış ara sonuçlar saklanıp tekrar kullanılmaz. Bu, kodu basit ve doğru kılar (Collatz kuralının doğrudan uygulanmasına dayandığı için sonucun doğruluğu tartışmasızdır) fakat zaman karmaşıklığı açısından optimal değildir: yaklaşık O(N × ortalama zincir uzunluğu) işlem yapılır (N = 10^6). NOT'ta belirtildiği gibi, zincir ilerlerken ara değerlerin bir milyonun üzerine çıkmasına izin verilir; kod bunu doğal olarak destekler çünkü `n` değişkeni üzerinde herhangi bir üst sınır kontrolü yapılmaz.

## Çözüm Dosyası

`problem14.c`
