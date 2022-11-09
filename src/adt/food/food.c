#include<stdio.h>
#include "../charmachinefood/charmachine.c"
#include "../wordmachinefood/wordmachine.c"
#include "../foodlist/foodlist.h"
#include "../time/time.c"
#include <stdlib.h>

    Foodlist f;
void addID(int i){
    int temp;
    temp = wordToInteger();
    printf("temp = %d\n", temp);
    Foodlist f;
    f.F[i].id = temp;
    printf("f.F[i].id = %d\n", f.F[i].id);
    ADVWORD();
}

void addName(int i){
    char y[50];
    wordToString(y);
    Foodlist f;
    f.F[i].name = y;
    ADVWORD();
}

void addExpTime(int i){
    Foodlist f;
    char y[50], ds[5],hs[5], ms[5];
    int d,h,m;
    wordToString(y);
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
    f.F[i].exptime = exptime;
    ADVWORD();
}

void addDelTime(int i){
    Foodlist f;
    char y[50], ds[5],hs[5], ms[5];
    int d,h,m;
    wordToString(y);
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
    f.F[i].deltime = deltime;
    ADVWORD();
}

void addAct(int i){
    char y[50];
    wordToString(y);
    Foodlist f;
    f.F[i].act = y;
    ADVWORD();
}

void addList(){
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
    ADVWORD();
    
    for (i=1;i<=N;i++){
        addID(i);
        addName(i);
        addExpTime(i);
        addDelTime(i);
        addAct(i);
    }
}
int main(){
    addList();
    printf("ceklur\n");
    for(int temp=1; temp<=6; temp++){
        printf("%d\n",f.F[temp].id);
        // printf("%s\n",f.F[temp].name);
        // displayTime(f.F[temp].exptime);
        // printf("\n");
        // displayTime(f.F[temp].deltime);
        // printf("\n");
        // printf("%s\n",f.F[temp].act);
    }
    // Foodlist f;
    // int mode = 0;
    // while(currentChar != EOF){
    //     int temp;
    //     if(mode == 0){
    //         mode = 1;
    //         temp = wordToInteger();
    //         f.F[temp].id = temp;
    //         ADVWORD();
    //     }
    //     else if(mode == 1){
    //         mode = 2;
    //         // printf("temp = %d\n",temp);
    //         char y[50];
    //         wordToString(y);
    //         f.F[temp].name = y;
    //         printf("aaa %s\n",f.F[1].name);
    //         ADVWORD();
    //     }
    //     else if(mode == 2){
    //         mode = 3;
    //         char y[50], ds[5],hs[5], ms[5];
    //         int d,h,m;
    //         wordToString(y);
    //         int k=0,j=0;
    //         while(y[k] != ' '){
    //             ds[j] = y[k];
    //             k++;
    //             j++;
    //         }
    //         d = atoi(ds);
    //         k++;

    //         j = 0;
    //         while(y[k] != BLANK){
    //             hs[j] = y[k];
    //             k++;
    //             j++;
    //         }
    //         h = atoi(hs);
    //         k++;

    //         j = 0;
    //         while(y[k] != '\0'){
    //             ms[j] = y[k];
    //             k++;
    //             j++;
    //         }
    //         m = atoi(ms);
    //         Time exptime;
    //         createTime(&exptime,d,h,m);
    //         f.F[temp].exptime = exptime;
    //         ADVWORD();
    //         // displayTime(exptime);
    //     }
    //     else if(mode == 3){
    //         mode = 4;
    //         char y[50], ds[5],hs[5], ms[5];
    //         int d,h,m;
    //         wordToString(y);
    //         int k=0,j=0;
    //         while(y[k] != ' '){
    //             ds[j] = y[k];
    //             k++;
    //             j++;
    //         }
    //         d = atoi(ds);
    //         k++;

    //         j = 0;
    //         while(y[k] != BLANK){
    //             hs[j] = y[k];
    //             k++;
    //             j++;
    //         }
    //         h = atoi(hs);
    //         k++;

    //         j = 0;
    //         while(y[k] != '\0'){
    //             ms[j] = y[k];
    //             k++;
    //             j++;
    //         }
    //         m = atoi(ms);
    //         Time deltime;
    //         createTime(&deltime,d,h,m);
    //         f.F[temp].deltime = deltime;
    //         ADVWORD();
    //     }
    //     else if(mode == 4){
    //         mode = 0;
    //         char y[50];
    //         wordToString(y);
    //         f.F[temp].act = y;
    //         ADVWORD();
    //     }
    //     displayWord(currentWord);
    //     printf("\n");
    // }

    // printf("ceklur\n");
    // for(int temp=1; temp<=6; temp++){
    //     printf("%d\n",f.F[temp].id);
    //     printf("%s\n",f.F[temp].name);
    //     displayTime(f.F[temp].exptime);
    //     printf("\n");
    //     displayTime(f.F[temp].deltime);
    //     printf("\n");
    //     printf("%s\n",f.F[temp].act);
    // }
}