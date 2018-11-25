#include <stdio.h>

void selectionsort(int a[], int n)
{
    int small, i, j, temp;
    for (i = 0; i < n; i++)
    {
        small = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[small] > a[j])
            {
                small = j;
            }
        }
        temp = a[small];
        a[small] = a[i];
        a[i] = temp;
    }
}

void main()
{
    int a[100], i, n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionsort(a, n);
    printf("Array after sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}