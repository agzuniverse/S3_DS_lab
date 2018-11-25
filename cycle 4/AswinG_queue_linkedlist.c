#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head = NULL, *tail = NULL;

void addToQueue()
{
    if (tail == NULL)
    {
        tail = (struct node *)malloc(sizeof(struct node));
        printf("Enter value to push to stack: ");
        scanf("%d", &(tail->data));
        tail->link = NULL;
        head = tail;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter value to add to queue: ");
        scanf("%d", &(temp->data));
        tail->link = temp;
        tail = temp;
    }
}

void removeFromQueue()
{
    if (head != NULL)
    {
        printf("Removed value is: %d\n", head->data);
        head = head->link;
    }
    else
    {
        printf("Queue is empty\n");
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