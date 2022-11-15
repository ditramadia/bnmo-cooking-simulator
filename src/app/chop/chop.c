#include<stdio.h>

void chop(){
    // anggep foodlist itu f di global
    // anggep panjang foodlist n

    
    print("list yang bisa di chop :\n");
    int a = 0;
    char *listfood[696];

    for(int i=0; i<n;i++){
        Word w = chop;
        if((f).F[i].act == w){
            displayWord((f).F[i].nama);
            listfood[a] = wordtostr((f).F[i].nama);
            a++;
            print("\n");
        }
    }
    char *c;
    scanf("%s",&c);
    int cek = 0;
    for(int i=0; i<n; i++){
        if(listfood[i] == c) cek = 1;
    }
    if(!cek){
        print("tidak ada jenis makanan yang memenuhi chop, masukan ulang\n")
        for(int i=0; i<n; i++){
            if(listfood[i] == c) cek = 1;
        }
    }
    else{

    }

}