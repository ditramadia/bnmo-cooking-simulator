#include <stdio.h>
#include "tree.h"
#include <stdlib.h>

// List treeResep[100][100];

Address newNode(ElType val)
{
    Address p;
    p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        NEXT(p) = NULL;
        INFO(p) = val;
    }
    return p;
}
int isEmpty(List l)
{
    return FIRST(l) == NULL;
}
void insertFirst(List *l, ElType val)
{
    Address p = newNode(val);
    if (p != NULL)
    {
        if (!isEmpty(*l))
            NEXT(p) = FIRST(*l);
        else
            NEXT(p) = NULL;
        FIRST(*l) = p;
    }
}
void createTree(List *l)
{
    FIRST(*l) = NULL;
}

void tree(int arr[][100], List l[][100], int maxElmt)
{
    for (int x = 0; x < maxElmt; x++)
    {
        Address p1 = newNode(arr[x][0]);
        for (int i = 2; i < arr[x][1] + 2; i++)
        {
            List l1;
            createTree(&l1);
            insertFirst(&l1, arr[x][i]);
            Address pNext = FIRST(l1);
            NEXT(pNext) = p1;
            l[x][i - 2] = l1;
        }
    }
}

void makeTree(List treeResep[100][100])
{
    startWordResep();
    int length = wordToIntegerResep();
    // printf("%d\n",x);
    // ADVWORD();
    // x = wordToInteger();
    // printf("%d\n",x);
    // printf("fdsfdsfsf");
    int arr[length + 5][100];
    // printf("%s",currentChar);
    // displayWord(currentWord);
    advWordResep();
    int mode = 0, x = 0;
    while (resep_retval != EOF)
    {
        // printf("mode = %d\n", mode);
        if (mode == 0)
        {
            mode = 1;
            int temp = wordToIntegerResep();
            // printf("temp = %d\n", temp);
            arr[x / 3][0] = temp;
            advWordResep();
        }
        else if (mode == 1)
        {
            mode = 2;
            int temp = wordToIntegerResep();
            // printf("temp = %d\n", temp);
            arr[x / 3][1] = temp;
            advWordResep();
        }
        else if (mode == 2)
        {
            mode = 0;
            // printf("%d\n", arr[x / 3][1]);
            for (int i = 2; i < 2 + arr[x / 3][1]; i++)
            {
                int temp = wordToIntegerResep();
                arr[x / 3][i] = temp;
                // printf("temp = %d\n", temp);
                advWordResep();
                // printf("%d\n", i);
            }
        }
        x++;
    }
    // List treeResep[length][100];
    // createTree(&treeResep);
    tree(arr, treeResep, length);
}

// int lengthCol(List treeRresep[100][100], int idx){
//     int i=0;
//     while(treeResep[idx][i] != 0){
//         i++;
//     }
//     return i;