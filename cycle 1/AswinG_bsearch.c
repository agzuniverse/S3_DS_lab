#include <stdio.h>

main()
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
    while (l <= u)
    {
        mid = (l + u) / 2;
        if (s == a[mid])
        {
            printf("Element found at position %d\n", mid + 1);
            break;
        }
        else if (s > a[mid])
        {
            l = mid + 1;
        }
        else if (s < a[mid])
        {
            u = mid - 1;
        }
    }
}