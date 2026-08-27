# Problem 15: Lattice Paths

**Kaynak:** https://projecteuler.net/problem=15

## Problem Metni (orijinal, İngilizce)

> Starting in the top left corner of a 2 × 2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
>
> How many such routes are there through a 20 × 20 grid?

## Kullanılan Algoritma

Bu problemin çözümü, ızgara (grid) üzerindeki yol sayma probleminin bir **kombinatorik** özdeşliğe indirgenmesine dayanır: n×n'lik bir ızgarada sol üst köşeden sağ alt köşeye, sadece sağa ve aşağı hareketlerle gidilebilecek toplam yol sayısı, toplam 2n adımdan (n sağ + n aşağı) n tanesinin "sağ" hareket olarak seçilmesiyle aynıdır (kalan n tanesi otomatik olarak "aşağı" olur). Bu da tam olarak binom katsayısı **C(2n, n)** değerine eşittir.

`problem15.c` içindeki uygulama:

1. **Doğrudan binom katsayısı hesaplama:** GMP kütüphanesinin `mpz_bin_uiui(result, 40, 20)` fonksiyonu çağrılır. Bu fonksiyon, C(40, 20) değerini (20×20'lik ızgara için n=20 olduğundan 2n=40) doğrudan ve keyfi hassasiyetle (arbitrary precision) hesaplar. C(40,20) = 137.846.528.820 gibi büyük bir sayı olduğundan ve GMP kullanıldığından, taşma (overflow) riski yoktur.

2. **Sonucun yazdırılması:** Hesaplanan `result` değeri `mpz_get_str(result_str, 10, result)` ile 10 tabanında bir karakter dizisine dönüştürülür ve `printf` ile ekrana yazdırılır.

3. **Bellek temizliği:** `mpz_clear(result)` ile GMP tarafından ayrılan bellek serbest bırakılır.

Bu yaklaşım doğrudan matematiksel formülü (binom katsayısı) kullandığı için hem çok hızlıdır (GMP'nin dahili binom hesaplama algoritması pratikte anlık sonuç verir) hem de dinamik programlama ile ızgarayı hücre hücre doldurmaya (klasik Pascal üçgeni / DP tablosu yaklaşımına) göre çok daha az kod ve bellek gerektirir; zaman karmaşıklığı, kullanılan sayıların basamak sayısına bağlı olarak GMP'nin iç algoritmasınca belirlenir ve bu boyuttaki sayılar için ihmal edilebilir düzeydedir.

## Çözüm Dosyası

`problem15.c`
