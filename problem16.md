# Problem 16: Power Digit Sum

**Kaynak:** https://projecteuler.net/problem=16

## Problem Metni (orijinal, İngilizce)

> 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
>
> What is the sum of the digits of the number 2^1000?

## Problem Metni (Türkçe Çeviri)

> 2^15 = 32768'dir ve bu sayının basamaklarının toplamı 3 + 2 + 7 + 6 + 8 = 26'dır.
>
> 2^1000 sayısının basamaklarının toplamı kaçtır?

## Kullanılan Algoritma

2^1000 sayısı yaklaşık 302 basamaklıdır ve hiçbir standart C tamsayı türüne (`int`, `long`, `long long`, hatta 64-bit türler) sığmaz. Bu nedenle `problem16.c` çözümünde de **GMP (GNU Multiple Precision Arithmetic Library)** kullanılır:

1. **Büyük üssün hesaplanması:** `mpz_ui_pow_ui(result, 2, 1000)` fonksiyonu, 2'nin 1000. kuvvetini keyfi hassasiyetle, taşma olmadan hesaplar ve sonucu `result` adlı `mpz_t` değişkenine yazar.

2. **Ondalık dizeye dönüştürme:** `mpz_get_str(result_str, 10, result)` ile `result` değeri, 10 tabanında bir karakter dizisine (`result_str`) çevrilir. Bu dizide her karakter, sayının bir basamağının ASCII rakam karşılığıdır (örn. '3', '2', '7' ...).

3. **Basamak toplamı:** `for(int i=0; i<result_str[i]; i++) { sum += result_str[i] - '0'; }` döngüsü ile her karakterin sayısal değeri (`karakter - '0'` ile ASCII rakamdan tam sayıya çevrilerek) `sum` değişkenine eklenir. Kod içindeki yorumda açıklandığı gibi, döngü koşulu olarak `i < result_str[i]` kullanılmıştır; bu, dizenin sonundaki null sonlandırıcı karaktere (ASCII değeri 0) ulaşıldığında `i < 0` durumu oluşup koşulun sağlanamaması ve döngünün doğal olarak durması fikrine dayanır (yazarın kod içi yorumunda "ascii tablosuna göre null yani sıfırda duracağını bildirerek ilerlenebilir" şeklinde belirtilmiştir).

4. **Sonucun yazdırılması ve bellek temizliği:** Toplam `sum`, `printf("%d\n", sum)` ile ekrana yazdırılır; `mpz_clear(result)` ile GMP belleği serbest bırakılır.

Bu yaklaşımda büyük sayının kendisi GMP ile kesin (exact) olarak hesaplandığı için basamaklara ayrıştırma ve toplama adımı, standart string/karakter işleme mantığıyla (ASCII rakam karakterinden `'0'` çıkarma) yürütülür. Zaman karmaşıklığı O(basamak sayısı) = O(302) düzeyindedir, yani ihmal edilebilir derecede hızlıdır.

## Algorithm Used (English)

The number 2^1000 has approximately 302 digits and does not fit into any standard C integer type (`int`, `long`, `long long`, or even 64-bit types). For this reason, the `problem16.c` solution also uses the **GMP (GNU Multiple Precision Arithmetic Library)**:

1. **Computing the large power:** `mpz_ui_pow_ui(result, 2, 1000)` computes 2 raised to the 1000th power with arbitrary precision and without overflow, writing the result into the `mpz_t` variable named `result`.

2. **Converting to a decimal string:** `mpz_get_str(result_str, 10, result)` converts the value of `result` into a base-10 character array (`result_str`). In this array, each character is the ASCII digit corresponding to one digit of the number (e.g. '3', '2', '7', ...).

3. **Summing the digits:** The loop `for(int i=0; i<result_str[i]; i++) { sum += result_str[i] - '0'; }` adds the numeric value of each character (converted from an ASCII digit to an integer via `character - '0'`) into the `sum` variable. As explained in the code's own comment, the loop condition used is `i < result_str[i]`; this relies on the idea that once the string's terminating null character (ASCII value 0) is reached, the condition `i < 0` no longer holds and the loop stops naturally (the author's in-code comment states that "one can proceed knowing it will stop at null, i.e., zero, according to the ASCII table").

4. **Printing the result and memory cleanup:** The total `sum` is printed with `printf("%d\n", sum)`; the GMP memory is freed with `mpz_clear(result)`.

Because the large number itself is computed exactly via GMP in this approach, the digit-extraction and summation step is carried out using ordinary string/character-processing logic (subtracting `'0'` from an ASCII digit character). The time complexity is O(number of digits) = O(302), meaning it runs at a negligibly fast speed.

## Çözüm Dosyası

`problem16.c`
