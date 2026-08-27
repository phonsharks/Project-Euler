# Problem 11: Largest Product in a Grid

**Kaynak:** https://projecteuler.net/problem=11

## Problem Metni (orijinal, İngilizce)

> In the 20 × 20 grid below, four numbers along a diagonal line have been marked in red.
>
> The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
>
> What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20 × 20 grid?

20×20 tablo:

```
08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
```

## Problem Metni (Türkçe Çeviri)

> Aşağıdaki 20 × 20'lik tabloda, bir köşegen doğrultusundaki dört sayı kırmızı ile işaretlenmiştir.
>
> Bu sayıların çarpımı 26 × 63 × 78 × 14 = 1788696'dır.
>
> 20 × 20'lik tabloda aynı yönde (yukarı, aşağı, sol, sağ veya çapraz) bitişik dört sayının verebileceği en büyük çarpım nedir?
>
> (20 × 20'lik tablo yukarıdaki İngilizce bölümde verilmiştir.)

## Kullanılan Algoritma

Kod, tabloyu baştan sona tarayan tam (exhaustive) bir brute-force arama uyguluyor.

- `grid[SIZE][SIZE]` (`SIZE = 20`) dizisi, problemde verilen tablonun tamamını sabit değerler olarak içerir.
- `directions[4][2]` dizisi dört yön vektörü tanımlar: sağ `(0, 1)`, aşağı `(1, 0)`, çapraz aşağı-sağ `(1, 1)` ve çapraz aşağı-sol `(1, -1)`. Yukarı ve sol yönler ayrıca tanımlanmamıştır; çünkü döngü tablonun her hücresinden başlayarak taradığından, örneğin bir hücreden "sağa" doğru dörtlü bir grup aranırken, o grubun soldaki bitiş noktasından "sola" doğru aranmasıyla aynı grup zaten başka bir başlangıç noktasında (sağdaki hücreden `-1` yönünde değil, soldaki hücreden `+1` yönünde) taranmış olur. Yani tüm hücrelerin taranması, dört yönün simetriği olan diğer dört yönü (sol, yukarı, çapraz yukarı-sol, çapraz yukarı-sağ) de kapsar.
- Üç iç içe döngü: `row` ve `col` tablodaki her başlangıç hücresini, `d` ise dört yönden birini seçer. `dr, dc` o yönün satır/sütun artışlarını verir.
- Seçilen yönde 4 hücre ilerlendiğinde varılacak bitiş hücresi (`endRow`, `endCol`) önceden hesaplanır; bu hücre tablo sınırlarının dışına taşıyorsa (`endRow`/`endCol` `0`'dan küçük ya da `SIZE`'dan büyük/eşit), o yön/başlangıç kombinasyonu atlanır (`continue`).
- Sınırlar içindeyse, `k = 0..3` döngüsüyle `grid[row + k*dr][col + k*dc]` hücrelerinin çarpımı (`product`) hesaplanır.
- Bulunan `product`, o ana kadarki en büyük değeri (`best`) aşıyorsa `best` güncellenir.
- Tüm başlangıç noktaları ve yönler denendikten sonra `best`, tablodaki herhangi bir yönde (yatay, dikey veya iki çapraz) 4 bitişik sayının verebileceği en büyük çarpım olarak yazdırılır.

Tablo boyutu sabit (`20x20`) ve yön sayısı sabit (`4`) olduğundan, karmaşıklık `O(SIZE² * 4 * 4)` gibi sabit ve küçük bir sayıdır; bu da tam taramanın pratikte anında sonuç vermesini sağlar.

## Algorithm Used (English)

The code performs an exhaustive brute-force search that scans the entire grid from start to end.

- The array `grid[SIZE][SIZE]` (`SIZE = 20`) holds the entire table given in the problem as constant values.
- The array `directions[4][2]` defines four direction vectors: right `(0, 1)`, down `(1, 0)`, diagonal down-right `(1, 1)`, and diagonal down-left `(1, -1)`. The up and left directions are not separately defined, because since the loop scans starting from every cell of the grid, a group of four sought "to the right" from one cell, for example, is already scanned from another starting point — namely from the left cell in the `+1` direction, rather than from the right cell in the `-1` direction — for that same group. In other words, scanning all cells also covers the four directions symmetric to these four (left, up, diagonal up-left, and diagonal up-right).
- Three nested loops: `row` and `col` select each starting cell in the grid, while `d` selects one of the four directions. `dr, dc` give the row/column increments for that direction.
- The end cell (`endRow`, `endCol`) reached after moving 4 cells in the chosen direction is computed in advance; if this cell falls outside the grid boundaries (`endRow`/`endCol` less than `0` or greater than/equal to `SIZE`), that direction/starting-point combination is skipped (`continue`).
- If it is within bounds, the loop `k = 0..3` computes the product (`product`) of the cells `grid[row + k*dr][col + k*dc]`.
- If the resulting `product` exceeds the largest value found so far (`best`), `best` is updated.
- After all starting points and directions have been tried, `best` is printed as the greatest product obtainable from 4 adjacent numbers in any direction (horizontal, vertical, or either diagonal) in the grid.

Since the grid size is fixed (`20x20`) and the number of directions is fixed (`4`), the complexity is a fixed and small quantity like `O(SIZE² * 4 * 4)`, which allows this exhaustive scan to give an answer essentially instantly in practice.

## Çözüm Dosyası

`problem11.c`
