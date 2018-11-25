#include <stdio.h>
#include <stdlib.h>

struct node
{
    int x;
    struct node *link;
} * vertices[100], *temp, *head;

int n, visited[100], a[100], beg, end;

void addToQueue(int d)
{
    if (beg == -1)
        beg = end = 0;
    else
        end++;
    a[end] = d;
}

int removeFromQueue()
{
    int ret;
    ret = a[beg];
    printf("v%d\t", ret + 1);
    beg++;
    if (beg > end)
        beg = end = -1;
    return ret;
}

void bfs()
{
    int v = 0;
    visited[0] = 1;
    addToQueue(v);
    while (end != -1)
    {
        int e = removeFromQueue();
        temp = vertices[e];
        while (temp != NULL)
        {
            if (!visited[temp->x])
            {
                visited[temp->x] = 1;
                addToQueue(temp->x);
            }
            temp = temp->link;
        }
    }
}

void main()
{
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    int i, c;
    for (i = 0; i < n; i++)
    {
        vertices[i] = (struct node *)malloc(sizeof(struct node));
        vertices[i]->x = i;
        vertices[i]->link = NULL;
        head = vertices[i];
        printf("Enter all adjacent nodes to v%d, enter 0 to go to next node\n", i + 1);
        do
        {
            scanf("%d", &c);
            if (c != 0)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->x = c - 1;
                temp->link = NULL;
                head->link = temp;
                head = temp;
            }

        } while (c != 0);
    }
    bfs();
    printf("\n");
}