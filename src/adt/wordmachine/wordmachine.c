/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

//#ifndef __MESINKATA_H__
//#define __MESINKATA_H__

#include "../boolean/boolean.h"
#include "../charmachine/charmachine.h"
#include "wordmachine.h"
#include <stdio.h>

//#define NMax 50
//#define BLANK ' '

// typedef struct
///{
// char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
// int Length;
//} Word;

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
    IgnoreBlanks();
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentWord.Length < NMax)
    {
        currentWord.TabWord[currentWord.Length] = currentChar;
        currentWord.Length++;
        ADV();
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

//#endif

void displayWord(Word W)
{
    int i;
    for (i = 0; i < W.Length; i++)
    {
        printf("%c", W.TabWord[i]);
    }
    printf(" ");
}

void wordToInteger(int *X)
{
    int i;
    int cc = 1;
    *X = 0;
    for (i = 0; i < (int)currentWord.Length - 1; i--)
    {
        *X = *X + (int)(currentWord.TabWord[i] - 48) * cc;
        cc *= 10;
    }
}

void wordToString(char y[currentWord.Length])
{
    int i;
    for (i = 0; i < currentWord.Length; i++)
    {
        y[i] = currentWord.TabWord[i];
    }