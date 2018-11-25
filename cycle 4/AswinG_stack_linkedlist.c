#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *top = NULL;

void push()
{
    if (top == NULL)
    {
        top = (struct node *)malloc(sizeof(struct node));
        printf("Enter value to push to stack: ");
        scanf("%d", &(top->data));
        top->link = NULL;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter value to push to stack: ");
        scanf("%d", &(temp->data));
        temp->link = top;
        top = temp;
    }
}

void pop()
{
    if (top != NULL)
    {
        printf("Popped value is: %d\n", top->data);
        top = top->link;
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void peek()
{
    if (top != NULL)
    {
        printf("Value on top of stack is: %d\n", top->data);
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void main()
{
    int choice = 0;
    do
    {
        printf("\n\nEnter 1 to push\nEnter 2 to pop\nEnter 3 to peek\nEnter 4 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        }
    } while (choice < 4);
}