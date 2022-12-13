#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int size = 0;
void PUSH()
{
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    printf("enter the element :");
    scanf("%d", &Node->data);
    Node->next = head;
    head = Node;
    printf("sucessfully inserted %d at the begining of your ll\n", head->data);
    size++;
}
void POP()
{
    if (head != NULL)
    {
        printf("First element '%d' deleted \n", head->data);
        struct node *temp = head;
        head = head->next;
        free(temp);
        size--;
    }
    else
    {
        printf("LL already empty \n");
    }
}
void traverse()
{
    struct node *temp = head;
    printf("%d elements your linked list are : { ", size);
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("}\n");
}
int main()
{
    int a = 0;
    while (a < 10)
    {
        printf("1> PUSH \n");
        printf("2> POP\n");
        printf("3> TRAVERSE\n");
        printf("0> Exit\n");
        printf("enter the your choice:");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            traverse();
            break;
        default:
            printf("exiting.....");
            a = 11;
            break;
        }
    }
    return 0;
}