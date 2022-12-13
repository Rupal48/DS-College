#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;
void Insert()
{
    int d;
    printf("Enter the element you wanna insert:");
    scanf("%d", &d);
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Memory Full.\n");
        return;
    }
    if (front == NULL)
    {
        ptr->data = d;
        ptr->next = NULL;
        rear = ptr;
        front = ptr;
        return;
    }
    ptr->data = d;
    ptr->next = NULL;
    rear->next = ptr;
    rear = rear->next;
}
void Delete()
{
    if (rear == NULL)
    {
        printf("No linked list is there.\n");
        return;
    }
    struct node *ptr = front;
    front = front->next;
    free(ptr);
}
void traverse()
{
    if (rear == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = front;
    printf("Current Queue: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    int c;
again:
    printf("Choose operation:\nPress 1 to perform Insertion\nPress 2 to perform Deletion\nPress 3 to perform traversal\nPress 0 to exit\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        Insert();
        break;
    case 2:
        Delete();
        break;
    case 3:
        traverse();
        break;
    case 0:
        printf("Exiting......");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
    goto again;
}