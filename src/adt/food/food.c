#include<stdio.h>
#include "../charmachinefood/charmachine.h"
#include "../wordmachinefood/wordmachine.c"
#include "../time/time.c"
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "food.h"
#include "../string/string.c"

void addID(Foodlist *f,int i){
    int temp;
    temp = wordToInteger();
    (*f).F[i].id = temp;
    ADVWORD();
}

void addName(Foodlist *f,int i){
    // char* y[50];
    // currentWts(y); 
    // f.F[i].name = y;
    (*f).F[i].name = currentWord;
    //displayWord(f.F[i].name);
    ADVWORD();
}

void addExpTime(Foodlist *f,int i){
    char y[50], ds[5],hs[5], ms[5];
    int d,h,m;
    currentWts(y);
    int k=0,j=0;
    while(y[k] != ' '){
        ds[j] = y[k];
        k++;
        j++;
    }
    d = atoi(ds);
    k++;

    j = 0;
    while(y[k] != BLANK){
        hs[j] = y[k];
        k++;
        j++;
    }
    h = atoi(hs);
    k++;
    j = 0;
    while(y[k] != '\0'){
        ms[j] = y[k];
        k++;
        j++;
    }
    m = atoi(ms);
    Time exptime;
    createTime(&exptime,d,h,m);
    (*f).F[i].exptime = exptime;
    ADVWORD();
}

void addDelTime(Foodlist *f,int i){
    char y[50], ds[5],hs[5], ms[5];
    int d,h,m;
    currentWts(y);
    int k=0,j=0;
    while(y[k] != ' '){
        ds[j] = y[k];
        k++;
        j++;
    }
    d = atoi(ds);
    k++;
    j = 0;
    while(y[k] != BLANK){
        hs[j] = y[k];
        k++;
        j++;
    }
    h = atoi(hs);
    k++;
    j = 0;
    while(y[k] != '\0'){
        ms[j] = y[k];
        k++;
        j++;
    }
    m = atoi(ms);
    Time deltime;
    createTime(&deltime,d,h,m);
    (*f).F[i].deltime = deltime;
    ADVWORD();
}

void addAct(Foodlist *f,int i){
    // char* y[50];
    // currentWts(y);
    // f.F[i].act = y;
    (*f).F[i].act = currentWord;
    ADVWORD();
}

void addList(Foodlist *f, int listlength){
    STARTWORD();
    // ADVWORD();
    // displayWord(currentWord);
    // printf("\n");
    // ADVWORD();
    // displayWord(currentWord);
    //     printf("\n");
    // ADVWORD();
    // displayWord(currentWord);
    //     printf("\n");
    int N,i;
    N = wordToInteger();
    listlength = N;
    ADVWORD();
    
    for (i=1;i<=N;i++){
        addID(f,i);
        addName(f,i);
        addExpTime(f,i);
        addDelTime(f,i);
        addAct(f,i);
    }
    // printf("ceklur\n");
//     printf("ceklur\n");
//     for(int temp=1; temp<=6; temp++){
//         printf("%d\n",(*f).F[temp].id);
//         displayWord((*f).F[temp].name);
//         printf("\n");
//         displayTime((*f).F[temp].exptime);
//         printf("\n");
//         displayTime((*f).F[temp].deltime);
//         printf("\n");
//         displayWord((*f).F[temp].act);
//         printf("\n");
// }
}

