#include <stdio.h>

int n;

void merge(int a[], int l, int m, int u)
{
    int i = l, j = m + 1, k = 0, b[50];

    while (i <= m && j <= u)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= u)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (i = l, j = 0; i <= u; i++, j++)
    {
        a[i] = b[j];
    }

    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n\n");
}

void mergesort(int a[], int l, int u)
{
    int mid;
    if (l < u)
    {
        mid = (l + u) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, u);
        merge(a, l, mid, u);
    }
}

void main()
{
    int a[100], i;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("Array after sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}