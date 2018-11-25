#include <stdio.h>

void main()
{
    int a[100], n, i, s, c = 1;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter element to search\n");
    scanf("%d", &s);

    for (i = 0; i < n; i++)
    {
        if (a[i] == s)
        {
            printf("Element found at position %d\n", i + 1);
            c = 0;
            break;
        }
    }
    if (c)
    {
        printf("Element not found\n");
    }
}