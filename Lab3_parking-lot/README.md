# 🅸🅽🅵 224 – Veri Yapıları  
## TP3: Stack & Queue – Otopark Sistemi

### 👤 Öğrenci Bilgileri
- **Ad Soyad:** Yusuf Bahçeci  
- **Numara:** 200104004  
- **Ders:** INF 224 – Veri Yapıları  
- **Uygulama:** TP3 (Lab 3)

---

## 📋 Proje Tanımı

Bu ödevde, 4 adet park alanı (stack yapısında) ve 1 adet geçici alan (queue yapısında) bulunan bir **otopark sistemi** simüle edilmiştir.  
Her park alanı yalnızca **arkadan giriş ve çıkışa** izin verir.  
Geçici alan ise **arkadan giriş ve önden çıkış** yapılabilen bir kuyruktur.

Amaç, bir aracın park alanından çıkması durumunda sistemin geri kalan araçları uygun şekilde yeniden yerleştirmesini simüle etmektir.

---

## ⚙️ Program Akışı

1. **create_Area()** → Park alanlarını başlatır (`head = -1`)
2. **create_Temporary()** → Geçici alanı (queue) başlatır
3. **add_car()** → Aracı sırayla 4 park alanına ekler; yer yoksa geçici alana atar
4. **leave()** → Belirtilen alandaki aracın çıkışını sağlar ve diğer araçları uygun yerlere taşır
5. **print_status()** → Park alanlarının ve geçici alanın güncel durumunu ekrana yazar

---

## 🧮 Başlangıç Durumu

- 4 park alanı vardır, her biri **4 araç kapasitelidir**.  
- 3. park alanında **bir boşluk** bulunur.  
- Geçici alan **boştur**.

Program başında sistem bu başlangıç durumuyla oluşturulur ve `print_status()` ile görüntülenir.

---

## 🚗 Simülasyon Senaryosu

1. İlk olarak park alanları aşağıdaki şekilde doldurulur:
   - Area 1 → 101, 102, 103, 104  
   - Area 2 → 201, 202, 203, 204  
   - Area 3 → 301, 302, 303  
   - Area 4 → (boş)

2. Daha sonra **1. alana ilk giren aracın çıkışı** `leave()` fonksiyonuyla gerçekleştirilir.  
   - Üstündeki araçlar geçici olarak diğer alanlara taşınır.  
   - Boşalan yere geçici alandaki araç(lar) alınır.

3. Son durumda sistem `print_status()` fonksiyonuyla tekrar ekrana yazdırılır.

---

## 🧰 Derleme ve Çalıştırma

### Komut satırından:
```bash
gcc 200104004_lab3.c -o lab3
./lab3



-----------------------

# 🚗 Parking Lot Simulation — Stack & Queue (C)

This project simulates a **parking lot system** using fundamental **data structures** in C:  
multiple **stacks** representing parking areas and a **queue** representing a temporary waiting lane.

It was inspired by a university data structures assignment (INF224 – TP3) but fully refactored and documented as a standalone mini-project.

---

## 🧩 Overview

The system models a parking lot that has:
- **4 parking areas**, each represented by a stack (`LIFO`).
- **1 temporary lane**, represented by a queue structure.

Each parking area can hold up to **4 cars**, and the temporary queue stores cars when all areas are full or when rearranging during exits.

When a car leaves, all vehicles behind it must be temporarily moved to other available areas or the queue.  
After the target car leaves, cars are rearranged back into the parking areas according to availability.

---

## 🧠 Concepts & Data Structures

| Structure | Description |
|------------|--------------|
| `stack` | Represents each parking area. Each has a fixed capacity and supports push/pop operations. |
| `queue` | Represents the temporary lane. Used when all areas are full or rearranging cars. |
| `print_status()` | Displays the current content of all areas. |
| `leave()` | Handles the process of removing a car and reorganizing others. |

---

