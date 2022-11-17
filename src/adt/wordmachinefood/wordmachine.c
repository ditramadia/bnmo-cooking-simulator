#include "wordmachine.h"
#include <stdio.h>

/* State Mesin word */
boolean EndWord;
word Currentword;

void IgnoreBlanks(){
    while (currentChar == BLANK || currentChar == '\n'){
        ADV();
    }
}

void STARTWORD(){
    START();
    //IgnoreBlanks();
    if (currentChar == '\n'){
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
    Currentword.Length = 0;
    while ( currentChar != MARK && Currentword.Length < NMax && currentChar != '\n' && retval != EOF){
        // printf("masuk gk\n");
        Currentword.TabWord[Currentword.Length] = currentChar;
        Currentword.Length++;
        ADV();
   }
}

void displayWord(word W){
    int i;
    for (i = 0; i < W.Length; i++){
        printf("%c", W.TabWord[i]);
    }
    //printf(" ");
}

int wordToInteger(){
    int i;
    int cc = 1;
    int X = 0;
    for (i = 0; i < Currentword.Length; i++){
        while(Currentword.TabWord[i] == ' '){
            i++;
        }
        X = X*cc + (int)(Currentword.TabWord[i] - 48);
        cc*= 10;
    }
    return X;
}

void wordToStri(word w, char *str)
{
    int i = 0;
    while (i < w.Length)
    {
    // printf("masuk kh");
        str[i] = w.TabWord[i];
        // printf("%c",str[i]);
        i++;
    }
    str[i] = '\0';
}

void currentWts(char *y) {
    int i;
    for (i = 0; i < Currentword.Length; i++){
        y[i] = Currentword.TabWord[i];
    }
}