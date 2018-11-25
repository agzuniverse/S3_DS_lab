#include <stdio.h>

int a[100], head = -1, tail = -1;

void addToQueue()
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

void removeFromQueue()
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

void main()
{
    int choice = 0;
    do
    {
        printf("\n\nEnter 1 to add\nEnter 2 to remove\nEnter 3 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addToQueue();
            break;
        case 2:
            removeFromQueue();
            break;
        }
    } while (choice < 3);
}