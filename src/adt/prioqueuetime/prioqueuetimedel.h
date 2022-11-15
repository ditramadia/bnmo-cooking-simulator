#include "../boolean/boolean.h"
#include "../food/food.h"
#include "../time/time.h"


#ifndef PRIOQUEUETIMEDEL_H
#define PRIOQUEUETIMEDEL_H

/* *** Definisi Type PrioQueueTimeDel dengan representasi array secara eksplisit *** */
/* *** Konstanta *** */
#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* *** Definisi elemen dan address *** */
typedef int idx; /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueTime : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct
{
    Food *T; /* tabel penyimpan elemen */
    idx HEAD; /* alamat penghapusan */
    idx TAIL; /* alamat penambahan */
    int MaxEl;    /* Max elemen queue */
} PrioQueueTime;  /* indeks tabel */

/* Deklarasi : 
      Q : PrioQueueTimeDel 
      t : Food */
/* Maka cara akses:
   Q.t[i] untuk mengakses elemen ke-i
   Q.t[i].name untuk mengakses nama dari elemen ke-i
   Q.t[i].Time untuk mengakses Time dari elemen ke-i
*/

/* ********* AKSES (Selektor) ********* */
/* Jika t : Food dan Q : PrioQueueTime, maka akses elemen : */
#define delTime(t) (t).deltime
#define nama(t) (t).name
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define Elmt(Q, i) (Q).T[(i)]

/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
boolean isEmpty(PrioQueueTime Q);
/* Mengirim true jika Q kosong: Head(Q) and Tail(Q) = NIL */
boolean isFull(PrioQueueTime Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int length(PrioQueueTime Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void createDel(PrioQueueTime *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* ********* Operator Dasar PrioQueueTime ********* */
void enqueue(PrioQueueTime* Q, Food X);
/* Menambahkan X pada Q dengan aturan prioqueue */
void dequeue(PrioQueueTime* Q, Food* X);
/* Menghapus X pada Q dengan aturan FIFO */


/* ********* Operator Tambahan ********* */
void PrioQueueTimePrint (PrioQueueTime Q);
/* Mencetak isi Q ke layar dengan format:
[(<nama>, <waktu>), (<nama>, <waktu>), ...] */
void displayDelivery(PrioQueueTime Q);

#endif