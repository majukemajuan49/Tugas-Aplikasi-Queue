/**************************************************************/
/* Program   : main.c                                         */
/* Deskripsi : Program AntreanLayanan - simulasi antrean      */
/*             layanan pengunjung di loket                    */
/* NIM/Nama  : 24060125120033/Farrelino Arvia Atmajaya        */
/* Tanggal   : 28 September 2026                              */
/**************************************************************/

#include <stdio.h>
#include "Pengunjung.h"
#include "QueueP.h"
#include "Loket.h"
#include "Core.h"

#define MAX_RONDE 50   // pengaman agar simulasi tidak berjalan tanpa henti

/* ---------- prosedur bantu tampilan ---------- */

void printSection(char section[]) {
    printf("\n\n==================== %s ====================\n", section);
}

void printSubSection(char subSection[]) {
    printf("\n--- %s ---\n", subSection);
}

/* Format: L1[P3] = loket 1 melayani pengunjung id 3, L2[-] = loket 2 kosong */
void PrintRingkasanLoket(Loket L) {
    if (IsLoketKosong(L)) {
        printf("L%d[-] ", GetIdLoket(L));
    } else {
        printf("L%d[P%d] ", GetIdLoket(L), GetId(GetPengunjungAktif(L)));
    }
}

void PrintRingkasan(int ronde, QueueP QA, QueueP QB, QueueP QI, QueueP QP,
                    Loket L1, Loket L2, Loket L3, Loket L4) {
    printf("Ronde %d | sisa antrean A=%d B=%d I=%d P=%d | ", ronde,
           SizeQueue(QA), SizeQueue(QB), SizeQueue(QI), SizeQueue(QP));
    PrintRingkasanLoket(L1);
    PrintRingkasanLoket(L2);
    PrintRingkasanLoket(L3);
    PrintRingkasanLoket(L4);
    printf("\n");
}

/* ---------- prosedur bantu setup ---------- */

/* Membuat ulang 4 antrean kosong dan 4 loket sesuai ketentuan soal */
void ResetSemua(QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP,
                Loket *L1, Loket *L2, Loket *L3, Loket *L4) {
    CreateQueue(QA);
    CreateQueue(QB);
    CreateQueue(QI);
    CreateQueue(QP);
    MakeLoket(1, 'A', 'B', L1);
    MakeLoket(2, 'B', '-', L2);
    MakeLoket(3, 'I', 'P', L3);
    MakeLoket(4, 'P', '-', L4);
}

/* Membuat 1 pengunjung lalu memasukkannya ke antrean sesuai layanannya */
void TambahPengunjung(int id, char nama[], char layanan,
                      QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP) {
    // kamus lokal
    Pengunjung p;

    // algoritma
    CreatePengunjung(id, nama, layanan, &p);
    MasukAntrean(p, QA, QB, QI, QP);
}

/* Membuat sejumlah pengunjung berlayanan sama, id berurutan mulai idAwal */
void TambahBanyak(int idAwal, int jumlah, char layanan,
                  QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP) {
    // kamus lokal
    int i;
    char nama[50];

    // algoritma
    for (i = 0; i < jumlah; i++) {
        sprintf(nama, "Tamu-%c%d", layanan, idAwal + i);
        TambahPengunjung(idAwal + i, nama, layanan, QA, QB, QI, QP);
    }
}

/* ---------- simulasi sampai selesai ---------- */

/* lengkap=1 : tiap ronde cetak kondisi lengkap antrean dan loket
   lengkap=0 : tiap ronde cukup satu baris ringkasan
   rondeAwal : penomoran ronde dimulai dari rondeAwal+1 */
void Simulasi(QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP,
              Loket *L1, Loket *L2, Loket *L3, Loket *L4, int lengkap, int rondeAwal) {
    // kamus lokal
    int ronde, langkah;

    // algoritma
    ronde = rondeAwal;
    langkah = 0;
    while (!IsSemuaSelesai(*QA, *QB, *QI, *QP, *L1, *L2, *L3, *L4) && langkah < MAX_RONDE) {
        ronde++;
        langkah++;
        if (lengkap) {
            printf("\n>>>>>>>>>> RONDE %d <<<<<<<<<<\n", ronde);
        }
        JalankanRonde(QA, QB, QI, QP, L1, L2, L3, L4);
        if (lengkap) {
            PrintKondisi(*QA, *QB, *QI, *QP, *L1, *L2, *L3, *L4);
        } else {
            PrintRingkasan(ronde, *QA, *QB, *QI, *QP, *L1, *L2, *L3, *L4);
        }
    }

    if (!IsSemuaSelesai(*QA, *QB, *QI, *QP, *L1, *L2, *L3, *L4)) {
        printf("ERR: simulasi dihentikan setelah %d ronde (kemungkinan macet).\n", MAX_RONDE);
    } else {
        printf("Simulasi selesai pada ronde %d.\n", ronde);
    }
}

