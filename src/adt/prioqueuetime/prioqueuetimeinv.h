/* File : prioqueuetime.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef prioqueuetimeinv_H
#define prioqueuetimeinv_H

#include "../boolean/boolean.h"
#include "../food/food.h"
#include "../time/time.h"
#include "../wordmachinefood/wordmachine.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef int idx; /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueTime : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct
{
    Food *T; /* tabel penyimpan elemen */
    idx HEAD; /* alamat penghapusan */
    idx TAIL; /* alamat penambahan */
    int MaxEl;    /* Max elemen queue */
} PrioQueueTime;
/* Definisi PrioQueueTime kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika t : Food dan Q : PrioQueueTime, maka akses elemen : */
#define expTime(t) (t).exptime
#define nama(t) (t).name
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define Elmt(Q, i) (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty(PrioQueueTime Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull(PrioQueueTime Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt(PrioQueueTime Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void createInv(PrioQueueTime *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueueTime *Q, Food X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue(PrioQueueTime *Q, Food *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueTime(PrioQueueTime Q);
/* Mencetak isi Q ke layar dengan format:
[(<nama>, <exp>), (<nama>, <exp>), ...] */

#endif