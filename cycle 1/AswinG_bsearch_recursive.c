#include <stdio.h>

int bsearch(int a[], int l, int u, int s)
{
    int mid = (l + u) / 2;
    if (a[mid] == s)
    {
        printf("Element found at position %d\n", mid + 1);
        return 1;
    }
    else if (s > a[mid])
    {
        l = mid + 1;
    }
    else if (s < a[mid])
    {
        u = mid - 1;
    }
    if (l <= u)
        bsearch(a, l, u, s);
    else
        return 0;
}

void main()
{
    int i, s, n, l, u, mid, a[100];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements (In ascending order):\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to be searched: ");
    scanf("%d", &s);
    l = 0;
    u = n;
    if (!bsearch(a, l, u, s))
        printf("Element not found\n");
}