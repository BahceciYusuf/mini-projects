#ifndef TREES_H
#define TREES_H

#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode{
    struct treeNode * left;
    struct treeNode * right;
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
void printInorder(treeNode *node);

// Ağacı Preorder sırayla yazdırır 
void printPreorder(treeNode *node);

// Ağacı Postorder sırayla yazdırır 
void printPostorder(treeNode *node);














#endif