#include<stdio.h>
#include "../../adt/prioqueuetime/prioqueuetimeinv.c"
#include "../../adt/tree/tree.c"

void fry(List l[][100],PrioQueueTime q){
    int n; //kita perlu bikin panjang l[][100]
    // anggep panjang foodlist n

    
    printf("list yang bisa di fry :\n");
    int a = 0;
    char *listfood[696];

    for(int i=0; i<foodListLen;i++){
        if(compareString(wordToStr((listFood).F[i].act), "Fry")){
            displayWord((listFood).F[i].name);
            listfood[a] = wordtostr((listFood).F[i].name);
            a++;
            print("\n");
        }
    }
    char *c;
    scanf("%s",&c);
    int cek = 0;
    int idxFood;
    for(int i=0; i<foodListLen; i++){
        if(listfood[i] == c){
            cek =1;
            idxFood=i;
        };
    }
    if(!cek){
        print("tidak ada jenis makanan yang memenuhi fry, masukan ulang\n");
        scanf("%s",&c);
        for(int i=0; i<foodListLen; i++){
            if(listfood[i] == c) cek = 1;
        }
    }
    else{
        int idx;
        for(int i=0;i<n;i++){
            if(listfood[idxFood]==INFO(NEXT(FIRST(l[i][0])))){
                idx=i;
            }
        }
        int isTrue=0;
        for(int i=0;i<length(l[idx]);i++){
            for(int j=0;j<NBElmt(q);j++){
                if(INFO(FIRST(l[idx][i]))==Elmt(q,j)){
                    isTrue++;
                }
            }
        }
        if(isTrue==length(l[idx])){
            for(int i=0;i<length(l[idx]);i++){
            for(int j=0;j<NBElmt(q);j++){
                if(INFO(FIRST(l[idx][i]))==Elmt(q,j)){
                    Head(q)=Elmt(q,j);
                    int val;
                    Dequeue(&q,&val);
                }
            }
        }
        }
    }
}