#include<stdio.h>
#include<stdlib.h>
#include "food.h"

void addID(Foodlist *f,int i){
    int temp;
    temp = wordToInteger();
    (*f).F[i].id = temp;
    ADVWORD();
}

void addName(Foodlist *f,int i){
    // char* y[50];
    // CurrentWts(y); 
    // f.F[i].name = y;
    (*f).F[i].name = Currentword;
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
    // CurrentWts(y);
    // f.F[i].act = y;
    (*f).F[i].act = Currentword;
    ADVWORD();
}

void addList(Foodlist *f, int listlength){
    STARTWORD();
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
}

void listshop(Foodlist *s,Foodlist f){
    // Foodlist s;
    // addList(f, listlength);
    int n;
    int i,j=1;
    n = listlength(f);
    for (i=1;i<=n;i++){
        char y[50];
        wordToStri((f).F[i].act,y);
        if(compareString(y,"Buy")){
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

void listfry(Foodlist *s,Foodlist f){
    int n;
    int i,j=1;
    n = listlength(f);
    for (i=1;i<=n;i++){
        char y[50];
        wordToStri((f).F[i].act,y);
        if(compareString(y,"Fry")){
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

void listboil(Foodlist *s,Foodlist f){
    int n;
    int i,j=1;
    n = listlength(f);
    for (i=1;i<=n;i++){
        char y[50];
        wordToStri((f).F[i].act,y);
        if(compareString(y,"Boil")){
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

void listchop(Foodlist *s,Foodlist f){
    int n;
    int i,j=1;
    n = listlength(f);
    for (i=1;i<=n;i++){
        char y[50];
        wordToStri((f).F[i].act,y);
        if(compareString(y,"Chop")){
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

void listmix(Foodlist *s,Foodlist f){
    int n;
    int i,j=1;
    n = listlength(f);
    for (i=1;i<=n;i++){
        char y[50];
        wordToStri((f).F[i].act,y);
        if(compareString(y,"Mix")){
            (*s).F[j] = f.F[i];
            // printf("%d\n",(*s).F[j].id);
            j++;
        }
    }
}

int listlength(Foodlist f){
    int i=1;
    while(f.F[i].id != 0){
        i++;
    }
    return i;
}