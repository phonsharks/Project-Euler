# Problem 4: Largest Palindrome Product

**Kaynak:** https://projecteuler.net/problem=4

## Problem Metni (orijinal, İngilizce)

> A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
>
> Find the largest palindrome made from the product of two 3-digit numbers.

## Problem Metni (Türkçe Çeviri)

> Bir palindromik sayı, her iki yönden okunduğunda da aynıdır. İki 2 basamaklı sayının çarpımından elde edilen en büyük palindrom, 91 × 99 = 9009'dur.
>
> İki 3 basamaklı sayının çarpımından elde edilen en büyük palindromu bulunuz.

## Kullanılan Algoritma

Çözüm, tüm 3 basamaklı sayı çiftlerini deneyen bir **kaba kuvvet (brute force)** arama kullanır ve her çarpımın palindrom olup olmadığını ayrı bir yardımcı fonksiyonla test eder.

- `main` içinde iki iç içe `for` döngüsü, `number1` ve `number2` değişkenlerini 999'dan 100'e kadar (azalan sırada) dolaştırır ve her kombinasyon için `result = number1 * number2` çarpımı hesaplanır.
- `polindrom(result)` fonksiyonu çağrılarak `result`'ın palindrom olup olmadığı test edilir; eğer palindromsa ve o ana kadar bulunan en büyük değerden (`largest`) büyükse, `largest` güncellenir.
- Tüm çiftler denendikten sonra `largest` ekrana yazdırılır.

`polindrom` fonksiyonunun asıl amacı, sayıyı bir karakter dizisine (`nums[12]`) çevirip diziyi baştan ve sondan karşılaştırarak simetrik olup olmadığını (yani palindrom olup olmadığını) kontrol etmektir; `last = strlen(nums)-1` ile dizinin son geçerli indeksi bulunur, ardından `for(int i=last;i>=0;i--)` döngüsüyle `nums[i]` ile `nums[last-i]` karşılaştırılır, herhangi bir eşleşmezlikte `0` (palindrom değil), döngü sonuna kadar hep eşleşirse `1` (palindrom) döndürülür. Fonksiyonun içinde sayıyı diziye yazan satır `printf("%d",num);` olarak yazılmış (sayıyı doğrudan konsola bastırır); dizinin dolduruşu tipik olarak `sprintf(nums, "%d", num)` ile yapılır. Kod bu haliyle bırakılmıştır ve mantığına dokunulmamıştır.

## Çözüm Dosyası

`Problem4.c`
