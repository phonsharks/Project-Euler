# Problem 8: Largest Product in a Series

**Kaynak:** https://projecteuler.net/problem=8

## Problem Metni (orijinal, İngilizce)

> The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
>
> Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

> 73167176531330624919225119674426574742353549123456789...

Sayının tamamı (1000 hane), kodda kullanılan haliyle aşağıdadır:

```
7316717653133062491922511967442657474235534919493496983520312774506326
2395783180169848018694788518438586156078911294949545950173795833195285
3208805511125406987471585238630507156932909632952274430435576689664895
0445244523161731856403098711121722383113622298934233803081353362766142
8280644448664523874930358907296290491560440772390713810515859307960866
7017242712188399879790879227492190169972088809377665727333001053367881
2202354218097512545405947522435258490771167055601360483958644670632441
5722155397536978179778461740649551492908625693219784686224828397224137
5657056057490261407972968652414535100474821663704844031998900088952434
5065854122758866688116427171479924442928230863465674813919123162824586
1786645835912456652947654568284891288314260769004224219022671055626321
1111093705442175069416589604080719840385096245544436298123098787992724
4284909188845801561660979191338754992005240636899125607176060588611646
7109405077541002256983155200055935729725716362695618826704282524836008
23257530420752963450
```

## Problem Metni (Türkçe Çeviri)

> 1000 haneli sayı içindeki, çarpımı en büyük olan dört bitişik hane 9 × 9 × 8 × 9 = 5832'dir.
>
> 1000 haneli sayı içinde, çarpımı en büyük olan on üç bitişik haneyi bulunuz. Bu çarpımın değeri nedir?
>
> (1000 haneli sayının kendisi yukarıdaki İngilizce bölümde verilmiştir.)

## Kullanılan Algoritma

Kod, kayan pencere (sliding window) yöntemiyle çalışan bir brute-force taramasıdır.

- 1000 haneli sayı `digits` adlı bir karakter dizisinde (string) sabit olarak saklanır. `len` değişkeni `strlen(digits)` ile dizinin uzunluğunu tutar ve `window = 13` olarak pencere genişliği sabitlenir.
- Dış döngü `i = 0`'dan `i + window <= len` koşulu sağlandığı sürece ilerler; yani sayı içindeki her olası 13 haneli ardışık pencerenin başlangıç konumu tek tek denenir.
- İç döngü (`j = 0..window-1`), o pencerede yer alan 13 hanenin çarpımını (`product`) hesaplar. Bir hane `0` ise (`d == 0`), `has_zero` bayrağı `1` yapılıp döngü hemen `break` ile sonlandırılır; çünkü çarpımda bir `0` varsa sonuç kesinlikle `0` olacağından bu pencere en büyük çarpım adayı olamaz — bu, gereksiz çarpma işlemlerini önleyen bir erken çıkış (early exit) optimizasyonudur.
- Pencerede `0` yoksa (`has_zero == 0`) ve hesaplanan `product`, o ana kadar bulunan en büyük değerden (`best`) büyükse, `best` güncellenir.
- Tüm pencereler tarandıktan sonra `best` değişkeni, 13 ardışık hanenin verebileceği en büyük çarpım olarak yazdırılır.

Karmaşıklık `O(n * window)` (n ≈ 1000, window = 13) olduğundan, doğrudan her pencereyi tek tek kontrol eden bu basit tarama pratikte çok hızlı çalışır.

## Çözüm Dosyası

`problem8.c`
