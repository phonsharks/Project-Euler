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

## Çözüm Dosyası

`problem16.c`
