# Lab5 — İkili Arama Ağacı (BST)

Bu ödevde `bst1.txt` ve `bst2.txt` dosyalarından sayılar okunup iki ayrı Binary Search Tree (BST) oluşturulur. Program, ilk 10 elemanı farklı dolaşım türlerinde yazdırır, rastgele bir sayı için silme denemesi yapar ve her iki ağaçta arama sürelerini karşılaştırır.

## İçerik
- `main.c`: Programın çalışır sürümü. Dosyalardan okuma, BST oluşturma, ilk 10 elemanı yazdırma, silme ve arama sürelerini içerir.
- `bst1.txt`, `bst2.txt`: Giriş veri dosyaları.
- `bst_files/`: Veri/örnek dosyaların olduğu klasör (gerekiyorsa).
- `trees.c`, `trees.h`: Referans/alternatif BST uygulaması (bu sürümde derlemeye dahil edilmiyor).

## Derleme
Projeyi `Lab5` dizini içinde derleyin:

```bash
gcc -O2 -Wall -Wextra main.c -o lab5
```

Not: `main.c` kendi BST fonksiyonlarını içerdiği için ek kaynak eklemeye gerek yoktur.

## Çalıştırma
`bst1.txt` ve `bst2.txt` dosyaları `Lab5` dizininde bulunmalıdır.

```bash
./lab5
```

## Beklenen Çıktı (özet)
- Her iki ağaç için ilk 10 eleman (Inorder/Preorder/Postorder)
- Rastgele seçilen bir sayı için silme denemesi bilgisi
- Aynı sayı için iki ağaçta arama sürelerinin karşılaştırması

## Notlar
- Zaman ölçümü için `gettimeofday` kullanılmaktadır.
- `trees.c`/`trees.h` dosyaları şu an derlemeye dahil edilmemektedir. Bu dosyaları kullanmak isterseniz, fonksiyon imzaları/isimleri ile tutarlılık sağlayacak şekilde güncelleme yapmanız gerekir.


