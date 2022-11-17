#include "wordmachine.h"
#include <stdio.h>

/* State Mesin Word */
boolean EndWord;
WorD CurrentWord;

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
   if (currentChar == '\n'){
      EndWord = true;
   }
   else{
      CopyWord();
    //   IgnoreBlanks();
   }
    }

void CopyWord(){
    // IgnoreBlanks();
    CurrentWord.Lengths = 0;
    while (currentChar != BLANK && CurrentWord.Lengths < NMax && currentChar != '\n' && retval != EOF){
        // printf("masuk gk\n");
        CurrentWord.TabWords[CurrentWord.Lengths] = currentChar;
        CurrentWord.Lengths++;
        ADV();
   }
}

void displayWord(WorD W){
    int i;
    for (i = 0; i < W.Lengths; i++){
        printf("%c", W.TabWords[i]);
    }
    printf(" ");
}

int wordToInteger(){
    int i;
    int cc = 1;
    int X = 0;
    for (i = 0; i < CurrentWord.Lengths; i++){
        // printf("pertama %c\n", currentWord.TabWords[0]);
        // printf("panjang %d\n", currentWord.Lengths);
        X = X*cc + (int)(CurrentWord.TabWords[i] - 48);
        cc*= 10;
    }
    return X;
}

void wordToString(char y[CurrentWord.Lengths]) {
    int i;
    for (i = 0; i < CurrentWord.Lengths; i++){
        y[i] = CurrentWord.TabWords[i];
    }
}