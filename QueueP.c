#include "QueueP.h"
#include "Pengunjung.h"
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10

/*procedure CreateQueue(output Q: QueueP)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan Pengunjung kosong (CreatePengunjung(-1, "-", '-', &Q->wadah[i])), head = tail = 0 }*/
void CreateQueue(QueueP *Q) {
    // kamus lokal
    int i;
    Pengunjung kosong;

    // algoritma
    for (i = 1; i <= MAX_SIZE; i++) {
        CreatePengunjung(-1, "-", '-', &kosong);
        Q->wadah[i] = kosong;
    }
    Q->head = 0;
    Q->tail = 0;
} 

/*function InfoHead(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung InfoHead(QueueP Q) {
    // kamus lokal
    Pengunjung kosong;

    // algoritma
    if (IsEmptyQueue(Q)) {
        CreatePengunjung(-1, "-", '-', &kosong);
        return kosong; // Mengembalikan Pengunjung kosong jika antrian kosong
    } else {
        return Q.wadah[Q.head];
    }
}

/*function InfoTail(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung InfoTail(QueueP Q) {
    // kamus lokal
    Pengunjung kosong;

    // algoritma
    if (IsEmptyQueue(Q)) {
        CreatePengunjung(-1, "-", '-', &kosong);
        return kosong; // Mengembalikan Pengunjung kosong jika antrian kosong
    } else {
        return Q.wadah[Q.tail];
    }
}

/*procedure Enqueue( input/output Q:QueueP, input p: Pengunjung )
{I.S.: Q dan p terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void Enqueue(QueueP *Q, Pengunjung p) {
    // kamus lokal
    // -

    // algoritma
    if (!IsFullQueue(*Q)) {
        if (IsEmptyQueue(*Q)) {
            Q->head = 1;
        }
        Q->tail++;
        Q->wadah[Q->tail] = p;
    } else {
        printf("ERR: queue full, can't enqueue another element.\n");
    }
}
  
/*procedure Dequeue( input/output Q:QueueP, output p: Pengunjung )
{I.S.: }
{F.S.: p=InfoHead(Q) atau p=CreatePengunjung(-1, "-", '-', &Q->wadah[i]) bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void Dequeue(QueueP *Q, Pengunjung *p) {
    // kamus lokal
    int i;

    // algoritma
    if (!IsEmptyQueue(*Q)) {
        *p = InfoHead(*Q);
        for (i = 1; i <= Tail(*Q)-1; i++) {
            Q->wadah[i] = Q->wadah[i + 1];
        }
        CreatePengunjung(-1, "-", '-', &Q->wadah[Q->tail]); // Mengosongkan elemen terakhir setelah digeser
        Q->tail--;
        if (Q->tail == 0) {
            Q->head = 0;
        }
    } else {
        CreatePengunjung(-1, "-", '-', p); // Mengembalikan Pengunjung kosong jika antrian kosong
    }
}

/*function IsEmptyQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q kosong}*/
boolean IsEmptyQueue(QueueP Q) {
    // kamus lokal
    // -

    // algoritma
    return Head(Q) == 0;
}
 
/*function IsFullQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q penuh}*/
boolean IsFullQueue(QueueP Q) {
    // kamus lokal
    // -

    // algoritma
    return Tail(Q) == MAX_SIZE;
}

/*function IsOneElement(Q:QueueP) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean IsOneElement(QueueP Q) {
    // kamus lokal
    // -

    // algoritma
    return Tail(Q) == 1;
}

/*function SizeQueue(Q:QueueP)-> integer 
{mengembalikan panjang antrian Q} */
int SizeQueue(QueueP Q) {
    // kamus lokal
    // -

    // algoritma
    return Tail(Q);
}

/*procedure PrintQueueP(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void PrintQueueP(QueueP Q) {
    // kamus lokal
    int i;

    // algoritma
    printf("[\n");
    for (i = 1; i <= MAX_SIZE; i++) {
        PrintPengunjung(Q.wadah[i]);
        if (i < MAX_SIZE) {
            printf("====================\n");
        }
    }
    printf("]\n");
}

/*procedure ViewQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void ViewQueue(QueueP Q) {
    // kamus lokal
    int i;

    // algoritma
    if (IsEmptyQueue(Q)) {
        printf("(kosong)\n");
    } else {
        for (i = 1; i <= Tail(Q); i++) {
            printf("--- Antrean ke-%d ---\n", i);
            PrintPengunjung(Q.wadah[i]);
        }
    }
}

// Operasi lain yang diperlukan
// ...