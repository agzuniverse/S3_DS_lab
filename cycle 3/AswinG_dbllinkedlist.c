#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL, *tail = NULL;

void insertAtBeg()
{
    int d;
    printf("Enter data to insert into list\n");
    scanf("%d", &d);
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = d;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = d;
        head->next = temp;
        temp->prev = head;
        temp->next = NULL;
        head = temp;
    }
}

void insertAtEnd()
{
    int d;
    printf("Enter data to insert into list\n");
    scanf("%d", &d);
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = d;
        head->prev = NULL;
        head->next = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->prev != NULL)
        {
            temp = temp->prev;
        }
        struct node *temp2 = (struct node *)malloc(sizeof(struct node));
        temp2->data = d;
        temp2->prev = NULL;
        temp2->next = temp;
        temp->prev = temp2;
    }
}

void insertAtPos()
{
    int d, i = 0, n;
    struct node *temp = head;
    printf("Enter element to insert\n");
    scanf("%d", &d);
    printf("Enter position to insert new element\n");
    scanf("%d", &n);
    while (temp != NULL && i < n)
    {
        temp = temp->prev;
        i++;
    }
    if (temp == NULL)
    {
        printf("That many nodes are not present in the list\n");
        return;
    }
    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    temp2->data = d;
    temp2->prev = temp->prev;
    temp->prev->next = temp2;
    temp2->next = temp;
    temp->prev = temp2;
}

void deleteNode()
{
    int d, flag = 0;
    printf("Enter value to delete\n");
    scanf("%d", &d);
    struct node *temp = head, *pre;
    if (temp != NULL && temp->data == d)
    {
        head = temp->prev;
        head->next = NULL;
        free(temp);
        printf("Successfully deleted\n");
        return;
    }
    while (temp != NULL && temp->data != d)
    {
        pre = temp;
        temp = temp->prev;
    }
    if (temp == NULL)
    {
        printf("Element not found\n");
        return;
    }
    pre->prev = temp->prev;
    temp->prev->next = pre;
    free(temp);
    printf("Successfully deleted\n");
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->prev;
    }
}

void main()
{
    int choice, d;
    do
    {
        printf("\n\n1. Insert at beginning\n2. Insert at end\n3. Insert after particular node\n4. Delete node containing value\n5. Print list\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPos();
            break;
        case 4:
            deleteNode();
            break;
        case 5:
            display();
            break;
        default:
            exit(0);
        }

    } while (choice <= 6);
}