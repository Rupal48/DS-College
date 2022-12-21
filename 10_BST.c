#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;
void insert()
{
    struct node *ptr, *temp;
    int d = 0;
    printf("Enter the value you wanna insert in your binary tree: ");
    scanf("%d", &d);
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Memory Full.\n");
        return;
    }
    else
    {
        if (root->data == NULL)
        {
            ptr->data = d;
            ptr->left = NULL;
            ptr->right = NULL;
            root = ptr;
            return;
        }
        ptr->data = d;
        temp->data = root->data;
        while (ptr != NULL)
        {
            if (d < temp->data)
            {
                temp = root->left;
            }
            else if (d > temp->data)
            {
                temp = root->right;
            }
        }
    }
}
int main()
{
    return 0;
}