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

## Algorithm Used (English)

The solution uses a **brute-force** search that tries every pair of 3-digit numbers, testing whether each product is a palindrome with a separate helper function.

- In `main`, two nested `for` loops walk `number1` and `number2` from 999 down to 100 (in descending order), and for each combination the product `result = number1 * number2` is computed.
- The function `polindrom(result)` is called to test whether `result` is a palindrome; if it is a palindrome and it is greater than the largest value found so far (`largest`), `largest` is updated.
- After all pairs have been tried, `largest` is printed.

The actual purpose of the `polindrom` function is to convert the number into a character array (`nums[12]`) and check whether it is symmetric (i.e., a palindrome) by comparing the array from the front and the back; `last = strlen(nums)-1` finds the last valid index of the array, and then the loop `for(int i=last;i>=0;i--)` compares `nums[i]` with `nums[last-i]`, returning `0` (not a palindrome) on any mismatch, or `1` (palindrome) if all comparisons match through the end of the loop. Inside the function, the line meant to write the number into the array is written as `printf("%d",num);` (which prints the number directly to the console); populating the array is typically done with `sprintf(nums, "%d", num)`. The code has been left as-is, and its logic has not been touched.

## Çözüm Dosyası

`Problem4.c`
