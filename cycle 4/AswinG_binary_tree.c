#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Preorder traversal
struct node *Preorder(struct node *root)
{
    if (root == NULL)
        return root;
    printf("%d ", root->key);
    Preorder(root->left);
    Preorder(root->right);
}

// Postorder traversal
struct node *Postorder(struct node *root)
{
    if (root == NULL)
        return root;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->key);
}

// Inorder traversal
struct node *Inorder(struct node *root)
{
    if (root == NULL)
        return root;
    Inorder(root->left);
    printf("%d ", root->key);
    Inorder(root->right);
}

struct node *Insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = Insert(node->left, key);
    else
        node->right = Insert(node->right, key);
    return node;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Search tree
struct node *Search(struct node *root, int item)
{
    if (root == NULL)
        return NULL;
    else if (root->key == item)
        return root;
    else
    {
        if (item > root->key)
            return Search(root->right, item);
        else
            return Search(root->left, item);
    }
}

void main()
{
    struct node *root = NULL;
    int choice = 0, item;
    while (choice != 4)
    {
        printf("\nEnter 0 to add\nEnter 1 to delete\nEnter 2 to search\nEnter 3 to traverse\nEnter4 to quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            scanf("%d", &item);
            root = Insert(root, item);
            break;
        case 1:
            scanf("%d", &item);
            root = deleteNode(root, item);
            break;
        case 2:
            scanf("%d", &item);
            struct node *needle = Search(root, item);
            if (needle != NULL)
                printf("Found\n");
            else
                printf("Not Found\n");
            break;
        case 3:
            printf("\nEnter 1 for inorder\nEnter 2 for preorder\nEnter 3 for postorder\n");
            scanf("%d", &item);
            switch (item)
            {
            case 1:
                Inorder(root);
                break;
            case 2:
                Preorder(root);
                break;
            case 3:
                Postorder(root);
                break;
            default:
                printf("Invalid choice\n");
            }
            printf("\n");
            break;
        case 4:
            break;
        default:
            printf("Invalid option\n");
        }
    }
}
