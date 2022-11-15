#include<stdio.h>

void boil(){
    // anggep foodlist itu f di global
    // anggep panjang foodlist n

    
    print("list yang bisa di boil :\n")
    int a = 0;
    char *listfood[696];

    for(int i=0; i<n;i++){
        Word w = boil;
        if((f).F[i].act == w){
            displayWord((f).F[i].nama);
            listfood[a] = wordtostr((f).F[i].nama)
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
        print("tidak ada jenis makanan yang memenuhi boil, masukan ulang\n")
        for(int i=0; i<n; i++){
            if(listfood[i] == c) cek = 1;
        }
    }
    else{
    /* cek di inventory apakah ada sesuai dengan c
        jika ada, maka search loop foodlist apakah ada yg info(next(first)) nya sesuai
        dengan yang kita cari, jika ada maka dihapus di inventory childnya dan diganti dengan
        yang baru
        jika tidak ada, gagal melakukan operasi "boil"
    */
    }

}