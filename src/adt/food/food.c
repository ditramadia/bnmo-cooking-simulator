#include <stdio.h>
#include <stdlib.h>

#include "../wordMachineFood/wordMachineFood.h"
#include "food.h"

void addID(Foodlist *f, int i)
{
    int temp;
    temp = wordToIntegerFood();
    (*f).F[i].id = temp;
    advWordFood();
}

void addName(Foodlist *f, int i)
{
    // char* y[50];
    // CurrentWts(y);
    // f.F[i].name = y;
    (*f).F[i].name = food_currentWord;
    // displayWord(f.F[i].name);
    advWordFood();
}

void addExpTime(Foodlist *f, int i)
{
    char y[50], ds[5], hs[5], ms[5];
    int d, h, m;
    currentWts(y);
    int k = 0, j = 0;
    while (y[k] != ' ')
    {
        ds[j] = y[k];
        k++;
        j++;
    }
    d = atoi(ds);
    k++;

    j = 0;
    while (y[k] != FOOD_BLANK)
    {
        hs[j] = y[k];
        k++;
        j++;
    }
    h = atoi(hs);
    k++;
    j = 0;
    while (y[k] != '\0')
    {
        ms[j] = y[k];
        k++;
        j++;
    }
    m = atoi(ms);
    Time exptime;
    createTime(&exptime, d, h, m);
    (*f).F[i].exptime = exptime;
    advWordFood();
}

void addDelTime(Foodlist *f, int i)
{
    char y[50], ds[5], hs[5], ms[5];
    int d, h, m;
    currentWts(y);
    int k = 0, j = 0;
    while (y[k] != ' ')
    {
        ds[j] = y[k];
        k++;
        j++;
    }
    d = atoi(ds);
    k++;
    j = 0;
    while (y[k] != FOOD_BLANK)
    {
        hs[j] = y[k];
        k++;
        j++;
    }
    h = atoi(hs);
    k++;
    j = 0;
    while (y[k] != '\0')
    {
        ms[j] = y[k];
        k++;
        j++;
    }
    m = atoi(ms);
    Time deltime;
    createTime(&deltime, d, h, m);
    (*f).F[i].deltime = deltime;
    advWordFood();
}

void addAct(Foodlist *f, int i)
{
    // char* y[50];
    // CurrentWts(y);
    // f.F[i].act = y;
    (*f).F[i].act = food_currentWord;
    advWordFood();
}

void addList(Foodlist *f)
{
    startWordFood();
    int N, i;
    N = wordToIntegerFood();
    // printf("%d\n", N);

    advWordFood();

    for (i = 1; i <= N; i++)
    {
        addID(f, i);
        addName(f, i);
        addExpTime(f, i);
        addDelTime(f, i);
        addAct(f, i);
    }
}

void listshop(Foodlist *s, Foodlist f)
{
    // Foodlist s;
    // addList(f, listlength);
    int n;
    int i, j = 1;
    n = listlength(f);
    for (i = 1; i <= n; i++)
    {
        char y[50];
        wordToStri((f).F[i].act, y);
        if (compareString(y, "Buy"))
        {
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

void listfry(Foodlist *s, Foodlist f)
{
    int n;
    int i, j = 1;
    n = listlength(f);
    for (i = 1; i <= n; i++)
    {
        char y[50];
        wordToStri((f).F[i].act, y);
        if (compareString(y, "Fry"))
        {
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

void listboil(Foodlist *s, Foodlist f)
{
    int n;
    int i, j = 1;
    n = listlength(f);
    for (i = 1; i <= n; i++)
    {
        char y[50];
        wordToStri((f).F[i].act, y);
        if (compareString(y, "Boil"))
        {
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

void listchop(Foodlist *s, Foodlist f)
{
    int n;
    int i, j = 1;
    n = listlength(f);
    for (i = 1; i <= n; i++)
    {
        char y[50];
        wordToStri((f).F[i].act, y);
        if (compareString(y, "Chop"))
        {
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

void listmix(Foodlist *s, Foodlist f)
{
    int n;
    int i, j = 1;
    n = listlength(f);
    for (i = 1; i <= n; i++)
    {
        char y[50];
        wordToStri((f).F[i].act, y);
        if (compareString(y, "Mix"))
        {
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

int listlength(Foodlist f)
{
    int i = 1;
    while (f.F[i].id != 0)
    {
        i++;
    }
    return i - 1;
}