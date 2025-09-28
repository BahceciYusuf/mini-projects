#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Room
{
    int room_number;
    float price_per_night;
    bool is_occupied;
} Room;

typedef struct Guest
{
    int guest_id;
    char name[50];
    Room *assigned_room;
    float total_payment;
    int previous_stays;
} Guest;

Guest *create_guest(int guest_id, char *name)
{
    Guest *g = (Guest *)malloc(sizeof(Guest));
    if (!g)
    {
        printf("Bellek Ayırma Sorunu\n");
        return NULL;
    }
    g->guest_id = guest_id;
    strcpy(g->name, name);
    g->assigned_room = NULL;
    g->total_payment = 0.0;
    g->previous_stays = 0;
    return g;
}
void Rezervasyon(Guest *guest, Room *room, int night)
{
    if (room->is_occupied)
    {
        printf("Oda dolu!\n");
        return;
    };
    guest->assigned_room = room;
    float cost = room->price_per_night * night;
    if (guest->previous_stays == 0)
    {
        printf("Hoş Geldiniz ilk sefere özel %%20 indirim! \n");
        guest->total_payment += cost * 0.8;
    }
    else
        guest->total_payment += cost;
    room->is_occupied = true;
    guest->previous_stays++;
    printf("%s için %d numaralı odamız rezerve edildi. Toplam Ödeme : %.2f Dolar\n", guest->name, guest->assigned_room->room_number, guest->total_payment);
    return;
}
Guest *enCokKalan(Guest *guests[], int size)
{
    Guest *max_stay_guest = guests[0];
    for (int i = 0; i < size; i++)
    {
        if (guests[i]->previous_stays > max_stay_guest->previous_stays)
        {
            max_stay_guest = guests[i];
        }
    }
    return max_stay_guest;
}

Guest *enCokOdeyen(Guest *guests[], int size)
{
    Guest *max_pay_guest = guests[0];
    for (int i = 0; i < size; i++)
    {
        if (guests[i]->total_payment > max_pay_guest->total_payment)
        {
            max_pay_guest = guests[i];
        }
    }
    return max_pay_guest;
}

int main()
{

    Room rooms[3] = {{101, 100, false}, {102, 200, false}, {103, 300, false}};

    Guest *g1 = create_guest(1, "Yusuf");
    Guest *g2 = create_guest(2, "Bahceci");
    Guest *g3 = create_guest(3, "Can");

    Rezervasyon(g3, &rooms[0], 3);
    Rezervasyon(g3, &rooms[1], 2);
    Rezervasyon(g3, &rooms[2], 1);

    Guest *guests[] = {g1, g2, g3};
    Guest *mxStay = enCokKalan(guests, 3);
    Guest *mxPay = enCokOdeyen(guests, 3);

    if (mxStay)
        printf("En cok rezervasyon yapan: %s (%d kez)\n",
               mxStay->name, mxStay->previous_stays);
    if (mxPay)
        printf("En cok odeme yapan: %s (%.2f)\n",
               mxPay->name, mxPay->total_payment);

    free(g1);
    free(g2);
    free(g3);
    return 0;
}