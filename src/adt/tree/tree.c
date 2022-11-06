#include <stdio.h>
#include "tree.h"
#include <stdlib.h>

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
void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if (p!= NULL){
        if (!isEmpty(*l)) NEXT(p) = FIRST(*l);
        else NEXT(p) = NULL;
        FIRST(*l) = p;
    }
}
void createTree(List l){
    FIRST(l) = NULL;
}
List *tree(int arr[][],int idxTree){
    Address p1 = newNode(arr[idxTree][0]);
    List l2[100];
    for(int i=2;i<arr[idxTree][1];i++){
        List l;
        createTree(l);
        insertFirst(&l,arr[idxTree][i]);
        Address pNext = l;
        NEXT(pNext) = p1;
        l2[i-2] = l;
    }
    return l2;
}