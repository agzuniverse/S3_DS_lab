#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head = NULL, *start = NULL;

void insert(int d)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = d;
        head->link = NULL;
        start = head;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = d;
        temp->link = head;
        head = temp;
        start->link = head;
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->link;
    }
}

void main()
{
    int n, d, i;
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    printf("Enter the values\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d);
        insert(d);
    }
    int choice;
    printf("Enter 1 to print circular linked list. WARNING: This is obviously an infinite loop\nEnter 2 to exit.\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        display();
    }
    else
    {
        exit(0);
    }
}