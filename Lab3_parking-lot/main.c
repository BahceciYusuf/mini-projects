#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stack
{
    int area[4];
    int head;
} stack;

typedef struct queue
{
    int area[MAX];
    int first;
} queue;
void print_status(stack *area1, stack *area2, stack *area3, stack *area4)
{

    printf("\nArea 1:\n");
    for (int i = 0; i <= area1->head; i++)
    {
        printf("%d", area1->area[i]);
        printf("\n");
    }

    printf("\nArea 2:\n");
    for (int i = 0; i <= area2->head; i++)
    {
        printf("%d", area2->area[i]);
        printf("\n");
    }

    printf("\nArea 3:\n");
    for (int i = 0; i <= area3->head; i++)
    {
        printf("%d", area3->area[i]);
        printf("\n");
    }

    printf("\nArea 4:\n");
    for (int i = 0; i <= area4->head; i++)
    {
        printf("%d", area4->area[i]);
        printf("\n");
    }
}

void create_Temporary(queue *qu)
{
    qu->first = -1;
}

void create_Area(stack *area)
{
    area->head = -1;
}

void add_temoprary(queue *temoprary, int car)
{
    temoprary->first++;
    temoprary->area[temoprary->first] = car;
}
int remove_temporary(queue *temoprary)
{
    temoprary->first--;
    return (temoprary->area[temoprary->first + 1]);
}

void add_car(stack *area1, stack *area2, stack *area3, stack *area4, queue *temporary, int car)
{
    if (area1->head < 3)
    {
        area1->head++;
        area1->area[area1->head] = car;
    }
    else if (area2->head < 3)
    {
        area2->head++;
        area2->area[area2->head] = car;
    }
    else if (area3->head < 3)
    {
        area3->head++;
        area3->area[area3->head] = car;
    }
    else if (area4->head < 3)
    {
        area4->head++;
        area4->area[area4->head] = car;
    }
    else
    {
        add_temoprary(temporary, car);
    }
}

int leave(int car_area, int car_index, stack *area1, stack *area2, stack *area3, stack *area4, queue *temporary)
{

    stack *target;
    switch (car_area)
    {
    case 1:
        target = area1;
        break;
    case 2:
        target = area2;
        break;
    case 4:
        target = area4;
        break;
    case 3:
        target = area3;
        break;
    default:
        return 1;
    }

    for (int i = target->head; i > car_index; i--)
    {
        int car = target->area[i];

        if (car_area != 1 && area1->head < 3)
            area1->area[++area1->head] = car;
        else if (car_area != 2 && area2->head < 3)
            area2->area[++area2->head] = car;
        else if (car_area != 3 && area3->head < 3)
            area3->area[++area3->head] = car;
        else if (car_area != 4 && area4->head < 3)
            area4->area[++area4->head] = car;
        else
            add_temoprary(temporary, car); // hiçbirinde yer yoksa temporary'ye
    }

    int leaving_car = target->area[car_index];
    target->head = car_index - 1;
    printf("%d numaralı araç otoparktan ayrıldı.\n", leaving_car);

    while (temporary->first >= 0)
    {
        int car = remove_temporary(temporary);
        add_car(area1, area2, area3, area4, temporary, car);
    }

    return 0;
}

int main()
{

    stack area1, area2, area3, area4;
    create_Area(&area1);
    create_Area(&area2);
    create_Area(&area3);
    create_Area(&area4);

    queue temporary;
    create_Temporary(&temporary);

    add_car(&area1, &area2, &area3, &area4, &temporary, 101);
    add_car(&area1, &area2, &area3, &area4, &temporary, 102);
    add_car(&area1, &area2, &area3, &area4, &temporary, 103);
    add_car(&area1, &area2, &area3, &area4, &temporary, 104);
    add_car(&area1, &area2, &area3, &area4, &temporary, 201);
    add_car(&area1, &area2, &area3, &area4, &temporary, 202);
    add_car(&area1, &area2, &area3, &area4, &temporary, 203);
    add_car(&area1, &area2, &area3, &area4, &temporary, 204);
    add_car(&area1, &area2, &area3, &area4, &temporary, 301);
    add_car(&area1, &area2, &area3, &area4, &temporary, 302);
    add_car(&area1, &area2, &area3, &area4, &temporary, 303);

    print_status(&area1, &area2, &area3, &area4);

    return 0;
}
