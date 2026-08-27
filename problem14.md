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

## Problem Metni (Türkçe Çeviri)

> Pozitif tam sayılar kümesi için aşağıdaki yinelemeli (iteratif) dizi tanımlanır:
>
> n → n/2 (n çift ise)
> n → 3n + 1 (n tek ise)
>
> Yukarıdaki kuralı kullanarak 13'ten başlarsak şu diziyi elde ederiz: 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1.
>
> Görüldüğü gibi bu dizi (13'te başlayıp 1'de biten) 10 terimden oluşur. Henüz kanıtlanmamış olsa da (Collatz Problemi), tüm başlangıç sayılarının sonunda 1'e ulaştığı düşünülmektedir.
>
> Bir milyonun altındaki hangi başlangıç sayısı en uzun zinciri üretir?
>
> NOT: Zincir bir kez başladıktan sonra terimlerin bir milyonun üzerine çıkmasına izin verilir.

## Kullanılan Algoritma

Çözüm, Collatz zincirini her başlangıç değeri için doğrudan (brute-force) simüle eden basit bir yaklaşım kullanır:

1. **`count(int n)` fonksiyonu:** Verilen `n` değeri için Collatz zincirinin uzunluğunu hesaplar. `while(n>1)` döngüsü içinde, `n` çift ise `n = n/2`, tek ise `n = 3*n+1` uygulanır ve her adımda `c` sayacı bir artırılır. Döngü `n` değeri 1'e ulaştığında biter; fonksiyon `c+1` döndürür (son adımdaki `n=1` teriminin de zincire dahil edilmesi için +1 eklenir).

2. **`main()` fonksiyonu:** `i` değişkeni 0'dan 999999'a kadar (yani milyonun altındaki her başlangıç sayısı için) döner. Her `i` için `count(i)` çağrılarak zincir uzunluğu hesaplanır. Eğer bu uzunluk (`c`) şimdiye kadar bulunan en büyük uzunluktan (`m_c`) büyükse, `m_c` ve karşılık gelen başlangıç sayısı `m_i` güncellenir.

3. Döngü bittiğinde `m_i`, milyonun altında en uzun Collatz zincirini üreten başlangıç sayısını tutar ve `printf("%u\n", m_i)` ile yazdırılır.

Bu yaklaşımda **memoizasyon (önbellekleme) kullanılmaz** — her başlangıç sayısı için zincir sıfırdan hesaplanır; daha önce hesaplanmış ara sonuçlar saklanıp tekrar kullanılmaz. Bu, kodu basit ve doğru kılar (Collatz kuralının doğrudan uygulanmasına dayandığı için sonucun doğruluğu tartışmasızdır) fakat zaman karmaşıklığı açısından optimal değildir: yaklaşık O(N × ortalama zincir uzunluğu) işlem yapılır (N = 10^6). NOT'ta belirtildiği gibi, zincir ilerlerken ara değerlerin bir milyonun üzerine çıkmasına izin verilir; kod bunu doğal olarak destekler çünkü `n` değişkeni üzerinde herhangi bir üst sınır kontrolü yapılmaz.

## Algorithm Used (English)

The solution uses a straightforward, brute-force approach that directly simulates the Collatz sequence for every starting value:

1. **`count(int n)` function:** Computes the length of the Collatz sequence for the given value `n`. Inside a `while(n>1)` loop, `n = n/2` is applied when `n` is even and `n = 3*n+1` when `n` is odd, with the counter `c` incremented by one at every step. The loop ends once `n` reaches 1; the function returns `c+1` (the extra +1 accounts for including the final `n=1` term in the sequence).

2. **`main()` function:** The variable `i` iterates from 0 to 999999 (i.e., every starting number below one million). For each `i`, `count(i)` is called to compute the chain length. If this length (`c`) is greater than the largest length found so far (`m_c`), both `m_c` and the corresponding starting number `m_i` are updated.

3. Once the loop finishes, `m_i` holds the starting number below one million that produces the longest Collatz chain, and it is printed with `printf("%u\n", m_i)`.

This approach does **not use memoization (caching)** — the chain is recomputed from scratch for every starting number, with no previously computed intermediate results stored or reused. This keeps the code simple and its correctness beyond question (since it relies on directly applying the Collatz rule), but it is not optimal in terms of time complexity: it performs roughly O(N × average chain length) operations (N = 10^6). As noted in the problem statement, intermediate terms are allowed to exceed one million once the chain has started; the code naturally supports this since no upper-bound check is ever applied to the `n` variable.

## Çözüm Dosyası

`problem14.c`
