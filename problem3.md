# Problem 3: Largest Prime Factor

**Kaynak:** https://projecteuler.net/problem=3

## Problem Metni (orijinal, İngilizce)

> The prime factors of 13195 are 5, 7, 13 and 29.
>
> What is the largest prime factor of the number 600851475143?

## Kullanılan Algoritma

Çözüm, **deneme bölmesi (trial division)** tabanlı bir asal çarpan bulma yaklaşımı kullanır.

- `get_prime(long int numb)` fonksiyonu, `numb` sayısı 2 ise doğrudan 2'yi döndürür. Aksi halde `i=3`'ten başlayarak `sqrt(numb)`'a kadar yalnızca tek sayılarla (`i+=2`, çift sayılar elenerek) `numb % i == 0` koşulunu test eder ve bulunan ilk böleni döndürür. Bu döndürülen ilk bölen matematiksel olarak her zaman asaldır, çünkü eğer bileşik olsaydı ondan daha küçük bir asal çarpanı önce bulunmuş olurdu. Döngü hiçbir bölen bulamazsa (yani `numb` asalsa), fonksiyon `numb`'ın kendisini döndürür.
- `main` içinde `numb = 600851475143` ile başlanır ve `prime = get_prime(numb)` çağrısıyla bu sayının en küçük asal çarpanı bulunur.
- `while(numb/prime != 1)` döngüsünde `numb = prime;` ataması yapılır (yani `numb`, bulunan asal çarpanın kendisine eşitlenir) ve ardından `prime = get_prime(numb);` ile bu yeni `numb` üzerinde tekrar çarpan aranır. `numb` artık asal bir sayı olduğundan `get_prime` onu değiştirmeden geri döndürür ve döngü koşulu (`numb/prime == 1`) sağlanarak döngü hemen sona erer.
- Son olarak `prime` değişkeni yazdırılır.

Kodun gerçekte izlediği akış budur: `get_prime` fonksiyonu tek başına deneme bölmesiyle doğru şekilde asal çarpan buluyor olsa da, `main` içindeki döngü `numb`'ı bölüm (`numb/prime`) yerine doğrudan bulunan asal çarpana (`prime`) eşitlediği için döngü, sayının kalan kısmını (kofaktörü) tekrar tekrar küçültüp diğer asal çarpanlara ilerlemek yerine tek adımda sonlanır. Bu nedenle programın yazdırdığı değer, 600851475143 sayısının bulunan ilk (en küçük) asal çarpanıdır.

## Çözüm Dosyası

`Problem3.c`
