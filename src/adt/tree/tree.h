//
// Created by Asus on 04/11/2022.
//

#ifndef TUBES_ALSTRUKDAT_TREE_H
#define TUBES_ALSTRUKDAT_TREE_H

#include "boolean.h"
#include "../liststatik/liststatik.h"

typedef int ElType;
typedef struct node* Address;
typedef struct node {
    ElType info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

typedef Address List;

#define FIRST(l) (l)


Address newNode(ElType val);
void createTree(List l);
ListStatik tree(int arr[][],int idxTree);





#endif //TUBES_ALSTRUKDAT_TREE_H