#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Number
{
    char typeOfNumber[20];
    char number[20];
    struct Number *next;

} Number;

typedef struct Person
{
    char name[50];
    struct Person *next;
    struct Person *previous;
    struct Number *numbers;

} Person;

void addPerson(Person **head, char newName[])
{

    Person *newNode = (Person *)malloc(sizeof(Person));
    if (newNode == NULL)
    {
        printf("Bellek ayrılamadı!\n");
        return;
    }
    strcpy(newNode->name, newName);
    newNode->numbers = NULL;
    newNode->next = NULL;
    newNode->previous = NULL;


    if (*head == NULL || strcmp(newName, (*head)->name) < 0)
    {
        newNode->next = *head;
        if (*head != NULL)
        {
            (*head)->previous = newNode;
        }
        *head = newNode;
        return;
    }


    Person *current = *head;
    while (current->next != NULL && strcmp(newName, current->next->name) > 0)
    {
        current = current->next;
    }


    newNode->next = current->next;
    if (current->next != NULL)
    {
        newNode->next->previous = newNode;
    }
    current->next = newNode;
    newNode->previous = current;
}

void addNumber(Person *head, char name[], char type[], char number[])
{
    Person *current = head;
    while (current != NULL && strcmp(name, current->name) != 0)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("HATA: '%s' isimli kişi listede bulunamadı.\n", name);
        return;
    }

    Number *newNumber = (Number *)malloc(sizeof(Number));
    if (newNumber == NULL)
    {
        printf("Bellek ayrılamadı!\n");
        return;
    }

    strcpy(newNumber->typeOfNumber, type);
    strcpy(newNumber->number, number);
    newNumber->next = NULL;

    if (current->numbers == NULL)
    {
        current->numbers = newNumber;
    }
    else
    {
        Number *temp = current->numbers;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNumber;
    }
    printf("'%s' kişisine '%s' numarası başarıyla eklendi.\n", name, number);
}

void removePerson(Person **head, char name[])
{
    Person *current = *head;
    while (current != NULL && strcmp(current->name, name) != 0)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Böyle bir kişi rehberde yok!\n");
        return;
    }

    Number *temp = current->numbers;
    while (temp != NULL)
    {
        Number *num_to_delete = temp;
        temp = temp->next;
        free(num_to_delete);
    }
    printf("'%s' kişisine ait tüm numaralar silindi.\n", name);

    if (current->previous == NULL)
    {
        *head = current->next;
        if (*head != NULL)
        {
            (*head)->previous = NULL;
        }
    }

    else
    {
        current->previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->previous = current->previous;
        }
    }

    free(current);
    printf("'%s' kişisi rehberden başarıyla silindi.\n", name);
}

void removeNumber(Person *head, char name[], char numToDel[])
{

    Person *current_person = head;
    while (current_person != NULL && strcmp(current_person->name, name) != 0)
    {
        current_person = current_person->next;
    }

    if (current_person == NULL)
    {
        printf("HATA: '%s' isimli kişi rehberde bulunamadı!\n", name);
        return;
    }

    Number *current_num = current_person->numbers;
    Number *previous_num = NULL;

    while (current_num != NULL && strcmp(current_num->number, numToDel) != 0)
    {
        previous_num = current_num;
        current_num = current_num->next;
    }

    if (current_num == NULL)
    {
        printf("HATA: '%s' numarası bu kişide bulunamadı!\n", numToDel);
        return;
    }

    if (previous_num == NULL)
    {
        current_person->numbers = current_num->next;
    }
    else
    {

        previous_num->next = current_num->next;
    }

    free(current_num);
    printf("Numara başarıyla silindi.\n");
}

void updatePerson(Person **head, char name[])
{
    Person *current = *head;
    while (current != NULL && strcmp(current->name, name) != 0)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("HATA: '%s' isimli kişi rehberde bulunamadı!\n", name);
        return;
    }

    char new_name[50];
    printf("'%s' için yeni ismi giriniz: ", name);
    scanf("%s", new_name);

    if (strcmp(name, new_name) == 0)
    {
        printf("İsim değiştirilmedi.\n");
        return;
    }

    if (current->previous == NULL)
    {
        *head = current->next;
        if (*head != NULL)
        {
            (*head)->previous = NULL;
        }
    }

    else if (current->next == NULL)
    {
        current->previous->next = NULL;
    }

    else
    {
        current->previous->next = current->next;
        current->next->previous = current->previous;
    }
    strcpy(current->name, new_name);

    Person *temp = *head;

    while (temp != NULL && strcmp(current->name, temp->name) > 0)
    {
        temp = temp->next;
    }

    if (temp == *head)
    {
        current->next = *head;
        current->previous = NULL;
        if (*head != NULL)
        {
            (*head)->previous = current;
        }
        *head = current;
    }

    else if (temp == NULL)
    {
        Person *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = current;
        current->previous = last;
        current->next = NULL;
    }

    else
    {
        current->next = temp;
        current->previous = temp->previous;
        temp->previous->next = current;
        temp->previous = current;
    }

    printf("'%s' ismi '%s' olarak güncellendi.\n", name, new_name);
}

