#ifndef TREES.H
#define TREES.H

#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode{
    treeNode * left;
    treeNode * right;
    int data;
    
}treeNode;
// Ağaca yeni bir düğüm ekler 
treeNode *Insert(treeNode *node, int data);

// Ağaçtan bir düğüm siler 
treeNode *Delete(treeNode *node, int data);

// En küçük düğümü bulur 
treeNode *FindMin(treeNode *node);

// En büyük düğümü bulur 
treeNode *FindMax(treeNode *node);


// Ağaçta bir veri arar 
treeNode *Find(treeNode *node, int data);

// Ağacı Inorder sırayla yazdırır 
void PrintInorder(treeNode *node);

// Ağacı Preorder sırayla yazdırır (
void PrintPreorder(treeNode *node);














#endif