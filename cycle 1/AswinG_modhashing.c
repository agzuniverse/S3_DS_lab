#include <stdio.h>

void main()
{
    int a[11];
    int h[11] = {0};
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    //Perform hashing
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (h[(a[i] % 11) + j] != 0)
        {
            j++;
            if ((a[i] % 11) + j >= 11)
            {
                j = -11 + j;
            }
        }
        h[(a[i] % 11) + j] = a[i];
    }

    //Print hash table
    printf("The hash table is: \n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d, ", h[i]);
    }
}
