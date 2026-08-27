# Problem 3: Largest Prime Factor

**Kaynak:** https://projecteuler.net/problem=3

## Problem Metni (orijinal, İngilizce)

> The prime factors of 13195 are 5, 7, 13 and 29.
>
> What is the largest prime factor of the number 600851475143?

## Problem Metni (Türkçe Çeviri)

> 13195 sayısının asal çarpanları 5, 7, 13 ve 29'dur.
>
> 600851475143 sayısının en büyük asal çarpanı nedir?

## Kullanılan Algoritma

Çözüm, **deneme bölmesi (trial division)** tabanlı bir asal çarpan bulma yaklaşımı kullanır.

- `get_prime(long int numb)` fonksiyonu, `numb` sayısı 2 ise doğrudan 2'yi döndürür. Aksi halde `i=3`'ten başlayarak `sqrt(numb)`'a kadar yalnızca tek sayılarla (`i+=2`, çift sayılar elenerek) `numb % i == 0` koşulunu test eder ve bulunan ilk böleni döndürür. Bu döndürülen ilk bölen matematiksel olarak her zaman asaldır, çünkü eğer bileşik olsaydı ondan daha küçük bir asal çarpanı önce bulunmuş olurdu. Döngü hiçbir bölen bulamazsa (yani `numb` asalsa), fonksiyon `numb`'ın kendisini döndürür.
- `main` içinde `numb = 600851475143` ile başlanır ve `prime = get_prime(numb)` çağrısıyla bu sayının en küçük asal çarpanı bulunur.
- `while(numb/prime != 1)` döngüsünde `numb = prime;` ataması yapılır (yani `numb`, bulunan asal çarpanın kendisine eşitlenir) ve ardından `prime = get_prime(numb);` ile bu yeni `numb` üzerinde tekrar çarpan aranır. `numb` artık asal bir sayı olduğundan `get_prime` onu değiştirmeden geri döndürür ve döngü koşulu (`numb/prime == 1`) sağlanarak döngü hemen sona erer.
- Son olarak `prime` değişkeni yazdırılır.

Kodun gerçekte izlediği akış budur: `get_prime` fonksiyonu tek başına deneme bölmesiyle doğru şekilde asal çarpan buluyor olsa da, `main` içindeki döngü `numb`'ı bölüm (`numb/prime`) yerine doğrudan bulunan asal çarpana (`prime`) eşitlediği için döngü, sayının kalan kısmını (kofaktörü) tekrar tekrar küçültüp diğer asal çarpanlara ilerlemek yerine tek adımda sonlanır. Bu nedenle programın yazdırdığı değer, 600851475143 sayısının bulunan ilk (en küçük) asal çarpanıdır.

## Algorithm Used (English)

The solution uses a **trial division**-based approach to find prime factors.

- The function `get_prime(long int numb)` returns 2 directly if `numb` equals 2. Otherwise, starting from `i=3` and going up to `sqrt(numb)`, it tests only odd numbers (`i+=2`, skipping even numbers) against the condition `numb % i == 0` and returns the first divisor found. This first divisor returned is always mathematically prime, because if it were composite, a smaller prime factor of it would have been found first. If the loop finds no divisor (i.e., `numb` is prime), the function returns `numb` itself.
- In `main`, execution starts with `numb = 600851475143`, and the call `prime = get_prime(numb)` finds the smallest prime factor of this number.
- In the loop `while(numb/prime != 1)`, the assignment `numb = prime;` is performed (i.e., `numb` is set equal to the prime factor just found), and then `prime = get_prime(numb);` searches for a factor again on this new `numb`. Since `numb` is now a prime number, `get_prime` returns it unchanged, the loop condition (`numb/prime == 1`) is satisfied, and the loop terminates immediately.
- Finally, the `prime` variable is printed.

This is the flow the code actually follows: although the `get_prime` function on its own correctly finds prime factors via trial division, because the loop in `main` sets `numb` equal directly to the found prime factor (`prime`) instead of to the quotient (`numb/prime`), the loop terminates in a single step instead of repeatedly shrinking the number's remaining part (its cofactor) and progressing to the other prime factors. As a result, the value the program prints is the first (smallest) prime factor found of 600851475143.

## Çözüm Dosyası

`Problem3.c`
