# Problem 15: Lattice Paths

**Kaynak:** https://projecteuler.net/problem=15

## Problem Metni (orijinal, İngilizce)

> Starting in the top left corner of a 2 × 2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
>
> How many such routes are there through a 20 × 20 grid?

## Problem Metni (Türkçe Çeviri)

> 2 × 2'lik bir ızgaranın sol üst köşesinden başlayıp, yalnızca sağa ve aşağı hareket ederek, sağ alt köşeye ulaşmanın tam olarak 6 farklı yolu vardır.
>
> 20 × 20'lik bir ızgarada bu şekilde kaç yol vardır?

## Kullanılan Algoritma

Bu problemin çözümü, ızgara (grid) üzerindeki yol sayma probleminin bir **kombinatorik** özdeşliğe indirgenmesine dayanır: n×n'lik bir ızgarada sol üst köşeden sağ alt köşeye, sadece sağa ve aşağı hareketlerle gidilebilecek toplam yol sayısı, toplam 2n adımdan (n sağ + n aşağı) n tanesinin "sağ" hareket olarak seçilmesiyle aynıdır (kalan n tanesi otomatik olarak "aşağı" olur). Bu da tam olarak binom katsayısı **C(2n, n)** değerine eşittir.

`problem15.c` içindeki uygulama:

1. **Doğrudan binom katsayısı hesaplama:** GMP kütüphanesinin `mpz_bin_uiui(result, 40, 20)` fonksiyonu çağrılır. Bu fonksiyon, C(40, 20) değerini (20×20'lik ızgara için n=20 olduğundan 2n=40) doğrudan ve keyfi hassasiyetle (arbitrary precision) hesaplar. C(40,20) = 137.846.528.820 gibi büyük bir sayı olduğundan ve GMP kullanıldığından, taşma (overflow) riski yoktur.

2. **Sonucun yazdırılması:** Hesaplanan `result` değeri `mpz_get_str(result_str, 10, result)` ile 10 tabanında bir karakter dizisine dönüştürülür ve `printf` ile ekrana yazdırılır.

3. **Bellek temizliği:** `mpz_clear(result)` ile GMP tarafından ayrılan bellek serbest bırakılır.

Bu yaklaşım doğrudan matematiksel formülü (binom katsayısı) kullandığı için hem çok hızlıdır (GMP'nin dahili binom hesaplama algoritması pratikte anlık sonuç verir) hem de dinamik programlama ile ızgarayı hücre hücre doldurmaya (klasik Pascal üçgeni / DP tablosu yaklaşımına) göre çok daha az kod ve bellek gerektirir; zaman karmaşıklığı, kullanılan sayıların basamak sayısına bağlı olarak GMP'nin iç algoritmasınca belirlenir ve bu boyuttaki sayılar için ihmal edilebilir düzeydedir.

## Algorithm Used (English)

This problem's solution rests on reducing the path-counting problem on a grid to a **combinatorial** identity: in an n×n grid, the total number of paths from the top-left corner to the bottom-right corner using only rightward and downward moves is the same as choosing, out of a total of 2n steps (n right + n down), which n of them are "right" moves (the remaining n are automatically "down"). This is exactly equal to the binomial coefficient **C(2n, n)**.

The implementation in `problem15.c`:

1. **Direct binomial coefficient computation:** The GMP library function `mpz_bin_uiui(result, 40, 20)` is called. This function computes the value of C(40, 20) directly and with arbitrary precision (since n=20 for a 20×20 grid, giving 2n=40). Because C(40,20) is a large number (137,846,528,820) and GMP is used, there is no risk of overflow.

2. **Printing the result:** The computed `result` value is converted to a base-10 character array via `mpz_get_str(result_str, 10, result)` and printed with `printf`.

3. **Memory cleanup:** The memory allocated by GMP is freed with `mpz_clear(result)`.

Because this approach uses the direct mathematical formula (the binomial coefficient), it is both very fast (GMP's internal binomial-coefficient algorithm produces the result effectively instantaneously in practice) and requires far less code and memory than filling in the grid cell by cell with dynamic programming (the classic Pascal's-triangle / DP-table approach). Its time complexity is determined by GMP's internal algorithm as a function of the digit count of the numbers involved, and is negligible for numbers of this size.

## Çözüm Dosyası

`problem15.c`
