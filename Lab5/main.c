#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h> // gettimeofday (hassas zaman ölçümü) için

typedef struct treeNode
{
    struct treeNode *left;
    struct treeNode *right;
    int data;
} treeNode;

treeNode *FindMin(treeNode *node);
treeNode *Delete(treeNode *node, int data);
treeNode *Find(treeNode *node, int data);

treeNode *GetNewNode(int data)
{
    treeNode *temp = (treeNode *)malloc(sizeof(treeNode));
    if (temp == NULL)
    {
        fprintf(stderr, "Bellek Ayırma Hatası (GetNewNode)\n");
        exit(1);
    }
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

treeNode *Insert(treeNode *node, int data)
{
    if (node == NULL)
    {
        return GetNewNode(data);
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

    else // Düğüm bulundu (data == node->data)
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
        return NULL;
    }
    treeNode *temp = node;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

treeNode *Find(treeNode *node, int data)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->data == data)
        return node;
    else
    {
        if (data > node->data) // data büyükse sağa git
            return Find(node->right, data);
        if (data < node->data) // data küçükse sola git
            return Find(node->left, data);
    }
    return NULL;
}

treeNode *ReadFromFileAndBuildTree(const char *filename, treeNode *root)
{
    FILE *file;
    file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "HATA: '%s' dosyası açılamadı.\n", filename);
        return root;
    }
    int number;
    while (fscanf(file, "%d", &number) == 1)
    {
        root = Insert(root, number);
    }
    fclose(file);
    printf(" '[MADDE 1]'%s' dosyası ile BST başarıyla oluşturuldu.\n", filename);
    return root;
}

// Inorder (Sol-Kök-Sağ)
void printFirst10Inorder(treeNode *node, int *count)
{
    const int max_count = 10;
    if (node == NULL || *count >= max_count)
    {
        return;
    }

    printFirst10Inorder(node->left, count);

    if (*count < max_count)
    {
        printf("%d ", node->data);
        (*count)++;
    }
    if (*count < max_count)
    {
        printFirst10Inorder(node->right, count);
    }
}

void printFirst10Preorder(treeNode *node, int *count)
{
    const int max_count = 10;
    if (node == NULL || *count >= max_count)
    {
        return;
    }

    if (*count < max_count)
    {
        printf("%d ", node->data);
        (*count)++;
    }

    if (*count < max_count)
    {
        printFirst10Preorder(node->left, count);
    }
    if (*count < max_count)
    {
        printFirst10Preorder(node->right, count);
    }
}

// Postorder (Sol-Sağ-Kök)
void printFirst10Postorder(treeNode *node, int *count)
{
    const int max_count = 10;

    if (node == NULL || *count >= max_count)
    {
        return;
    }
    printFirst10Postorder(node->left, count);
    printFirst10Postorder(node->right, count);

    if (*count < max_count)
    {
        printf("%d ", node->data);
        (*count)++;
    }
}

// Inorder
void printInorder(treeNode *node)
{
    if (node != NULL)
    {
        printInorder(node->left);
        printf("%d ", node->data);
        printInorder(node->right);
    }
}

double measureSearchTime(treeNode *root, int data)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    Find(root, data);

    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    return (double)seconds + (double)microseconds / 1000000.0;
}

int main()
{
    srand(time(NULL));

    char dosya1[] = "bst1.txt";
    char dosya2[] = "bst2.txt";

    treeNode *root1 = NULL;
    treeNode *root2 = NULL;

    root1 = ReadFromFileAndBuildTree(dosya1, root1);
    root2 = ReadFromFileAndBuildTree(dosya2, root2);

    printf("                  MADDE 2: ILK 10 ELEMAN\n");

    int count;

    // Inorder
    count = 0;
    printf("\n--- BST 1: Inorder (En Kucuk 10 Sayi) ---\n");
    printFirst10Inorder(root1, &count);
    printf("\n");

    // Preorder
    count = 0;
    printf("\n--- BST 1: Preorder ---\n");
    printFirst10Preorder(root1, &count);
    printf("\n");

    // Postorder
    count = 0;
    printf("\n--- BST 1: Postorder ---\n");
    printFirst10Postorder(root1, &count);
    printf("\n");

    printf("                MADDE 3: RASTGELE SILME\n");

    int random_data = (rand() % 5000);

    printf("Oluşturulan rastgele sayı: %d\n", random_data);

    // BST 1
    treeNode *found_node = Find(root1, random_data);
    if (found_node != NULL)
    {
        printf("BST 1'de Sayı (%d) bulundu. Siliniyor.\n", random_data);
        root1 = Delete(root1, random_data);
        printf("BST 1'den silme işlemi başarılı.\n");
    }
    else
    {
        printf("BST 1'de Sayı (%d) bulunamadı. Silme yok.\n", random_data);
    }

    printf("                MADDE 4: ARAMA ZAMANLARI\n");

    random_data = (rand() % 5000);
    double time1 = measureSearchTime(root1, random_data);
    printf("BST 1 (Ağaç 1) üzerinde %d arama süresi: %.7f saniye\n", random_data, time1);

    double time2 = measureSearchTime(root2, random_data);
    printf("BST 2 (Ağaç 2) üzerinde %d arama süresi: %.7f saniye\n", random_data, time2);

    if (time1 < time2)
    {
        printf("\nSonuç: BST 1'deki arama, BST 2'den daha hızlı gerçekleşti.\n");
    }
    else if (time1 > time2)
    {
        printf("\nSonuç: BST 2'deki arama, BST 1'den daha hızlı gerçekleşti.\n");
    }
    else
    {
        printf("\nSonuç: İki ağaçtaki arama süresi neredeyse aynıdır.\n");
    }

    return 0;
}