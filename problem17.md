# Problem 17: Number Letter Counts

**Kaynak:** https://projecteuler.net/problem=17

## Problem Metni (orijinal, İngilizce)

> If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
>
> If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
>
> NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

## Problem Metni (Türkçe Çeviri)

> 1'den 5'e kadar olan sayılar kelimelerle yazılırsa: one, two, three, four, five, toplamda 3 + 3 + 5 + 4 + 4 = 19 harf kullanılmış olur.
>
> 1'den 1000'e (bin dahil) kadar olan tüm sayılar kelimelerle yazılsaydı, toplam kaç harf kullanılırdı?
>
> NOT: Boşlukları veya tireleri saymayın. Örneğin, 342 (three hundred and forty-two) 23 harf içerir ve 115 (one hundred and fifteen) 20 harf içerir. Sayılar yazılırken "and" kullanımı İngiliz kullanımına uygundur.

## Kullanılan Algoritma

`Problem17.py` çözümü, her sayıyı önce İngilizce kelime karşılığına (boşluksuz ve tiresiz olarak) çevirip ardından bu kelimenin karakter uzunluğunu ölçen bir yaklaşım izler:

1. **Sabit kelime listeleri:** `ones` (1-9 arası sayıların kelimeleri, index 0 boş bırakılmış), `teens` (10-19 arası özel isimler: ten, eleven, ..., nineteen) ve `tens` (20, 30, ..., 90'ın onlar basamağı kelimeleri) dizileri tanımlanır.

2. **`number_to_words(n)` fonksiyonu:** Bir sayıyı kelimeye çevirir:
   - `n == 0` özel durumunda `'zero'` döner (asıl toplama döngüsünde kullanılmaz, sadece güvenlik amaçlı).
   - `n == 1000` özel durumunda doğrudan `'onethousand'` döner (problem sadece 1000 dahil olduğu için özel olarak sabitlenmiştir).
   - **Yüzler basamağı:** `hundreds = n // 100` hesaplanır; sıfırdan büyükse `ones[hundreds] + 'hundred'` eklenir. Eğer sayının 100'e tam bölünmeyen bir kalanı varsa (`n % 100 != 0`), İngiliz kullanımına uygun olarak `'and'` bağlacı eklenir (örn. "threehundredand...").
   - **Onlar ve birler basamağı:** `remainder = n % 100` hesaplanır. Kalan 0 ise bir şey eklenmez; 10'dan küçükse `ones[remainder]` kullanılır; 20'den küçükse (10-19 arası) `teens[remainder-10]` kullanılır; aksi halde `tens[remainder//10]` eklenir ve varsa birler basamağı (`remainder % 10`) `ones[]` listesinden eklenir.
   - Tüm parçalar boşluksuz/tiresiz şekilde string birleştirmeyle (`+=`) tek bir kelimede toplanır.

3. **`count_letters(n)` fonksiyonu:** `number_to_words(n)` sonucunun `len()` uzunluğunu döndürür. Kelimeler zaten boşluk ve tire içermeden üretildiği için bu uzunluk doğrudan "harf sayısı" anlamına gelir; problemde istenen "boşluk ve tireleri sayma" kısıtı, üretim aşamasında bu karakterlerin hiç eklenmemesiyle otomatik olarak sağlanır.

4. **Toplama döngüsü:** `for i in range(1, 1001): total_letters += count_letters(i)` ile 1'den 1000'e kadar (1000 dahil) her sayının harf sayısı toplanarak `total_letters` değişkeninde biriktirilir ve sonuç ekrana yazdırılır.

Bu yaklaşımın doğruluğu, İngilizce sayı adlandırma kurallarının (yüzler + "and" + onlar/birler, özel "teens" isimleri) doğrudan koda yansıtılmasından ve boşluk/tire eklenmeden string birleştirme yapılmasından gelir. Zaman karmaşıklığı O(1000) sayı üzerinde sabit işlemler içerdiğinden pratikte anlık sonuç verir.

## Çözüm Dosyası

`Problem17.py`
