/**************************************************************/
/* Program   : Loket.c                                        */
/* Deskripsi : file IMPLEMENTASI modul ADT Loket              */
/* NIM/Nama  : 24060125120033/Farrelino Arvia Atmajaya        */
/* Tanggal   : 28 September 2026                              */
/**************************************************************/

#include "Loket.h"
#include "Pengunjung.h"
#include <stdio.h>

#define MAX_LIST 10

/*procedure MakeLoket(input id: integer, input layanan1: character, input layanan2: character, output L: Loket)
{I.S.: id, layanan1, layanan2 terdefinisi (layanan2='-' bila loket hanya melayani 1 jenis)}
{F.S.: L terdefinisi, status=0, pengunjungAktif kosong, listPengunjung kosong, jumlahDilayani=0}
{Proses: mengisi field-field L; pengunjung kosong = (-1, "-", '-') } */
void MakeLoket(int id, char layanan1, char layanan2, Loket *L) {
    // kamus lokal
    int i;

    // algoritma
    L->id = id;
    L->status = 0;
    L->jenisLayanan[0] = '-';
    L->jenisLayanan[1] = layanan1;
    L->jenisLayanan[2] = layanan2;
    CreatePengunjung(-1, "-", '-', &L->pengunjungAktif);
    for (i = 1; i <= MAX_LIST; i++) {
        CreatePengunjung(-1, "-", '-', &L->listPengunjung[i]);
    }
    L->jumlahDilayani = 0;
}

/*procedure SetStatus(input/output L: Loket, input status: integer)
{I.S.: L dan status terdefinisi}
{F.S.: L.status = status}
{Proses: mengubah status loket L} */
void SetStatus(Loket *L, int status) {
    // kamus lokal
    // -

    // algoritma
    L->status = status;
}

/*procedure MulaiMelayani(input/output L: Loket, input p: Pengunjung)
{I.S.: L terdefinisi dan kosong (status=0), p terdefinisi}
{F.S.: L.pengunjungAktif = p, L.status = 1}
{Proses: loket mulai melayani p; bila loket sedang melayani, cetak pesan ERR dan tidak berubah} */
void MulaiMelayani(Loket *L, Pengunjung p) {
    // kamus lokal
    // -

    // algoritma
    if (IsLoketKosong(*L)) {
        L->pengunjungAktif = p;
        L->status = 1;
    } else {
        printf("ERR: loket %d sedang melayani, tidak bisa melayani pengunjung lain.\n", GetIdLoket(*L));
    }
}

/*procedure SelesaiMelayani(input/output L: Loket)
{I.S.: L terdefinisi, sedang melayani (status=1)}
{F.S.: pengunjungAktif masuk ke listPengunjung, jumlahDilayani bertambah 1,
       pengunjungAktif kosong, status = 0}
{Proses: mencatat pengunjung yang selesai dilayani; bila status=0 atau listPengunjung penuh,
         cetak pesan ERR} */
void SelesaiMelayani(Loket *L) {
    // kamus lokal
    // -

    // algoritma
    if (IsLoketKosong(*L)) {
        printf("ERR: loket %d tidak sedang melayani siapa pun.\n", GetIdLoket(*L));
    } else if (L->jumlahDilayani >= MAX_LIST) {
        printf("ERR: listPengunjung loket %d penuh, tidak bisa mencatat pengunjung.\n", GetIdLoket(*L));
    } else {
        L->jumlahDilayani++;
        L->listPengunjung[L->jumlahDilayani] = L->pengunjungAktif;
        CreatePengunjung(-1, "-", '-', &L->pengunjungAktif);
        L->status = 0;
    }
}

/*function IsLoketKosong(L: Loket) -> boolean
{mengembalikan true jika status loket L = 0 (tidak sedang melayani)} */
boolean IsLoketKosong(Loket L) {
    // kamus lokal
    // -

    // algoritma
    return GetStatus(L) == 0;
}

/*function BisaMelayani(L: Loket, layanan: character) -> boolean
{mengembalikan true jika layanan termasuk salah satu jenisLayanan loket L} */
boolean BisaMelayani(Loket L, char layanan) {
    // kamus lokal
    // -

    // algoritma
    return layanan != '-' && (L.jenisLayanan[1] == layanan || L.jenisLayanan[2] == layanan);
}

/*procedure PrintLoket(input L: Loket)
{I.S.: L terdefinisi}
{F.S.: -}
{Proses: mencetak id, status, jenis layanan, pengunjung aktif (bila melayani),
         dan daftar pengunjung yang sudah dilayani} */
void PrintLoket(Loket L) {
    // kamus lokal
    int i;

    // algoritma
    printf("=== LOKET %d ===\n", GetIdLoket(L));
    printf("Status          : %d (%s)\n", GetStatus(L), IsLoketKosong(L) ? "kosong" : "melayani");

    printf("Jenis layanan   : %c", L.jenisLayanan[1]);
    if (L.jenisLayanan[2] != '-') {
        printf(", %c", L.jenisLayanan[2]);
    }
    printf("\n");

    printf("Sedang dilayani :");
    if (IsLoketKosong(L)) {
        printf(" -\n");
    } else {
        printf("\n");
        PrintPengunjung(GetPengunjungAktif(L));
    }

    printf("Sudah dilayani (%d orang):", GetJumlahDilayani(L));
    if (GetJumlahDilayani(L) == 0) {
        printf(" -\n");
    } else {
        printf("\n");
        for (i = 1; i <= GetJumlahDilayani(L); i++) {
            PrintPengunjung(L.listPengunjung[i]);
            if (i < GetJumlahDilayani(L)) {
                printf("--------------------\n");
            }
        }
    }
}