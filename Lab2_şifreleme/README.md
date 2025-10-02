# 🔐 Stack Tabanlı Şifreleme Uygunluk Kontrolü

Bu proje, `r` uzunluğundaki **eleman blokları** ve `t` uzunluğundaki **token blokları** içeren bir dizinin, verilen **şifreleme protokolüne** uygun olup olmadığını **stack (yığın)** veri yapısı kullanarak kontrol eder.

- **Anahtar**: İlk `r` karakter (ilk eleman bloğu).
- **Kural**:
  - 2. blok → **anahtarın tersi**
  - 3. blok → **anahtarın düz hali**
  - 4. blok → **anahtarın tersi**
  - … şeklinde devam eder (**tek → düz**, **çift → ters**).

---

## 📂 Dosya İçeriği

- `main.c` → Stack implementasyonu, yardımcı fonksiyonlar, uygunluk kontrolü ve `main` fonksiyonu.

---

## ⚙️ Derleme ve Çalıştırma

```bash
# Derleme
gcc -Wall -Wextra -O2 main.c -o sifre_kontrol

# Çalıştırma
./sifre_kontrol

▶️ Örnek Kullanım

Geçerli örnek:
r (eleman boyutu): 3
t (token boyutu): 1
Diziyi giriniz (bosluksuz): 123A321B123C
Sorun yok karakter sayısı uyuşuyor
DOGRU: Yigin sifrelemeye UYGUN.


Geçersiz örnek:
r (eleman boyutu): 3
t (token boyutu): 1
Diziyi giriniz (bosluksuz): 10010011001
Array boyutunda uyuşmazlık var!
HATA: Dizi boyutu (r+t)*N kuralina uymuyor.

