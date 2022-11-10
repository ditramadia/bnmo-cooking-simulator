/* File : pqt.h */
/* ini pakai array biasa, atau mungkin yang tau jadwal you*/
#include "../boolean/boolean.h"
#include "../food/food.h"
#include "../time/time.h"

#define IDX_UNDEF -1
// #define CAPACITY 100

/* Definisi elemen dan address */
typedef Food ElType;
typedef struct
{
        ElType buffer[CAPACITY];
        int head;
        int tail;
} PrioQueueDel;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).head
#define IDX_TAIL(q) (q).tail
#define     HEAD(q) (q).buffer[(q).head]
#define     TAIL(q) (q).buffer[(q).tail]

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}