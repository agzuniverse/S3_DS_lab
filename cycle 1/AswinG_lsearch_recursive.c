#include <stdio.h>
int lsearch(int a[], int i, int n, int s)
{
    if (a[i] == s)
    {
        printf("Element found at position %d\n", i + 1);
        return 1;
    }
    else if (i < n)
    {
        lsearch(a, i + 1, n, s);
    }
    else
        return 0;
}

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

    if (!lsearch(a, 0, n, s))
    {
        printf("Element not found\n");
    }
}