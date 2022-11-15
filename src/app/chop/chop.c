#include<stdio.h>
#include "../../adt/prioqueuetime/prioqueuetimeinv.c"

void chop(){
    // anggep panjang foodlist n

    
    printf("list yang bisa di chop :\n");
    int a = 0;
    char *listfood[696];

    for(int i=0; i<foodListLen;i++){
        if(compareString(wordToStr((listFood).F[i].act), "Chop")){
            displayWord((listFood).F[i].name);
            listfood[a] = wordtostr((listFood).F[i].name);
            a++;
            print("\n");
        }
    }
    char *c;
    scanf("%s",&c);
    int cek = 0;
    for(int i=0; i<foodListLen; i++){
        if(listfood[i] == c) cek = 1;
    }
    if(!cek){
        print("tidak ada jenis makanan yang memenuhi chop, masukan ulang\n");
        scanf("%s",&c);
        for(int i=0; i<foodListLen; i++){
            if(listfood[i] == c) cek = 1;
        }
    }
    else{
        
    }
}