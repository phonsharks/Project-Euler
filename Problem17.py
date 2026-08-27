"""
Project Euler Problem 17: Number Letter Counts
Kaynak: https://projecteuler.net/problem=17

Algoritma:
number_to_words(n), 1-1000 arasındaki bir sayıyı boşluksuz/tiresiz İngilizce
kelime karşılığına çevirir (ones/teens/tens sabit dizileri ve İngiliz
kullanımına uygun "and" bağlacı ile). count_letters(n) bu kelimenin karakter
uzunluğunu (len) döndürür. Ana döngü, 1'den 1000'e kadar her sayı için
count_letters() sonucunu toplayarak toplam harf sayısını hesaplar.
"""
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