#include "../boolean/boolean.h"
#include "../food/food.h"
#include "prioqueuetimeinv.h"

#ifndef __PRIOQUEUETIMEDEL_H__
#define __PRIOQUEUETIMEDEL_H__

/* *** Definisi Type PrioQueueTimeDel dengan representasi array secara eksplisit *** */
/* *** Konstanta *** */
#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* *** Definisi elemen dan address *** */
typedef struct {
    Food F;
    int Time;
} infotypePrioQueueTimeDel;
/* infotypePrioQueueTimeDel adalah type elemen tabel */

typedef int addressPrioQueueTimeDel;   /* indeks tabel */
/* Indeks yang digunakan [1..MaxElPrioQueueTimeDel] */
/* Indeks 0 tidak dipakai */
/* Jika T adalah PrioQueueTimeDel, cara deklarasi dan akses: */
/* Deklarasi : T : PrioQueueTimeDel */
/* Maka cara akses:
   T.NBElmt  untuk mengetahui banyaknya elemen
   T.TI[i] untuk mengakses elemen ke-i
   T.TI[i].F untuk mengakses Food dari elemen ke-i
   T.TI[i].Time untuk mengakses Time dari elemen ke-i
*/
/* Definisi : PrioQueueTimeDel kosong: T.NBElmt = 0 */
/* Elemen yang dipakai menyimpan nilai infotypePrioQueueTimeDel yang */
/* dapat diassign ke Food F dan Time Time */
/* Jika T adalah PrioQueueTimeDel, cara deklarasi dan akses: */
/* Deklarasi : T : PrioQueueTimeDel */
/* Maka cara akses:
   T.NBElmt  untuk mengetahui banyaknya elemen
   T.TI[i] untuk mengakses elemen ke-i
   T.TI[i].F untuk mengakses Food dari elemen ke-i
   T.TI[i].Time untuk mengakses Time dari elemen ke-i
*/


/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void PrioQueueTimeDel (PrioQueueTime * Q, Food X);
/* Menghapus X dari Q. Jika X tidak ada, Q tetap */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean PrioQueueTimeIsFull (PrioQueueTime Q);
/* Mengirim true jika Q sudah penuh yaitu mengandung MaxEl elemen */
boolean PrioQueueTimeIsEmpty (PrioQueueTime Q);
/* Mengirim true jika Q kosong yaitu tidak mengandung elemen */

/* ********* Operator Dasar PrioQueueTime ********* */
void PrioQueueTimeAdd (PrioQueueTime* Q, Food X);
/* Menambahkan X pada Q dengan aturan FIFO */
void PrioQueueTimeDel (PrioQueueTime* Q, Food* X);
/* Menghapus X pada Q dengan aturan FIFO */

/* ********* Operator Tambahan ********* */
void PrioQueueTimePrint (PrioQueueTime Q);
/* Mencetak isi Q ke layar dengan format:
[<nama>, <jumlah>, <durasi>, <prioritas>]
*/

/* ********* Operasi Lain ********* */
int PrioQueueTimeNbElmt (PrioQueueTime Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

#endif