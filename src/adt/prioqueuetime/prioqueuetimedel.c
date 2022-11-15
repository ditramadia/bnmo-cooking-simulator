#include "../boolean/boolean.h"
#include "../food/food.h"
#include "prioqueuetimedel.h"
/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
boolean IsEmpty(PrioQueueTime Q)
/* Mengirim true jika Q kosong: Head(Q) = Tail(Q) = NIL */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull(PrioQueueTime Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (length(Q) == MaxEl(Q));
}

int length(PrioQueueTime Q)
/* Mengirimkan   banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q))
    {
        return 0;
    }
    else
    {
        if (Tail(Q) >= Head(Q))
        {
            return (Tail(Q) - Head(Q) + 1);
        }
        else
        {
            return (MaxEl(Q) - (Head(Q) - Tail(Q) + 1));
        }
    }
}

/* *** Kreator *** */
void MakeEmpty(PrioQueueTime *Q, int Max)
{
    (*Q).T = (Food *)malloc((Max) * sizeof(Food));
    if ((*Q).T == NULL)
    {
        MaxEl(*Q) = 0;
    }
    else
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
}

/* ********* Operator Dasar PrioQueueTime ********* */
void enqueue(PrioQueueTime* Q, Food X)
{
    boolean found;
    int idx;
    int i, j;
    Food temp;
    if (IsEmpty(*Q))
    {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else
    {
        Tail(*Q) = Tail(*Q) == MaxEl(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
        while (i != Head(*Q) && timeToMinute((*Q).T[i].deltime) < timeToMinute((*Q).T[j].deltime))
        {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
        }
    }
}
void dequeue(PrioQueueTime* Q, Food* X)
{
    *X = InfoHead(*Q);
    if (length(*Q) == 1)
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        Head(*Q) = (Head(*Q) == MaxEl(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
}

/* ********* Operator Tambahan ********* */
void PrintPrioQueueTime(PrioQueueTime Q)
{
    Food F;
    PrioQueueTime temp;
    MakeEmpty(&temp, MaxEl(Q));
    while (!IsEmpty(Q))
    {
        Dequeue(&Q, &F);
        Enqueue(&temp, F);
    }
    if (!IsEmpty(temp))
    {
        printf("#\n");
        while (!IsEmpty(temp))
        {
            Dequeue(&temp, &F);
            Enqueue(&Q, F);
            displayWord(F.name);
            printf("\n");
            displayTime(F.deltime);
            printf("\n");
            // printf("%d %c\n", ExpTime(F), Name(F));
        }
    }
    printf("#\n");
}


// void displayDelivery(PrioQueueTime Q)
// {
//     infotypePrioQueueTimeDel val;
//     PrioQueueTime temp;
//     temp = Q;
//     int i = 1;
//     if (IsEmpty(Q))
//     {
//         printf("Tidak ada makanan di perjalanan\n");
//     }
//     else
//     {
//         printf("List Makanan di Perjalanan\n");
//         printf("(Nama - Waktu Sisa Delivery)\n");
//         if (!IsEmpty(Q))
//         {
//             while (!IsEmpty(temp))
//             {
//                 Dequeue(&temp, &val);
//                 printf("%i. %d %c\n", i, Time(val), Info(val));
//             }
//         }
//     }
// }