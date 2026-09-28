#include "Pengunjung.h"
#include <string.h>
#include <stdio.h>

// {Operasi: Konstruktor, Selektor, Mutator, Print}

/* procedure CreatePengunjung(input id: integer, input nama: string, input layanan: character, output p: Pengunjung)
{I.S.: id, nama, dan layanan telah terdefinisi} 
{F.S.: p telah terdefinisi dengan nilai id, nama, dan layanan}
{Proses: Mengisi field-field dari struct Pengunjung } */
void CreatePengunjung(int id, char nama[], char layanan, Pengunjung *p) {
    // kamus lokal
    // -

    // algoritma
    p->id = id;
    strncpy(p->nama, nama, 49);
    p->nama[49] = '\0';
    p->layanan = layanan;
}   

/* procedure SetId(input/output p: Pengunjung, input id: integer)
{I.S.: p dan id telah terdefinisi}
{F.S.: p.id telah terisi dengan nilai id}
{Proses: Mengubah nilai id dari pengunjung p} */
void SetId(Pengunjung *p, int id) {
    // kamus lokal
    // -

    // algoritma
    p->id = id;
}

/* procedure SetNama(input/output p: Pengunjung, input nama: string)
{I.S.: p dan nama telah terdefinisi}
{F.S.: p.nama telah terisi dengan nilai nama}
{Proses: Mengubah nilai nama dari pengunjung p} */
void SetNama(Pengunjung *p, char nama[]) {
    // kamus lokal
    // -

    // algoritma
    strncpy(p->nama, nama, 49);
    p->nama[49] = '\0';
}

/* procedure SetLayanan(input/output p: Pengunjung, input layanan: character)
{I.S.: p dan layanan telah terdefinisi}
{F.S.: p.layanan telah terisi dengan nilai layanan}
{Proses: Mengubah nilai layanan dari pengunjung p} */
void SetLayanan(Pengunjung *p, char layanan) {
    // kamus lokal
    // -

    // algoritma
    p->layanan = layanan;
}

/* procedure PrintPengunjung(input p: Pengunjung)
{I.S.: p telah terdefinisi}
{F.S.: informasi pengunjung p telah dicetak}
{Proses: Mencetak informasi pengunjung p} */
void PrintPengunjung(Pengunjung p) {
    // kamus lokal
    // -

    // algoritma
    printf("ID      : %d\n", p.id);
    printf("Nama    : %s\n", p.nama);
    printf("Layanan : %c\n", p.layanan);
}