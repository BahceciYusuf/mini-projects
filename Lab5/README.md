# 🌳 Lab5 — İkili Arama Ağacı (BST)

Bu projede, `bst1.txt` ve `bst2.txt` dosyalarından sayılar okunarak iki ayrı **Binary Search Tree (BST)** oluşturulur. Program; ilk 10 elemanı farklı dolaşım türlerinde yazdırır, rastgele seçilen bir sayıyı silmeyi dener ve her iki ağaçta arama sürelerini karşılaştırır.

## 🎯 Amaç
- **Okuma**: Dosyalardan sayıların okunup BST'ye eklenmesi
- **Görselleştirme**: İlk 10 elemanın `Inorder`, `Preorder`, `Postorder` sıralarında yazdırılması
- **Güncelleme**: Rastgele seçilen bir sayının ağaçtan silinmesi (varsa)
- **Kıyas**: İki ağaçta aynı değer için arama sürelerinin ölçülmesi ve karşılaştırılması

## 📦 İçerik
- `main.c` → Dosyadan okuma, BST oluşturma, yazdırma, silme ve arama süreleri
- `bst1.txt`, `bst2.txt` → Giriş veri dosyaları
- `trees.c`, `trees.h` → Alternatif/referans BST uygulaması (bu sürümde derlemeye dahil değil)

## ⚙️ Derleme
Projeyi `Lab5` dizini içinde derleyin:

```bash
gcc -O2 -Wall -Wextra main.c -o lab5
```

Not: `main.c` kendi BST fonksiyonlarını içerir; ekstra kaynak eklemeye gerek yoktur.

## ▶️ Çalıştırma
`bst1.txt` ve `bst2.txt` dosyaları `Lab5` dizininde bulunmalıdır.

```bash
./lab5
```

## 🧪 Örnek Çıktı (Özet)
- İlk 10 eleman (Inorder/Preorder/Postorder)
- Rastgele seçilen sayı için silme denemesi
- Aynı sayı için iki ağaçta arama sürelerinin karşılaştırması

## ⏱️ Zaman Ölçümü
Zaman ölçümü için `gettimeofday` kullanılmaktadır. Her iki ağaçta aynı değer için arama yapılır ve süreler karşılaştırılır.

## 🧠 Notlar
- `trees.c`/`trees.h` şu an derlemeye dahil edilmemektedir. Bu dosyaları kullanmak isterseniz, fonksiyon imzalarını ve isimleri tutarlı hale getirmeniz gerekir.
- Büyük veri dosyalarıyla (`bst1.txt`, `bst2.txt`) test edilmiştir.

## 🗺️ Yol Haritası / Geliştirme Fikirleri
- Düğümlere yükseklik ekleyip AVL/Red-Black ağaçlarıyla kıyaslama
- Yazdırma fonksiyonlarına seviye-seviye (level-order) eklemek
- Dosyadan okuma sırasında geçersiz girdilere karşı ek doğrulama


