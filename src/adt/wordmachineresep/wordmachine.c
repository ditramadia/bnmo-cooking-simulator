#include "boolean.h"
#include "charmachine.c"
#include "wordmachine.h"
#include <stdio.h>

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK || currentChar == '\n'){
        ADV();
    }
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    if (retval == EOF){
       EndWord = true;
    }
    else{
       EndWord = false;
       CopyWord();
}
}

void ADVWORD(){
    IgnoreBlanks();
   if (currentChar == MARK || currentChar == '\n'){
      EndWord = true;
   }
   else{
      CopyWord();
    //   IgnoreBlanks();
   }
    }

void CopyWord(){
    // IgnoreBlanks();
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentWord.Length < NMax && currentChar != '\n' && retval != EOF){
        // printf("masuk gk\n");
        currentWord.TabWord[currentWord.Length] = currentChar;
        currentWord.Length++;
        ADV();
   }
}

void displayWord(Word W){
    int i;
    for (i = 0; i < W.Length; i++){
        printf("%c", W.TabWord[i]);
    }
    printf(" ");
}

int wordToInteger(){
    int i;
    int cc = 1;
    int X = 0;
    for (i = 0; i < currentWord.Length; i++){
        // printf("pertama %c\n", currentWord.TabWord[0]);
        // printf("panjang %d\n", currentWord.Length);
        X = X*cc + (int)(currentWord.TabWord[i] - 48);
        cc*= 10;
    }
    return X;
}

void wordToString(char y[currentWord.Length]) {
    int i;
    for (i = 0; i < currentWord.Length; i++){
        y[i] = currentWord.TabWord[i];
    }
}