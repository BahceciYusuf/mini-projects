# Telefon Rehberi - Multi Linked List Uygulaması

## 📋 Proje Hakkında

Bu proje, **INF224 Veri Yapıları** dersi kapsamında geliştirilmiş bir telefon rehberi uygulamasıdır. Çoklu bağlı liste (multi linked list) ve çift yönlü bağlı liste (doubly linked list) veri yapıları kullanılarak implement edilmiştir.

## 🏗️ Veri Yapısı

Proje iki temel `struct` yapısı kullanır:

### Person Yapısı
```c
typedef struct Person {
    char name[50];              // Kişinin adı
    struct Person *next;        // Sonraki kişiye pointer
    struct Person *previous;    // Önceki kişiye pointer
    struct Number *numbers;     // Numaralar listesinin başı
} Person;
```

### Number Yapısı
```c
typedef struct Number {
    char typeOfNumber[20];      // Numara türü (ev, cep, iş)
    char number[20];            // Telefon numarası
    struct Number *next;        // Sonraki numaraya pointer
} Number;
```

## ✨ Özellikler

### 1. **addPerson()**
- Kişileri alfabetik sıraya göre listeye ekler
- Yeni eklenen kişinin numara listesi başlangıçta boştur
- Çift yönlü bağlantıları otomatik olarak oluşturur

### 2. **addNumber()**
- Var olan bir kişiye numara ekler
- Numara türünü belirtme imkanı sunar (ev, cep, iş)
- Kişi listede yoksa hata mesajı verir

### 3. **removePerson()**
- Belirtilen kişiyi listeden tamamen siler
- Kişiye ait tüm numaraları bellekten temizler
- Liste bağlantılarını düzgün şekilde günceller

### 4. **removeNumber()**
- Belirtilen kişiden belirli bir numarayı siler
- Numara bulunamazsa hata mesajı verir

### 5. **updatePerson()**
- Kişinin ismini günceller
- Alfabetik sıralamayı otomatik olarak korur
- İsim değişikliği sonrası liste yeniden düzenlenir

### 6. **updateNumber()**
- Var olan bir numarayı yeni numara ile değiştirir
- Numara türü değişmeden kalır

### 7. **search()**
- Belirtilen isimde kişiyi arar
- Alfabetik sıralama sayesinde **optimize edilmiş arama** yapar
- Aranan isimden alfabetik olarak büyük bir isme ulaşıldığında aramayı sonlandırır
- Bulunan kişinin tüm numaralarını görüntüler

### 8. **list()**
- Tüm rehberi ekrana yazdırır
- Her kişi ve ona ait numaralar sıralı şekilde gösterilir

## 🚀 Kullanım

### Derleme
```bash
gcc main.c -o telefon_rehberi
```

### Çalıştırma
```bash
./telefon_rehberi
```

## 📝 Test Senaryosu

`main()` fonksiyonunda kapsamlı test senaryoları bulunmaktadır:

1. ✅ Alfabetik sırayla kişi ekleme
2. ✅ Numaraları ekleme ve hata kontrolü
3. ✅ Optimize edilmiş arama fonksiyonu
4. ✅ Numara güncelleme
5. ✅ Numara silme
6. ✅ Kişi ismi güncelleme (alfabetik sıra korunur)
7. ✅ Kişi silme işlemleri

## 🎯 Önemli Notlar

- **Alfabetik Sıralama**: Tüm kişiler her zaman alfabetik sırada tutulur
- **Bellek Yönetimi**: Silme işlemlerinde tüm ilgili bellek alanları düzgün şekilde temizlenir
- **Çift Yönlü Liste**: Her kişi hem sonraki hem de önceki kişiye referans tutar
- **Optimize Arama**: Alfabetik sıralama sayesinde gereksiz döngülerden kaçınılır

## 🔍 Örnek Çıktı

```
--- TÜM REHBER ---

İsim: Ali
-> home: 02122340001
-> mobile: 05331230001

İsim: Cem
-> Kayıtlı numara yok.

İsim: Emel
-> mobile: 05421230001

İsim: Seda
-> work: 02169870001
```

## 📚 Gereksinimler

- C derleyicisi (GCC önerilir)
- Standard C kütüphaneleri (`stdio.h`, `stdlib.h`, `string.h`)

## 👨‍💻 Geliştirici

Yusuf Bahçeci. 

