#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char empName[50];
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
int size = 0;
void insertatbegining()
{
    struct node *Node;
    Node = (struct node *)malloc(sizeof(struct node *));
    Node->prev = NULL;
    printf("enter the element :");
    scanf("%s", &Node->empName);
    Node->next = head;
    head = Node;
    printf("sucessfully inserted %s at the begining of your ll\n", head->empName);
    size++;
}
void deleteatend()
{
    if (head != NULL)
    {
        struct node *temp = head;
        if (temp->next != NULL)
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            printf("Last element '%s' deleted \n", temp->next->empName);
            free(temp->next);
            temp->next = NULL;
        }
        else
        {
            printf("Last element '%s' deleted \n", temp->empName);
            free(temp);
            head = NULL;
        }
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
        printf("%s ", temp->empName);
        temp = temp->next;
    }
    printf("}\n");
}
int main()
{
    int a;
again:
    printf("1> Insert at begining\n");
    printf("2> Delete at the end\n");
    printf("3> Traverse\n");
    printf("0> Exit\n");
    printf("enter the your choice:");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        insertatbegining();
        break;
    case 2:
        deleteatend();
        break;
    case 3:
        traverse();
        break;
    default:
        return 0;
    }
    goto again;
}