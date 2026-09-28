#ifndef Pengunjung_H
#define Pengunjung_H
#include "boolean.h"

/* type Pengunjung = <  id: integer,
                        nama: string,
                        layanan: character
                     >
*/
typedef struct
{
    int id;
    char nama[50];
    char layanan;
} Pengunjung;

/* procedure CreatePengunjung(input id: integer, input nama: string, input layanan: character, output p: Pengunjung)
{I.S.: id, nama, dan layanan telah terdefinisi}
{F.S.: p telah terdefinisi dengan nilai id, nama, dan layanan}
{Proses: Mengisi field-field dari struct Pengunjung } */
void CreatePengunjung(int id, char nama[], char layanan, Pengunjung *p);

/* function GetId(p: Pengunjung) -> integer
{mengembalikan id dari pengunjung p} */
#define GetId(p) (p).id

/* function GetNama(p: Pengunjung) -> string
{mengembalikan nama dari pengunjung p} */
#define GetNama(p) (p).nama

/* function GetLayanan(p: Pengunjung) -> character
{mengembalikan layanan dari pengunjung p} */
#define GetLayanan(p) (p).layanan

/* procedure SetId(input/output p: Pengunjung, input id: integer)
{I.S.: p dan id telah terdefinisi}
{F.S.: p.id telah terisi dengan nilai id}
{Proses: Mengubah nilai id dari pengunjung p} */
void SetId(Pengunjung *p, int id);

/* procedure SetNama(input/output p: Pengunjung, input nama: string)
{I.S.: p dan nama telah terdefinisi}
{F.S.: p.nama telah terisi dengan nilai nama}
{Proses: Mengubah nilai nama dari pengunjung p} */
void SetNama(Pengunjung *p, char nama[]);

/* procedure SetLayanan(input/output p: Pengunjung, input layanan: character)
{I.S.: p dan layanan telah terdefinisi}
{F.S.: p.layanan telah terisi dengan nilai layanan}
{Proses: Mengubah nilai layanan dari pengunjung p} */
void SetLayanan(Pengunjung *p, char layanan);

/* procedure PrintPengunjung(input p: Pengunjung)
{I.S.: p telah terdefinisi}
{F.S.: informasi pengunjung p telah dicetak}
{Proses: Mencetak informasi pengunjung p} */
void PrintPengunjung(Pengunjung p);

#endif