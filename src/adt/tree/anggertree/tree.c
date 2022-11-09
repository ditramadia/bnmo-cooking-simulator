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
boolean isEmpty(List l){
    return FIRST(l) == NULL;
}
void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if (p!= NULL){
        if (!isEmpty(*l)) NEXT(p) = FIRST(*l);
        else NEXT(p) = NULL;
        FIRST(*l) = p;
    }
}
void createTree(List *l){
    FIRST(*l) = NULL;
}
void tree(int arr[][100],List l[][100],int maxElmt){
    for(int x=0;x<maxElmt;x++){
        Address p1 = newNode(arr[x][0]);
        for(int i=2;i<arr[x][1]+2;i++){
            List l1;
            createTree(&l1);
            insertFirst(&l1,arr[x][i]);
            Address pNext = FIRST(l1);
            NEXT(pNext) = p1;
            l[x][i-2] = l1;
        }
    }
}

// int main(){
//     int arr[2][10] = {{1,2,3,4},{2,3,4,5,6}};
//     List l =  *tree(arr,5);
//     printf("awkwkwkwk");
//     printf("%d",INFO(FIRST(l)));
//     printf("awkwkwkwk");

//     return 0;
// }