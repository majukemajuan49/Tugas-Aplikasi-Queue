# 🏦 Simulasi Antrean Layanan Loket

> Tugas Kelompok – Mata Kuliah Struktur Data  
> Semester 3 | Universitas Diponegoro

---

## 📋 Deskripsi

Program **AntreanLayanan** adalah simulasi sistem antrean pelayanan loket berbasis teks yang diimplementasikan dalam bahasa C. Program ini mensimulasikan alur pengunjung yang masuk ke antrean sesuai jenis layanan, kemudian dilayani oleh loket-loket yang tersedia secara per-ronde (time-step).

---

## 🗂️ Struktur File

```
Queue/
├── boolean.h        # Tipe data boolean (true/false)
├── Pengunjung.h     # ADT Pengunjung – header
├── Pengunjung.c     # ADT Pengunjung – implementasi
├── QueueP.h         # ADT Queue of Pengunjung – header
├── QueueP.c         # ADT Queue of Pengunjung – implementasi
├── Loket.h          # ADT Loket – header
├── Loket.c          # ADT Loket – implementasi
├── Core.h           # Logika simulasi – header
├── Core.c           # Logika simulasi – implementasi
├── main.c           # Program utama & skenario uji
└── res.txt          # Contoh output hasil running
```

---

## 🧩 Arsitektur ADT

### `Pengunjung`
Merepresentasikan satu pengunjung dengan atribut:
- `id` – nomor unik pengunjung
- `nama` – nama pengunjung (maks. 50 karakter)
- `layanan` – kode jenis layanan (`'A'`, `'B'`, `'I'`, `'P'`)

### `QueueP` *(Queue of Pengunjung)*
Antrean berbasis array linear dengan kapasitas **10 elemen**. Operasi utama:
- `CreateQueue`, `Enqueue`, `Dequeue`
- `IsEmptyQueue`, `IsFullQueue`, `SizeQueue`
- `InfoHead`, `InfoTail`, `PrintQueueP`, `ViewQueue`

### `Loket`
Merepresentasikan satu loket pelayanan:
- Mendukung hingga **2 jenis layanan**
- Menyimpan **pengunjung aktif** (sedang dilayani)
- Menyimpan **riwayat** pengunjung yang sudah dilayani (maks. 10)
- Operasi: `MakeLoket`, `MulaiMelayani`, `SelesaiMelayani`, `BisaMelayani`, `IsLoketKosong`

### `Core` *(Logika Simulasi)*
Merangkai ketiga ADT di atas. Operasi utama:
- `MasukAntrean` – memasukkan pengunjung ke antrean sesuai kode layanan
- `CariLoketKosong` – mencari loket kosong yang bisa melayani, prioritas nomor terkecil
- `JalankanRonde` – menjalankan satu siklus simulasi
- `IsSemuaSelesai` – mengecek apakah semua antrean dan loket telah kosong
- `PrintKondisi` – mencetak kondisi lengkap antrean dan loket

---

## ⚙️ Konfigurasi Loket

| Loket | Jenis Layanan                        |
|-------|--------------------------------------|
| L1    | A (Administrasi), B (Pembayaran)     |
| L2    | B (Pembayaran)                       |
| L3    | I (Informasi), P (Pengaduan)         |
| L4    | P (Pengaduan)                        |

---

## 🔄 Alur Simulasi

Setiap **ronde** berjalan dengan urutan:
1. **Selesaikan** semua loket yang sedang melayani (status → kosong, pengunjung masuk riwayat)
2. **Panggil pengunjung** dari antrean secara berurutan: **A → B → I → P**
   - Setiap antrean mencari loket kosong yang cocok dengan nomor terkecil
   - Loket yang ditemukan langsung mulai melayani pengunjung terdepan

Simulasi berhenti ketika **semua antrean kosong** dan **semua loket kosong**, atau setelah maksimum **50 ronde** (pengaman deadlock).

---

## 🧪 Skenario Pengujian

Program `main.c` mencakup **6 skenario** pengujian:

| # | Skenario | Yang Diuji |
|---|----------|------------|
| 1 | Sesuai soal tugas (5 pengunjung campuran) | Alur normal simulasi |
| 2 | Loket 1 diperebutkan layanan A dan B | Prioritas layanan A sebelum B |
| 3 | Loket 3 diperebutkan layanan I dan P | Prioritas nomor loket terkecil |
| 4 | 11 pengunjung B masuk (kapasitas 10) | Penolakan saat antrean penuh |
| 5 | Kode layanan tidak valid (`'X'`, `'a'`) | Validasi kode layanan |
| 6 | Pengunjung datang di tengah simulasi | Penambahan pengunjung dinamis |

---

## 📦 Cara Kompilasi & Menjalankan

### Kompilasi (GCC)
```bash
gcc -o antrean main.c Pengunjung.c QueueP.c Loket.c Core.c
```

### Jalankan
```bash
./antrean
```

### Output ke file (opsional)
```bash
./antrean > hasil.txt
```

---

## 📄 Contoh Output

```
PROGRAM ANTREAN LAYANAN LOKET

==================== SKENARIO 1: SESUAI TUGAS ====================

--- Kondisi awal ---
[Antrean A - Administrasi] (1 orang): Budi
[Antrean B - Pembayaran]   (2 orang): Sari, Andi
[Antrean I - Informasi]    (0 orang): (kosong)
[Antrean P - Pengaduan]    (2 orang): Dewi, Rina

>>>>>>>>>> RONDE 1 <<<<<<<<<<
L1 melayani Budi (A) | L2 melayani Sari (B) | L3 melayani Dewi (P) | L4 melayani Rina (P)

>>>>>>>>>> RONDE 2 <<<<<<<<<<
L1 melayani Andi (B) | L2 kosong | L3 kosong | L4 kosong

Simulasi selesai pada ronde 3.
```

> Output lengkap tersedia di [`res.txt`](res.txt).

---

## 📌 Catatan Implementasi

- Implementasi **Queue linear** dengan pergeseran elemen saat `Dequeue` (bukan circular)
- Selektor sederhana menggunakan **macro `#define`** untuk efisiensi
- Tipe `boolean` didefinisikan manual via `boolean.h` (kompatibel C89/C90)
- Validasi kode layanan hanya menerima huruf kapital: `'A'`, `'B'`, `'I'`, `'P'`
- Loket dengan kapasitas riwayat penuh akan mencetak pesan `ERR`
