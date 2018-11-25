#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int temp;
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[root])
        root = left;
    if (right < n && a[right] > a[root])
        root = right;
    if (root != i)
    {
        temp = a[i];
        a[i] = a[root];
        a[root] = temp;
        heapify(a, n, root);
    }
}
void heapsort(int a[], int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
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
    heapsort(a, n);
    printf("Array after sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}