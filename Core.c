/************************************************************/
/* Program   : Core.c                                       */
/* Deskripsi : file IMPLEMENTASI logika simulasi antrean    */
/*             layanan loket                                */
/* NIM/Nama  : 24060125120033/Farrelino Arvia Atmajaya      */
/* Tanggal   : 28 September 2026                            */
/************************************************************/

#include "Core.h"
#include <stdio.h>

/*procedure MasukAntrean(input p: Pengunjung, input/output QA,QB,QI,QP: QueueP)
{I.S.: p, QA, QB, QI, QP terdefinisi}
{F.S.: p masuk ke antrean sesuai layanan p, bila kode layanan tidak valid cetak ERR}
{Proses: memilih antrean berdasarkan kode layanan ('A','B','I','P') lalu Enqueue} */
void MasukAntrean(Pengunjung p, QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP) {
    // kamus lokal
    // -

    // algoritma
    switch (GetLayanan(p)) {
        case 'A': Enqueue(QA, p); break;
        case 'B': Enqueue(QB, p); break;
        case 'I': Enqueue(QI, p); break;
        case 'P': Enqueue(QP, p); break;
        default : printf("ERR: kode layanan '%c' milik pengunjung %d tidak valid.\n", GetLayanan(p), GetId(p));
    }
}

/*function CariLoketKosong(layanan: character, L1,L2,L3,L4: Loket) -> integer
{mengembalikan id loket dengan status=0 yang dapat melayani layanan, dengan id terkecil;
 mengembalikan 0 bila tidak ada loket kosong yang cocok}
{pengecekan berurutan L1, L2, L3, L4 sehingga nomor terkecil didahulukan} */
int CariLoketKosong(char layanan, Loket L1, Loket L2, Loket L3, Loket L4) {
    // kamus lokal
    // -

    // algoritma
    if (IsLoketKosong(L1) && BisaMelayani(L1, layanan)) {
        return GetIdLoket(L1);
    } else if (IsLoketKosong(L2) && BisaMelayani(L2, layanan)) {
        return GetIdLoket(L2);
    } else if (IsLoketKosong(L3) && BisaMelayani(L3, layanan)) {
        return GetIdLoket(L3);
    } else if (IsLoketKosong(L4) && BisaMelayani(L4, layanan)) {
        return GetIdLoket(L4);
    } else {
        return 0;
    }
}

/*procedure SelesaikanSemuaLoket(input/output L1,L2,L3,L4: Loket)
{I.S.: L1..L4 terdefinisi}
{F.S.: semua loket berstatus 1 telah selesai melayani (status=0, pengunjung tercatat di list)}
{Proses: memanggil SelesaiMelayani untuk tiap loket yang sedang melayani} */
void SelesaikanSemuaLoket(Loket *L1, Loket *L2, Loket *L3, Loket *L4) {
    // kamus lokal
    // -

    // algoritma
    if (!IsLoketKosong(*L1)) SelesaiMelayani(L1);
    if (!IsLoketKosong(*L2)) SelesaiMelayani(L2);
    if (!IsLoketKosong(*L3)) SelesaiMelayani(L3);
    if (!IsLoketKosong(*L4)) SelesaiMelayani(L4);
}

/*procedure PanggilPengunjung(input/output Q: QueueP, input layanan: character, input/output L1,L2,L3,L4: Loket)
{I.S.: Q adalah antrean untuk layanan, L1..L4 terdefinisi}
{F.S.: pengunjung terdepan Q dilayani loket kosong yang cocok, berulang selama Q tidak kosong
       dan masih ada loket kosong yang cocok}
{Proses: CariLoketKosong -> Dequeue -> MulaiMelayani; pengunjung yang belum kebagian loket tetap di Q} */
void PanggilPengunjung(QueueP *Q, char layanan, Loket *L1, Loket *L2, Loket *L3, Loket *L4) {
    // kamus lokal
    Pengunjung p;
    int id;

    // algoritma
    id = CariLoketKosong(layanan, *L1, *L2, *L3, *L4);
    while (!IsEmptyQueue(*Q) && id != 0) {
        Dequeue(Q, &p);
        if (id == GetIdLoket(*L1)) {
            MulaiMelayani(L1, p);
        } else if (id == GetIdLoket(*L2)) {
            MulaiMelayani(L2, p);
        } else if (id == GetIdLoket(*L3)) {
            MulaiMelayani(L3, p);
        } else {
            MulaiMelayani(L4, p);
        }
        id = CariLoketKosong(layanan, *L1, *L2, *L3, *L4);
    }
}

/*function IsSemuaSelesai(QA,QB,QI,QP: QueueP, L1,L2,L3,L4: Loket) -> boolean
{mengembalikan true jika keempat antrean kosong dan keempat loket kosong (tidak ada yang melayani)} */
boolean IsSemuaSelesai(QueueP QA, QueueP QB, QueueP QI, QueueP QP,
                       Loket L1, Loket L2, Loket L3, Loket L4) {
    // kamus lokal
    // -

    // algoritma
    return IsEmptyQueue(QA) && IsEmptyQueue(QB) && IsEmptyQueue(QI) && IsEmptyQueue(QP)
        && IsLoketKosong(L1) && IsLoketKosong(L2) && IsLoketKosong(L3) && IsLoketKosong(L4);
}

/*procedure JalankanRonde(input/output QA,QB,QI,QP: QueueP, input/output L1,L2,L3,L4: Loket)
{I.S.: semua terdefinisi}
{F.S.: satu ronde simulasi telah dijalankan}
{Proses: SelesaikanSemuaLoket, lalu PanggilPengunjung untuk antrean A, B, I, P (berurutan)} */
void JalankanRonde(QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP,
                   Loket *L1, Loket *L2, Loket *L3, Loket *L4) {
    // kamus lokal
    // -

    // algoritma
    SelesaikanSemuaLoket(L1, L2, L3, L4);
    PanggilPengunjung(QA, 'A', L1, L2, L3, L4);
    PanggilPengunjung(QB, 'B', L1, L2, L3, L4);
    PanggilPengunjung(QI, 'I', L1, L2, L3, L4);
    PanggilPengunjung(QP, 'P', L1, L2, L3, L4);
}

/*procedure PrintKondisi(input QA,QB,QI,QP: QueueP, input L1,L2,L3,L4: Loket)
{I.S.: semua terdefinisi}
{F.S.: -}
{Proses: mencetak kondisi keempat antrean dan informasi keempat loket} */
void PrintKondisi(QueueP QA, QueueP QB, QueueP QI, QueueP QP,
                  Loket L1, Loket L2, Loket L3, Loket L4) {
    // kamus lokal
    // -

    // algoritma
    printf("\n########## KONDISI ANTREAN ##########\n");
    printf("[Antrean A - Administrasi] (%d orang)\n", SizeQueue(QA));
    ViewQueue(QA);
    printf("[Antrean B - Pembayaran] (%d orang)\n", SizeQueue(QB));
    ViewQueue(QB);
    printf("[Antrean I - Informasi] (%d orang)\n", SizeQueue(QI));
    ViewQueue(QI);
    printf("[Antrean P - Pengaduan] (%d orang)\n", SizeQueue(QP));
    ViewQueue(QP);

    printf("\n########## KONDISI LOKET ##########\n");
    PrintLoket(L1);
    printf("\n");
    PrintLoket(L2);
    printf("\n");
    PrintLoket(L3);
    printf("\n");
    PrintLoket(L4);
}