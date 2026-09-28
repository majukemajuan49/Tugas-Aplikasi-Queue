#ifndef Core_H
#define Core_H
#include "Pengunjung.h"
#include "QueueP.h"
#include "Loket.h"
#include "boolean.h"

/************************************************************/
/* Program   : Core.h                                       */
/* Deskripsi : logika simulasi antrean layanan loket,       */
/*             merangkai ADT Pengunjung, QueueP, dan Loket  */
/* NIM/Nama  : 24060125120033/Farrelino Arvia Atmajaya      */
/* Tanggal   : 28 September 2026                            */
/************************************************************/

/* Asumsi:
   - simulasi berjalan per ronde, satu loket melayani satu pengunjung per ronde
   - urutan pengecekan antrean tiap ronde: A -> B -> I -> P
   - antrean: QA=Administrasi, QB=Pembayaran, QI=Informasi, QP=Pengaduan
   - id loket dimulai dari 1, id=0 berarti "tidak ada loket" */

/*procedure MasukAntrean(input p: Pengunjung, input/output QA,QB,QI,QP: QueueP)
{I.S.: p, QA, QB, QI, QP terdefinisi}
{F.S.: p masuk ke antrean sesuai layanan p, bila kode layanan tidak valid cetak ERR}
{Proses: memilih antrean berdasarkan kode layanan ('A','B','I','P') lalu Enqueue} */
void MasukAntrean(Pengunjung p, QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP);

/*function CariLoketKosong(layanan: character, L1,L2,L3,L4: Loket) -> integer
{mengembalikan id loket dengan status=0 yang dapat melayani layanan, dengan id terkecil;
 mengembalikan 0 bila tidak ada loket kosong yang cocok}
{pengecekan berurutan L1, L2, L3, L4 sehingga nomor terkecil didahulukan} */
int CariLoketKosong(char layanan, Loket L1, Loket L2, Loket L3, Loket L4);

/*procedure SelesaikanSemuaLoket(input/output L1,L2,L3,L4: Loket)
{I.S.: L1..L4 terdefinisi}
{F.S.: semua loket berstatus 1 telah selesai melayani (status=0, pengunjung tercatat di list)}
{Proses: memanggil SelesaiMelayani untuk tiap loket yang sedang melayani} */
void SelesaikanSemuaLoket(Loket *L1, Loket *L2, Loket *L3, Loket *L4);

/*procedure PanggilPengunjung(input/output Q: QueueP, input layanan: character, input/output L1,L2,L3,L4: Loket)
{I.S.: Q adalah antrean untuk layanan, L1..L4 terdefinisi}
{F.S.: pengunjung terdepan Q dilayani loket kosong yang cocok, berulang selama Q tidak kosong
       dan masih ada loket kosong yang cocok}
{Proses: CariLoketKosong -> Dequeue -> MulaiMelayani; pengunjung yang belum kebagian loket tetap di Q} */
void PanggilPengunjung(QueueP *Q, char layanan, Loket *L1, Loket *L2, Loket *L3, Loket *L4);

/*function IsSemuaSelesai(QA,QB,QI,QP: QueueP, L1,L2,L3,L4: Loket) -> boolean
{mengembalikan true jika keempat antrean kosong dan keempat loket kosong (tidak ada yang melayani)} */
boolean IsSemuaSelesai(QueueP QA, QueueP QB, QueueP QI, QueueP QP,
                       Loket L1, Loket L2, Loket L3, Loket L4);

/*procedure JalankanRonde(input/output QA,QB,QI,QP: QueueP, input/output L1,L2,L3,L4: Loket)
{I.S.: semua terdefinisi}
{F.S.: satu ronde simulasi telah dijalankan}
{Proses: SelesaikanSemuaLoket, lalu PanggilPengunjung untuk antrean A, B, I, P (berurutan)} */
void JalankanRonde(QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP,
                   Loket *L1, Loket *L2, Loket *L3, Loket *L4);

/*procedure PrintKondisi(input QA,QB,QI,QP: QueueP, input L1,L2,L3,L4: Loket)
{I.S.: semua terdefinisi}
{F.S.: -}
{Proses: mencetak kondisi keempat antrean dan informasi keempat loket} */
void PrintKondisi(QueueP QA, QueueP QB, QueueP QI, QueueP QP,
                  Loket L1, Loket L2, Loket L3, Loket L4);

#endif