void listshop(Foodlist *s,Foodlist f, int listlength){
    // Foodlist s;
    // addList(f, listlength);
    int i,j=0;
    for (i=1;i<=listlength;i++){
        char y[50];
        wordToStri((f).F[i].act,y);
        if(compareString(y,"Buy")){
            (*s).F[j] = f.F[i];
            printf("%d\n",(*s).F[j].id);
            j++;
        }
        // currentWord = (f).F[i].act;
        // displayWord(currentWord);
        // wordToStri(&y);
        // printf("%s\n",y);

        // if (compareString(wordToStr(),"Buy")){
        //     (*s).F[i] = (f).F[i];
        // }
        //  printf("%d\n",(f).F[i].id);
        // displayWord((f).F[i].name);
        // printf("\n");
        // displayTime((f).F[i].exptime);
        // printf("\n");
        // displayTime((f).F[i].deltime);
        // printf("\n");
        // displayWord((f).F[i].act);
        // printf("\n");
    }
}
// int main(){
//     addList();
// }
//     // printf("ceklur\n");
//     // for(int temp=1; temp<=6; temp++){
//     //     printf("%d\n",f.F[temp].id);
//     //     printf("%s\n",f.F[temp].name);
//     //     displayTime(f.F[temp].exptime);
//     //     printf("\n");
//     //     displayTime(f.F[temp].deltime);
//     //     printf("\n");
//     //     printf("%s\n",f.F[temp].act);
//     // }
//     // Foodlist f;
//     // int mode = 0;
//     // while(currentChar != EOF){
//     //     int temp;
//     //     if(mode == 0){
//     //         mode = 1;
//     //         temp = wordToInteger();
//     //         f.F[temp].id = temp;
//     //         ADVWORD();
//     //     }
//     //     else if(mode == 1){
//     //         mode = 2;
//     //         // printf("temp = %d\n",temp);
//     //         char y[50];
//     //         wordToStri(y);
//     //         f.F[temp].name = y;
//     //         printf("aaa %s\n",f.F[1].name);
//     //         ADVWORD();
//     //     }
//     //     else if(mode == 2){
//     //         mode = 3;
//     //         char y[50], ds[5],hs[5], ms[5];
//     //         int d,h,m;
//     //         wordToStri(y);
//     //         int k=0,j=0;
//     //         while(y[k] != ' '){
//     //             ds[j] = y[k];
//     //             k++;
//     //             j++;
//     //         }
//     //         d = atoi(ds);
//     //         k++;

//     //         j = 0;
//     //         while(y[k] != BLANK){
//     //             hs[j] = y[k];
//     //             k++;
//     //             j++;
//     //         }
//     //         h = atoi(hs);
//     //         k++;

//     //         j = 0;
//     //         while(y[k] != '\0'){
//     //             ms[j] = y[k];
//     //             k++;
//     //             j++;
//     //         }
//     //         m = atoi(ms);
//     //         Time exptime;
//     //         createTime(&exptime,d,h,m);
//     //         f.F[temp].exptime = exptime;
//     //         ADVWORD();
//     //         // displayTime(exptime);
//     //     }
//     //     else if(mode == 3){
//     //         mode = 4;
//     //         char y[50], ds[5],hs[5], ms[5];
//     //         int d,h,m;
//     //         wordToStri(y);
//     //         int k=0,j=0;
//     //         while(y[k] != ' '){
//     //             ds[j] = y[k];
//     //             k++;
//     //             j++;
//     //         }
//     //         d = atoi(ds);
//     //         k++;

//     //         j = 0;
//     //         while(y[k] != BLANK){
//     //             hs[j] = y[k];
//     //             k++;
//     //             j++;
//     //         }
//     //         h = atoi(hs);
//     //         k++;

//     //         j = 0;
//     //         while(y[k] != '\0'){
//     //             ms[j] = y[k];
//     //             k++;
//     //             j++;
//     //         }
//     //         m = atoi(ms);
//     //         Time deltime;
//     //         createTime(&deltime,d,h,m);
//     //         f.F[temp].deltime = deltime;
//     //         ADVWORD();
//     //     }
//     //     else if(mode == 4){
//     //         mode = 0;
//     //         char y[50];
//     //         wordToStri(y);
//     //         f.F[temp].act = y;
//     //         ADVWORD();
//     //     }
//     //     displayWord(currentWord);
//     //     printf("\n");
//     // }

//     // printf("ceklur\n");
//     // for(int temp=1; temp<=6; temp++){
//     //     printf("%d\n",f.F[temp].id);
//     //     printf("%s\n",f.F[temp].name);
//     //     displayTime(f.F[temp].exptime);
//     //     printf("\n");
//     //     displayTime(f.F[temp].deltime);
//     //     printf("\n");
//     //     printf("%s\n",f.F[temp].act);
//      }

