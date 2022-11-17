/* File: wordmachine.h */
/* Definisi word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean/boolean.h"
#include "../charmachinefood/charmachine.c"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} word;

/* State Mesin word */
extern boolean Endword;
extern word Currentword;

void IgnoreBlanksFood();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORDFOOD();
/* I.S. : currentChar sembarang
   F.S. : Endword = true, dan currentChar = MARK;
          atau Endword = false, Currentword adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDFOOD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : Currentword adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, Endword = true.
   Proses : Akuisisi kata menggunakan procedure Salinword */

void CopyWordFood();
/* Mengakuisisi kata, menyimpan dalam Currentword
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : Currentword berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void displayWordFood(word W);

#endif