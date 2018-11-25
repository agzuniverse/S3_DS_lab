#include <stdio.h>

int a[100], top1 = -1, top2 = 100;

void pushOne()
{
    int d;
    if (top1 < top2)
    {
        printf("Enter value to push to stack: ");
        scanf("%d", &d);
        top1++;
        a[top1] = d;
    }
    else
        printf("Stack is full\n");
}

void popOne()
{
    if (top1 > -1)
    {
        printf("Popped value is: %d\n", a[top1]);
        top1--;
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void peekOne()
{
    if (top1 > -1)
    {
        printf("Value on top of stack is: %d\n", a[top1]);
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void pushTwo()
{
    if (top2 > top1)
    {
        int d;
        printf("Enter value to push to stack: ");
        scanf("%d", &d);
        top2--;
        a[top2] = d;
    }
    else
        printf("Stack is full\n");
}

void popTwo()
{
    if (top2 < 100)
    {
        printf("Popped value is: %d\n", a[top2]);
        top2++;
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void peekTwo()
{
    if (top2 < 100)
    {
        printf("Value on top of stack is: %d\n", a[top2]);
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
        printf("\n\nEnter 1 to push to stack 1\nEnter 2 to pop from stack 1\nEnter 3 to peek from stack 1\nEnter 4 to push to stack 2\nEnter 5 to pop from stack 2\nEnter 6 to peek from stack 2\nEnter 7 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            pushOne();
            break;
        case 2:
            popOne();
            break;
        case 3:
            peekOne();
            break;
        case 4:
            pushTwo();
            break;
        case 5:
            popTwo();
            break;
        case 6:
            peekTwo();
            break;
        }
    } while (choice < 7);
}