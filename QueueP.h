#ifndef QueueP_H
#define QueueP_H
#include "Pengunjung.h"
#include "boolean.h"

/* type QueueP = <  wadah: array [1..10] of Pengunjung,
					head: integer,
					tail: integer 
                 > */
typedef struct { Pengunjung wadah[11]; //kapasitas 10 elemen, indeks 0 tidak dipakai
                  int head; 
                  int tail; 
                } QueueP;

/*procedure CreateQueue(output Q: QueueP)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan Pengunjung kosong (CreatePengunjung(-1, "-", '-', &Q->wadah[i])), head = tail = 0 }*/
void CreateQueue(QueueP *Q); 

/*function Head(Q:QueueP)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(QueueP Q);
#define Head(Q) (Q).head //implementasi fisik macro

/*function Tail(Q:QueueP)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(QueueP Q);
#define Tail(Q) (Q).tail //implementasi fisik macro

/*function InfoHead(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung InfoHead(QueueP Q);

/*function InfoTail(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung InfoTail(QueueP Q);

/*procedure Enqueue( input/output Q:QueueP, input p: Pengunjung )
{I.S.: Q dan p terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void Enqueue(QueueP *Q, Pengunjung p);
  
/*procedure Dequeue( input/output Q:QueueP, output p: Pengunjung )
{I.S.: }
{F.S.: p=InfoHead(Q) atau p=CreatePengunjung(-1, "-", '-', &Q->wadah[i]) bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void Dequeue(QueueP *Q, Pengunjung *p);


/*function IsEmptyQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q kosong}*/
boolean IsEmptyQueue(QueueP Q);
 
/*function IsFullQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q penuh}*/
boolean IsFullQueue(QueueP Q);

/*function IsOneElement(Q:QueueP) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean IsOneElement(QueueP Q);

/*function SizeQueue(Q:QueueP)-> integer 
{mengembalikan panjang antrian Q} */
int SizeQueue(QueueP Q);

/*procedure PrintQueueP(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void PrintQueueP(QueueP Q);

/*procedure ViewQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void ViewQueue(QueueP Q);

// Operasi lain yang diperlukan
// ...

#endif