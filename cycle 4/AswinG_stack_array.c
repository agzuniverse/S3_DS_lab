#include <stdio.h>

int a[100], top = -1;

void push()
{
    int d;
    printf("Enter value to push to stack: ");
    scanf("%d", &d);
    top++;
    a[top] = d;
}

void pop()
{
    if (top > -1)
    {
        printf("Popped value is: %d\n", a[top]);
        top--;
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void peek()
{
    if (top > -1)
    {
        printf("Value on top of stack is: %d\n", a[top]);
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