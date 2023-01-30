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
struct node * create(int data){
    struct node * Node = (struct node *) malloc(sizeof(struct node));
    Node->data = data;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
int main()
{
    struct node *root = NULL;
    root=create(1);
    root->left=create(2);
    root->right=create(3);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    free(root);
    return 0;
}