int main() {
    // kamus lokal
    Pengunjung P1, P2, P3, P4, P5;
    QueueP QA, QB, QI, QP;   // antrean layanan Administrasi, Pembayaran, Informasi, Pengaduan
    Loket L1, L2, L3, L4;

    // algoritma
    printf("PROGRAM ANTREAN LAYANAN LOKET\n");

    /* ---------- skenario 1: sesuai tugas ---------- */
    printSection("SKENARIO 1: SESUAI TUGAS");

    // membuat sampel data pengunjung
    CreatePengunjung(1, "Budi", 'A', &P1);
    CreatePengunjung(2, "Sari", 'B', &P2);
    CreatePengunjung(3, "Andi", 'B', &P3);
    CreatePengunjung(4, "Dewi", 'P', &P4);
    CreatePengunjung(5, "Rina", 'P', &P5);

    // membuat 4 loket sesuai ketentuan soal
    MakeLoket(1, 'A', 'B', &L1);
    MakeLoket(2, 'B', '-', &L2);
    MakeLoket(3, 'I', 'P', &L3);
    MakeLoket(4, 'P', '-', &L4);

    // inisialisasi antrean
    CreateQueue(&QA);
    CreateQueue(&QB);
    CreateQueue(&QI);
    CreateQueue(&QP);

    // pengunjung masuk antrean sesuai layanan
    MasukAntrean(P1, &QA, &QB, &QI, &QP);
    MasukAntrean(P2, &QA, &QB, &QI, &QP);
    MasukAntrean(P3, &QA, &QB, &QI, &QP);
    MasukAntrean(P4, &QA, &QB, &QI, &QP);
    MasukAntrean(P5, &QA, &QB, &QI, &QP);

    printSubSection("Kondisi awal");
    PrintKondisi(QA, QB, QI, QP, L1, L2, L3, L4);
    Simulasi(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4, 1, 0);


    /* ---------- skenario 2: loket 1 diperebutkan layanan A dan B ---------- */
    printSection("SKENARIO 2: LOKET 1 DIPEREBUTKAN A DAN B");
    printf("1 pengunjung A (id 1), 2 pengunjung B (id 2 dan 3). Diuji: urutan A -> B.\n");
    ResetSemua(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4);
    TambahPengunjung(1, "Tamu-A1", 'A', &QA, &QB, &QI, &QP);
    TambahBanyak(2, 2, 'B', &QA, &QB, &QI, &QP);
    Simulasi(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4, 0, 0);


    /* ---------- skenario 3: loket 3 diperebutkan layanan I dan P ---------- */
    printSection("SKENARIO 3: LOKET 3 DIPEREBUTKAN I DAN P");
    printf("1 pengunjung I (id 1), 3 pengunjung P (id 2 sampai 4). Diuji: nomor loket terkecil.\n");
    ResetSemua(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4);
    TambahPengunjung(1, "Tamu-I1", 'I', &QA, &QB, &QI, &QP);
    TambahBanyak(2, 3, 'P', &QA, &QB, &QI, &QP);
    Simulasi(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4, 0, 0);


    /* ---------- skenario 4: antrean penuh ---------- */
    printSection("SKENARIO 4: ANTREAN PENUH");
    printf("11 pengunjung B masuk, kapasitas antrean 10. Diuji: pengunjung ke-11 ditolak.\n");
    ResetSemua(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4);
    TambahBanyak(1, 11, 'B', &QA, &QB, &QI, &QP);
    printf("Ukuran antrean B: %d\n", SizeQueue(QB));
    Simulasi(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4, 0, 0);


    /* ---------- skenario 5: kode layanan tidak valid ---------- */
    printSection("SKENARIO 5: KODE LAYANAN TIDAK VALID");
    printf("Kode 'X' dan 'a' (huruf kecil). Diuji: ditolak, tidak masuk antrean manapun.\n");
    ResetSemua(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4);
    TambahPengunjung(1, "Valid", 'A', &QA, &QB, &QI, &QP);
    TambahPengunjung(2, "Salah", 'X', &QA, &QB, &QI, &QP);
    TambahPengunjung(3, "Kecil", 'a', &QA, &QB, &QI, &QP);
    Simulasi(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4, 0, 0);


    /* ---------- skenario 6: pengunjung datang di tengah simulasi ---------- */
    printSection("SKENARIO 6: PENGUNJUNG DATANG DI TENGAH SIMULASI");
    printf("2 pengunjung B (id 1 dan 2), lalu setelah ronde 1 datang id 3 (B) dan id 4 (A).\n");
    ResetSemua(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4);
    TambahBanyak(1, 2, 'B', &QA, &QB, &QI, &QP);
    JalankanRonde(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4);
    PrintRingkasan(1, QA, QB, QI, QP, L1, L2, L3, L4);
    printf("(pengunjung baru datang: id 3 layanan B, id 4 layanan A)\n");
    TambahPengunjung(3, "Telat-B", 'B', &QA, &QB, &QI, &QP);
    TambahPengunjung(4, "Telat-A", 'A', &QA, &QB, &QI, &QP);
    Simulasi(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4, 0, 1);

    return 0;
}