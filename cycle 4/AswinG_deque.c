#include <stdio.h>

int a[100], head = -1, tail = -1;

void addToQueueEnd()
{
    int d;
    printf("Enter value to add to queue: ");
    scanf("%d", &d);
    if (head == -1)
        head = tail = 0;
    else
        tail++;
    a[tail] = d;
}

void addToQueueBeg()
{
    int d;
    printf("Enter value to add to queue: ");
    scanf("%d", &d);
    if (head == -1)
        head = tail = 0;
    else if (head == 0)
    {
        printf("No space available at beginning of queue\n");
        return;
    }
    else
        head--;
    a[head] = d;
}

void removeFromQueueBeg()
{
    if (tail == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Removed value is: %d\n", a[head]);
        head++;
        if (head > tail)
            head = tail = -1;
    }
}

void removeFromQueueEnd()
{
    if (tail == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Removed value is: %d\n", a[tail]);
        tail--;
        if (head > tail)
            head = tail = -1;
    }
}

void main()
{
    int choice = 0;
    do
    {
        printf("\n\nEnter 1 to add at beginning\nEnter 2 to remove from beginning\nEnter 3 to add at end\nEnter 4 to remove from end\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addToQueueBeg();
            break;
        case 2:
            removeFromQueueBeg();
            break;
        case 3:
            addToQueueEnd();
            break;
        case 4:
            removeFromQueueEnd();
            break;
        }
    } while (choice < 5);
}