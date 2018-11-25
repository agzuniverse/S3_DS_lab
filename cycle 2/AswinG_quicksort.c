#include <stdio.h>

int n;
int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int down = lb;
    int up = ub;
    while (down < up)
    {
        while (a[down] <= pivot && down < ub)
            down++;
        while (a[up] > pivot)
            up--;
        if (down < up)
        {
            int temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }
    }
    a[lb] = a[up];
    a[up] = pivot;
    int i;
    for (i = 0; i < n; i++)
        printf("%d, ", a[i]);
    printf("\n");
    return up;
}
void quicksort(int a[], int lb, int ub)
{
    if (lb >= ub)
        return;
    int j = partition(a, lb, ub);
    quicksort(a, lb, j - 1);
    quicksort(a, j + 1, ub);
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
    quicksort(a, 0, n - 1);
    printf("Array after sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}