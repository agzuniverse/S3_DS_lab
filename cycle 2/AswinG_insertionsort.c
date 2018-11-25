#include <stdio.h>

void insertionsort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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
    insertionsort(a, n);
    printf("Array after sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}