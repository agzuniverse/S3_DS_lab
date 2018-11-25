#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
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

void insertAtEnd()
{
    int d;
    printf("Enter data to insert into list\n");
    scanf("%d", &d);
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = d;
        head->link = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        struct node *temp2 = (struct node *)malloc(sizeof(struct node));
        temp2->data = d;
        temp2->link = NULL;
        temp->link = temp2;
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
        temp = temp->link;
        i++;
    }
    if (temp == NULL)
    {
        printf("That many nodes are not present in the list\n");
        return;
    }
    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    temp2->data = d;
    temp2->link = temp->link;
    temp->link = temp2;
}

void deleteNode()
{
    int d, flag = 0;
    printf("Enter value to delete\n");
    scanf("%d", &d);
    struct node *temp = head, *prev;
    if (temp != NULL && temp->data == d)
    {
        head = temp->link;
        free(temp);
        printf("Successfully deleted\n");
        return;
    }
    while (temp != NULL && temp->data != d)
    {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL)
    {
        printf("Element not found\n");
        return;
    }
    prev->link = temp->link;
    free(temp);
    printf("Successfully deleted\n");
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