#ifndef Loket_H
#define Loket_H
#include "Pengunjung.h"
#include "boolean.h"

/* type Loket = <  id: integer,
                   status: integer,                        {1=melayani, 0=kosong}
                   jenisLayanan: array [1..2] of character, {'-' bila slot tidak dipakai}
                   pengunjungAktif: Pengunjung,
                   listPengunjung: array [1..10] of Pengunjung,
                   jumlahDilayani: integer                 {banyak elemen terisi di listPengunjung}
                > */
typedef struct { int id;
                 int status;
                 char jenisLayanan[3];          //kapasitas 2 layanan, indeks 0 tidak dipakai
                 Pengunjung pengunjungAktif;
                 Pengunjung listPengunjung[11]; //kapasitas 10 elemen, indeks 0 tidak dipakai
                 int jumlahDilayani;
               } Loket;

// {Operasi: Konstruktor, Selektor, Mutator, Print, dan operasi lain yang diperlukan}

/*procedure MakeLoket(input id: integer, input layanan1: character, input layanan2: character, output L: Loket)
{I.S.: id, layanan1, layanan2 terdefinisi (layanan2='-' bila loket hanya melayani 1 jenis)}
{F.S.: L terdefinisi, status=0, pengunjungAktif kosong, listPengunjung kosong, jumlahDilayani=0}
{Proses: mengisi field-field L; pengunjung kosong = (-1, "-", '-') } */
void MakeLoket(int id, char layanan1, char layanan2, Loket *L);

/*function GetIdLoket(L: Loket) -> integer
{mengembalikan id loket L} */
#define GetIdLoket(L) (L).id

/*function GetStatus(L: Loket) -> integer
{mengembalikan status loket L: 1=melayani, 0=kosong} */
#define GetStatus(L) (L).status

/*function GetPengunjungAktif(L: Loket) -> Pengunjung
{mengembalikan pengunjung yang sedang dilayani loket L} */
#define GetPengunjungAktif(L) (L).pengunjungAktif

/*function GetJumlahDilayani(L: Loket) -> integer
{mengembalikan banyak pengunjung yang sudah dilayani loket L} */
#define GetJumlahDilayani(L) (L).jumlahDilayani

/*procedure SetStatus(input/output L: Loket, input status: integer)
{I.S.: L dan status terdefinisi}
{F.S.: L.status = status}
{Proses: mengubah status loket L} */
void SetStatus(Loket *L, int status);

/*procedure MulaiMelayani(input/output L: Loket, input p: Pengunjung)
{I.S.: L terdefinisi dan kosong (status=0), p terdefinisi}
{F.S.: L.pengunjungAktif = p, L.status = 1}
{Proses: loket mulai melayani p; bila loket sedang melayani, cetak pesan ERR dan tidak berubah} */
void MulaiMelayani(Loket *L, Pengunjung p);

/*procedure SelesaiMelayani(input/output L: Loket)
{I.S.: L terdefinisi, sedang melayani (status=1)}
{F.S.: pengunjungAktif masuk ke listPengunjung, jumlahDilayani bertambah 1,
       pengunjungAktif kosong, status = 0}
{Proses: mencatat pengunjung yang selesai dilayani; bila status=0 atau listPengunjung penuh,
         cetak pesan ERR} */
void SelesaiMelayani(Loket *L);

/*function IsLoketKosong(L: Loket) -> boolean
{mengembalikan true jika status loket L = 0 (tidak sedang melayani)} */
boolean IsLoketKosong(Loket L);

/*function BisaMelayani(L: Loket, layanan: character) -> boolean
{mengembalikan true jika layanan termasuk salah satu jenisLayanan loket L} */
boolean BisaMelayani(Loket L, char layanan);

/*procedure PrintLoket(input L: Loket)
{I.S.: L terdefinisi}
{F.S.: -}
{Proses: mencetak id, status, jenis layanan, pengunjung aktif (bila melayani),
         dan daftar pengunjung yang sudah dilayani} */
void PrintLoket(Loket L);

#endif