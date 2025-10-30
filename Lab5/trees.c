#include "trees.h"

treeNode *Insert(treeNode *node, int data)
{
    if (node == NULL)
    {
        treeNode *temp = (treeNode *)malloc(sizeof(treeNode));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (node->data < data)
    {
        node->right = Insert(node->right, data);
    }

    else if (node->data > data)
    {
        node->left = Insert(node->left, data);
    }

    return node;
}

treeNode *Delete(treeNode *node, int data)
{
    treeNode *temp;
    if (node == NULL)
    {
        return NULL;
    }

    if (data < node->data)
    {
        node->left = Delete(node->left, data);
    }

    else if (data > node->data)
    {
        node->right = Delete(node->right, data);
    }

    // bulunursa else e girecek
    else
    {
        if (node->right && node->left)
        {
            temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }

        else
        {
            temp = node;
            if (node->right == NULL)
            {
                node = node->left;
            }
            else if (node->left == NULL)
            {
                node = node->right;
            }
            free(temp);
        }
    }
    return node;
}

treeNode *FindMin(treeNode *node)
{

    if (!node)
    {
        printf("Tree is empty!\n");
        return NULL;
    }
    treeNode *temp = node;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

treeNode *FindMax(treeNode *node)
{

    if (!node)
    {
        printf("Tree is empty!\n");
        return NULL;
    }
    treeNode *temp = node;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

treeNode *Find(treeNode *node, int data)
{
    if (!node)
    {
        return NULL;
    }

    if (node->data == data)
        return node;

    if (data < node->data)
        return Find(node->left, data);
    else
        return Find(node->right, data);
}

void printPreorder(treeNode *node){
    if(node!=NULL){
        printf("%d \n",node->data);
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

void printPostorder(treeNode *node){
    if(node!=NULL){
        printPostorder(node->left);
        printPostorder(node->right);
        printf("%d \n",node->data);
    }
}

void printInorder(treeNode *node){
    if(node!=NULL){
        printInorder(node->left);
        printf("%d \n",node->data);
        printInorder(node->right);
    }
}