void updateNumber(Person **head, char name[], char oldNumb[], char newNumb[])
{
    Person *current = *head;
    while (current != NULL && strcmp(current->name, name) != 0)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("HATA: '%s' isimli kişi rehberde bulunamadı!\n", name);
        return;
    }

    Number *temp = current->numbers;

    while (temp != NULL && strcmp(temp->number, oldNumb) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("HATA: '%s' numara rehberde bulunamadı!\n", oldNumb);
        return;
    }

    strcpy(temp->number, newNumb);
    printf("İşlem başarılı: Numara '%s' olarak güncellendi.\n", newNumb);
}

void search(Person *head, char name[])
{
    Person *current = head;

    while (current != NULL)
    {
        int comparison = strcmp(current->name, name);

        if (comparison == 0)
        {
            break;
        }

        if (comparison > 0)
        {
            current = NULL;
            break;
        }

        current = current->next;
    }
    if (current == NULL)
    {
        printf("'%s' isimli kişi rehberde bulunamadı.\n", name);
    }
    else
    {
        printf("--- Arama Sonucu ---\n");
        printf("İsim: %s\n", current->name);

        Number *num_iter = current->numbers;
        if (num_iter == NULL)
        {
            printf("-> Bu kişiye ait kayıtlı numara yok.\n");
        }
        else
        {
            printf("Telefon Numaraları:\n");
            while (num_iter != NULL)
            {
                printf("-> %s: %s\n", num_iter->typeOfNumber, num_iter->number);
                num_iter = num_iter->next;
            }
        }
        printf("---------------------\n");
    }
}

void list(Person *head)
{
    if (head == NULL)
    {
        printf("Telefon rehberi boş.\n");
        return;
    }

    printf("--- TÜM REHBER ---\n");
    Person *current_person = head;

    while (current_person != NULL)
    {
        printf("\nİsim: %s\n", current_person->name);

        Number *current_number = current_person->numbers;
        if (current_number == NULL)
        {
            printf("-> Kayıtlı numara yok.\n");
        }
        else
        {

            while (current_number != NULL)
            {
                printf("-> %s: %s\n", current_number->typeOfNumber, current_number->number);
                current_number = current_number->next;
            }
        }

        current_person = current_person->next;
    }
    printf("\n--------------------\n");
}

int main()
{
    Person *head = NULL; 

    printf("--- 1. Kişiler Ekleniyor (Alfabetik Sıra Testi) ---\n");
    addPerson(&head, "Emel");
    addPerson(&head, "Seda");
    addPerson(&head, "Ali"); 
    addPerson(&head, "Cem");
    list(head);

    printf("\n--- 2. Numaralar Ekleniyor ---\n");
    addNumber(head, "Ali", "home", "02122340001");
    addNumber(head, "Ali", "mobile", "05331230001");
    addNumber(head, "Seda", "work", "02169870001");
    addNumber(head, "Emel", "mobile", "05421230001");
    addNumber(head, "Zeynep", "home", "11111"); // Hata vermesi gerek
    list(head);

    printf("\n--- 3. Arama Fonksiyonu Testi ---\n");
    printf("-> 'Cem' aranıyor (numarası yok):\n");
    search(head, "Cem");
    printf("\n-> 'Seda' aranıyor:\n");
    search(head, "Seda");
    printf("\n-> 'Barış' aranıyor (listede yok, optimizasyon testi):\n");
    search(head, "Baris");

    printf("\n--- 4. Numara Güncelleme Testi ---\n");
    printf("'Ali'nin 'home' numarası güncelleniyor...\n");
    updateNumber(&head, "Ali", "02122340001", "0212YENINUMARA");
    search(head, "Ali");

    printf("\n--- 5. Numara Silme Testi ---\n");
    printf("'Ali'nin 'mobile' numarası siliniyor...\n");
    removeNumber(head, "Ali", "05331230001");
    search(head, "Ali");

    printf("\n--- 6. Kişi Güncelleme Testi (Alfabetik Sıra) ---\n");
    updatePerson(&head, "Emel"); 
    list(head);

    printf("\n--- 7. Kişi Silme Testi ---\n");
    printf("'Cem' siliniyor...\n");
    removePerson(&head, "Cem");
    printf("\n'Ali' siliniyor (Listenin başı siliniyor)...\n");
    removePerson(&head, "Ali");
    list(head);

    printf("\n--- Test Tamamlandı ---\n");

    return 0;
}