#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int expo;
    struct poly *link;
} *p1head = NULL, *p1ptr = NULL, *p2head = NULL, *p2ptr = NULL, *p3head = NULL, *p3ptr;

void main()
{
    int n, i;
    printf("Enter number of terms in first polynomial\n");
    scanf("%d", &n);
    printf("Enter coefficient and exponent of %d terms\n", n);
    for (i = 0; i < n; i++)
    {
        if (p1head == NULL)
        {
            p1head = (struct poly *)malloc(sizeof(struct poly));
            scanf("%d", &(p1head->coeff));
            scanf("%d", &(p1head->expo));
            p1head->link = NULL;
            p1ptr = p1head;
        }
        else
        {
            struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
            scanf("%d", &(temp->coeff));
            scanf("%d", &(temp->expo));
            temp->link = NULL;
            p1head->link = temp;
            p1head = temp;
        }
    }

    printf("Enter number of terms in second polynomial\n");
    scanf("%d", &n);
    printf("Enter coefficient and exponent of %d terms\n", n);
    for (i = 0; i < n; i++)
    {
        if (p2head == NULL)
        {
            p2head = (struct poly *)malloc(sizeof(struct poly));
            scanf("%d", &(p2head->coeff));
            scanf("%d", &(p2head->expo));
            p2head->link = NULL;
            p2ptr = p2head;
        }
        else
        {
            struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
            scanf("%d", &(temp->coeff));
            scanf("%d", &(temp->expo));
            temp->link = NULL;
            p2head->link = temp;
            p2head = temp;
        }
    }

    printf("The entered polynomials are:\n");
    struct poly *temp = p1ptr;
    while (temp->link != NULL)
    {
        printf("%dx^%d + ", temp->coeff, temp->expo);
        temp = temp->link;
    }
    printf("%dx^%d\n", temp->coeff, temp->expo);
    temp = p2ptr;
    while (temp->link != NULL)
    {
        printf("%dx^%d + ", temp->coeff, temp->expo);
        temp = temp->link;
    }
    printf("%dx^%d\n", temp->coeff, temp->expo);

    while (p1ptr != NULL && p2ptr != NULL)
    {
        if (p1ptr->expo > p2ptr->expo)
        {
            if (p3head == NULL)
            {
                p3head = (struct poly *)malloc(sizeof(struct poly));
                p3head->expo = p1ptr->expo;
                p3head->coeff = p1ptr->coeff;
                p3head->link = NULL;
                p3ptr = p3head;
            }
            else
            {
                struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
                temp->expo = p1ptr->expo;
                temp->coeff = p1ptr->coeff;
                temp->link = NULL;
                p3head->link = temp;
                p3head = temp;
            }
            p1ptr = p1ptr->link;
        }
        else if (p1ptr->expo < p2ptr->expo)
        {
            if (p3head == NULL)
            {
                p3head = (struct poly *)malloc(sizeof(struct poly));
                p3head->expo = p2ptr->expo;
                p3head->coeff = p2ptr->coeff;
                p3head->link = NULL;
                p3ptr = p3head;
            }
            else
            {
                struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
                temp->expo = p2ptr->expo;
                temp->coeff = p2ptr->coeff;
                temp->link = NULL;
                p3head->link = temp;
                p3head = temp;
            }
            p2ptr = p2ptr->link;
        }
        else if (p1ptr->expo == p2ptr->expo)
        {
            if (p3head == NULL)
            {
                p3head = (struct poly *)malloc(sizeof(struct poly));
                p3head->expo = p1ptr->expo;
                p3head->coeff = p1ptr->coeff + p2ptr->coeff;
                p3head->link = NULL;
                p3ptr = p3head;
            }
            else
            {
                struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
                temp->expo = p1ptr->expo;
                temp->coeff = p1ptr->coeff + p2ptr->coeff;
                temp->link = NULL;
                p3head->link = temp;
                p3head = temp;
            }
            p1ptr = p1ptr->link;
            p2ptr = p2ptr->link;
        }
    }
    while (p1ptr != NULL)
    {
        struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
        temp->expo = p1ptr->expo;
        temp->coeff = p1ptr->coeff;
        temp->link = NULL;
        p3head->link = temp;
        p3head = temp;
        p1ptr = p1ptr->link;
    }
    while (p2ptr != NULL)
    {
        struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
        temp->expo = p2ptr->expo;
        temp->coeff = p2ptr->coeff;
        temp->link = NULL;
        p3head->link = temp;
        p3head = temp;
        p2ptr = p2ptr->link;
    }

    printf("The resultant polynomial is:\n");
    temp = p3ptr;
    while (temp->link != NULL)
    {
        printf("%dx^%d + ", temp->coeff, temp->expo);
        temp = temp->link;
    }
    printf("%dx^%d\n", temp->coeff, temp->expo);
}