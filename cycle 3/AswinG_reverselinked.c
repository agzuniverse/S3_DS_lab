#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head = NULL;

void insert(int d)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = d;
        head->link = NULL;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = d;
        temp->link = head;
        head = temp;
    }
}

void reverse()
{
    struct node *cur = head, *next = NULL, *prev = NULL;
    while (cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
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
    printf("Linked list before reversing\n");
    display();
    reverse();
    printf("Linked list after reversing\n");
    display();
}