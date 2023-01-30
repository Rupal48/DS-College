#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
// struct node *insert()
// {
//     int value;
//     printf("Enter data : ");
//     scanf("%d", &value);
//     if (value == -1)
//     {
//         return NULL;
//     }
//     struct node *root = (struct node *)malloc(sizeof(struct node *));
//     root->data = value;
//     struct node *leftNode = insert();
//     struct node *rightNode = insert();
//     root->left = leftNode;
//     root->right = rightNode;
//     return root;
// }
int inorder(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
struct node *create(int value)
{
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->data = value;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}
struct node *insertion(struct node *root, int value)
{
    if (root == NULL)
    {
        return create(value);
    }
    if (value <= root->data)
    {
        root->left = insertion(root->left, value);
    }
    if (value > root->data)
    {
        root->right = insertion(root->right, value);
    }
    return (root);
}
int getRightMin(struct node *root)
{
    struct node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp->data;
}
struct node *deletion(struct node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deletion(root->left, value);
    }
    if (value > root->data)
    {
        root->right = deletion(root->right, value);
    }
    if (value == root->data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
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
        else
        {
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = deletion(root->right, rightMin);
        }
    }

    return (root);
}
int main()
{
    struct node *root = NULL;
    root = insertion(root, 2);
    root = insertion(root, 1);
    root = insertion(root, 3);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    root = deletion(root, 2);
    inorder(root);
    printf("\n");
    free(root);
    return 0;
}