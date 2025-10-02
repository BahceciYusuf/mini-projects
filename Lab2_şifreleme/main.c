#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 100

int is_array_size_compatible(char *arr, int r, int t)
{
    if (strlen(arr) % (r + t) == 0)
    {
        printf("Sorun yok karakter sayısı uyuşuyor\n");
        return 0;
    }
    printf("Array boyutunda uyuşmazlık var!\n");
    return 1;
}

typedef struct stack
{
    char data[STACK_SIZE];
    int top;
} stack;

void create_stack(stack *st)
{
    if (!st)
        return;
    st->top = -1;
}

// Boş mu?
int is_empty(const stack *st)
{
    return (st->top == -1);
}

// Dolu mu?
int is_full(const stack *st)
{
    return (st->top == STACK_SIZE - 1);
}

// Push: başari=0, hata=1
int push(stack *st, char c)
{
    if (is_full(st))
    {
        printf("Hata: Stack dolu (overflow). Ekleme yapilamadi: '%c'\n", c);
        return 1;
    }
    st->data[++(st->top)] = c;
    return 0;
}

char pop(stack *st)
{
    if (!st || is_empty(st))
    {
        // Underflow
        return 1;
    }
    return st->data[(st->top)--];
}

// Tüm elemanları sil
void remove_all_elements(stack *st)
{
    st->top = -1;
}

// soru 3
stack *move_array_to_stack(char *arr, int t, int r)
{
    int len = (int)strlen(arr);
    int block = r + t;

    stack *array_to_stack = malloc(sizeof(stack));
    create_stack(array_to_stack);

    for (int i = 0; i < len; i += block)
    {
        for (int j = 0; j < r; j++)
        {
            push(array_to_stack, arr[i + j]);
        }
    }

    return array_to_stack;
}

// soru 4
struct stack *move_stack_to_stack(struct stack *st1, int n)
{
    stack *st2 = (stack *)malloc(sizeof(stack));
    create_stack(st2);

    for (int i = 0; i < n; i++)
    {
        if (is_empty(st1))
            break;         // st1 biterse dur
        char c = pop(st1); // pop: char döndürüyor
        push(st2, c);      
    }
    return st2;
}

int compare_stack_to_stack(struct stack *st1, struct stack *st2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!(st1->data[st1->top - i] == st2->data[st2->top - i]))
        {
            printf("Karşılaştırmada hata bulundu!\n");
            return 1;
        }
    }
    return 0;
}

// soru 6
int is_stack_compatible(struct stack *st1, int r)
{
    int n = st1->top + 1;
    if (r <= 0 || n == 0 || n % r != 0)
        return 1;

    int block_count = n / r;
    
    // Anahtar: stack'in EN ALTINDA (ilk eklenen r karakter)
    char key[STACK_SIZE];
    for (int i = 0; i < r; i++)
        key[i] = st1->data[i];

    // 2. bloktan itibaren kontrol et
    for (int blok_no = 2; blok_no <= block_count; blok_no++)
    {
        int start = (blok_no - 1) * r;  // Blokun başlangıç indexi
        
        for (int i = 0; i < r; i++)
        {
            char expected;
            if (blok_no % 2 == 0) {
                // Çift blok → TERS
                expected = key[r - 1 - i];
            } else {
                // Tek blok → DÜZ
                expected = key[i];
            }
            
            if (st1->data[start + i] != expected) {
                return 1;  // Uyumsuzluk
            }
        }
    }
    
    return 0;  // Uyumlu
}

int main()
{
    int r, t;
    char input[STACK_SIZE];

    printf("r (eleman boyutu): ");
    if (scanf("%d", &r) != 1) return 1;

    printf("t (token boyutu): ");
    if (scanf("%d", &t) != 1) return 1;

    printf("Diziyi giriniz (bosluksuz): ");
    if (scanf("%99s", input) != 1) return 1;

    // (Soru 1) Boyut kontrolü
    if (is_array_size_compatible(input, r, t) != 0) {
        printf("HATA: Dizi boyutu (r+t)*N kuralina uymuyor.\n");
        return 1;
    }

    // (Soru 3) Diziyi token'lari atarak stack'e aktar
    stack *st = move_array_to_stack(input, t, r);
    if (!st) {
        fprintf(stderr, "Hata: bellek ayirilamadi.\n");
        return 1;
    }

    // (Soru 6) Uygunluk kontrolü
    int rc = is_stack_compatible(st, r);
    if (rc == 0) {
        printf("DOGRU: Yigin sifrelemeye UYGUN.\n");
    } else {
        printf("HATA: Yigin sifrelemeye UYGUN DEGIL.\n");
    }

    free(st);
    return 0 ;
}