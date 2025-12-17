"""
Project Euler Problem 17: Number Letter Counts
(https://projecteuler.net/problem=17)

If the numbers 1 to 5 are written out in words: one, two, three, four, five,
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two)
contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is in compliance with British usage.

------------------------------------------------------------

1'den 5'e kadar sayılar kelimelerle yazıldığında: one, two, three, four, five
Toplamda 3 + 3 + 5 + 4 + 4 = 19 harf kullanılır.

1'den 1000'e (one thousand dahil) kadar tüm sayılar kelimelerle yazılsaydı,
toplamda kaç harf kullanılırdı?

NOT: Boşlukları ve tireleri saymayın.
Örnek: 342 (three hundred and forty-two) = 23 harf
       115 (one hundred and fifteen) = 20 harf
"""
# ... alttaki kodun (fonksiyonlar vs.) tamamı aynı kalabilir ...
def number_to_words(n):
    """Bir sayıyı İngilizce kelimelere çevirir (boşluk ve tire olmadan)"""
    
    # Temel sayılar
    ones = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    teens = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 
             'sixteen', 'seventeen', 'eighteen', 'nineteen']
    tens = ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
    
    if n == 0:
        return 'zero'
    if n == 1000:
        return 'onethousand'
    
    words = ''
    
    # Yüzler basamağı
    hundreds = n // 100
    if hundreds > 0:
        words += ones[hundreds] + 'hundred'
        if n % 100 != 0:
            words += 'and'
    
    # Onlar ve birler basamağı
    remainder = n % 100
    if remainder == 0:
        pass
    elif remainder < 10:
        words += ones[remainder]
    elif remainder < 20:
        words += teens[remainder - 10]
    else:
        words += tens[remainder // 10]
        if remainder % 10 != 0:
            words += ones[remainder % 10]
    
    return words

def count_letters(n):
    """Bir sayının kelime karşılığındaki harf sayısını döndürür"""
    return len(number_to_words(n))

# 1'den 1000'e kadar tüm sayıların harf sayılarını topla
total_letters = 0
for i in range(1, 1001):
    total_letters += count_letters(i)

print(f"1'den 1000'e kadar tüm sayıların toplam harf sayısı: {total_letters}")