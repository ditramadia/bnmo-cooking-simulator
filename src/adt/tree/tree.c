#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
#include "../liststatik/liststatik.c"

Address newNode(ElType val)
{
    Address p;
    p = (Address) malloc (sizeof(Node));
    if(p != NULL){
        NEXT(p) = NULL;
        INFO(p) = val;
    }
    return p;
}
void createTree(List l){
    FIRST(*l) = NULL;
}
ListStatik tree(int arr[][],int idxTree){
    Address p1 = newNode(arr[idxTree][0]);
    ListStatik l1;
    CreateListStatik(&l1);
    for(int i=2;i<arr[idxTree][1];i++){
        Address p = newNode(arr[idxTree][i]);
        List l;
        createTree(l);
        Address pNext = l;
        ELMT(l1,i-2) = l;
    }
    return l1;
}
int main(){
    printf("halooo");
    return 0;
}