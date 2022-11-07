#include "../boolean/boolean.h"
#include "../food/food.h"
#include "prioqueuetimeinv.h"
#include <stdio.h>

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
#define Time(e) (e).time
#define Info(e) (e).info
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define Elmt(Q, i) (Q).T[(i)]

void PrintPrioQueueTime(PrioQueueTime Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
{
    infotype val;
    PrioQueueTime temp;
    temp = Q;
    if (!IsEmpty(Q))
    {
        while (!IsEmpty(temp))
        {
            Dequeue(&temp, &val);
            printf("%d %c\n", Time(val), Info(val));
        }
    }
    printf("#\n");
}


void displayDelivery(PrioQueueTime Q)
{
    infotype val;
    PrioQueueTime temp;
    temp = Q;
    int i = 1;
    if (IsEmpty(Q))
    {
        printf("Tidak ada makanan di perjalanan\n");
    }
    else
    {
        printf("List Makanan di Perjalanan\n");
        printf("(Nama - Waktu Sisa Delivery)\n")
        if (!IsEmpty(Q))
        {
            while (!IsEmpty(temp))
            {
                Dequeue(&temp, &val);
                printf("%i. %d %c\n", i, Time(val), Info(val));
            }
        }
    }
}