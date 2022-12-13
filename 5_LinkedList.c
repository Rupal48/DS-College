#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;
void createlist()
{
    struct node *temp, *ptr;
    head = (struct node *)malloc(sizeof(struct node *));
    ptr = head;
    if (ptr == NULL)
    {
        printf(" Memory Overflow.\n");
        return;
    }
    else
    {
        int data;
        printf("Enter data in first node:");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        int n;
        printf("Enter total no. of nodes in the linked list:");
        scanf("%d", &n);
        if (n > 1)
        {
            printf("Enter the data in rest of the nodes: ");
            for (int i = 2; i <= n; i++)
            {
                int item;
                scanf("%d", &item);
                temp = (struct node *)malloc(sizeof(struct node *));
                temp->data = item;
                temp->next = NULL;
                ptr->next = temp;
                ptr = ptr->next;
            }
        }
    }
}
void traverse()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = head;
    printf("Current Linked List: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void search()
{
    struct node *ptr = head;
    int key, i = 1, j = 0;
    printf("Enter the element you wanna find:");
    scanf("%d", &key);
    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            j = 1;
            printf("Found element %d at position %d\n", key, i);
            break;
        }
        i++;
        ptr = ptr->next;
    }
    if (j == 0)
    {
        printf("Element not found.\n");
    }
}
void Insert_At_Beginning()
{
    int d;
    printf("Enter the element you wanna insert:");
    scanf("%d", &d);
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    if (temp == NULL)
    {
        printf("Memory Full.\n");
        return;
    }
    if (head == NULL)
    {
        temp->data = d;
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->data = d;
    temp->next = head;
    head = temp;
}
void Insert_At_End()
{
    int d;
    printf("Enter the element you wanna insert:");
    scanf("%d", &d);
    struct node *temp, *ptr = head;
    temp = (struct node *)malloc(sizeof(struct node *));
    if (temp == NULL)
    {
        printf("Memory Full.\n");
        return;
    }
    if (head == NULL)
    {
        temp->data = d;
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->data = d;
    temp->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void Insert_At_Specific_Position()
{
    int d, pos, count = 0;
    printf("Enter the element you wanna insert and its position:");
    scanf("%d %d", &d, &pos);
    struct node *temp, *ptr = head, *ptr2 = head;
    temp = (struct node *)malloc(sizeof(struct node *));
    if (temp == NULL)
    {
        printf("Memory Full.\n");
        return;
    }
    while (ptr2 != NULL)
    {
        count++;
        ptr2 = ptr2->next;
    }
    if (pos > count + 1)
    {
        printf("Position does not exist.\n");
        return;
    }
    if (head == NULL)
    {
        temp->data = d;
        temp->next = NULL;
        head = temp;
        return;
    }
    temp->data = d;
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void Delete_At_Beginning()
{
    if (head == NULL)
    {
        printf("No linked list is there.\n");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
}
void Delete_At_End()
{
    if (head == NULL)
    {
        printf("No linked list is there.\n");
        return;
    }
    struct node *ptr = head;
    if (head->next == NULL)
    {
        free(ptr);
        head = NULL;
        return;
    }
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    ptr->next = NULL;
    free(temp);
}
void Delete_at_Specific_position()
{
    if (head == NULL)
    {
        printf("No linked list is there.\n");
        return;
    }
    int pos, count = 0;
    printf("Enter the position you wanna delete:");
    scanf("%d", &pos);
    struct node *ptr = head, *temp, *ptr2 = head;
    while (ptr2 != NULL)
    {
        count++;
        ptr2 = ptr2->next;
    }
    if (pos > count)
    {
        printf("Position does not exist.\n");
        return;
    }
    if (pos == 1)
    {
        head = head->next;
        free(ptr);
        return;
    }
    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}
void Delete_Specific_Element()
{
    if (head == NULL)
    {
        printf("No linked list is there.\n");
        return;
    }
    struct node *ptr = head;
    int key;
    printf("Enter the element you wanna delete:");
    scanf("%d", &key);
    if (head->next == NULL && head->data == key)
    {
        free(ptr);
        head = NULL;
        return;
    }
    if (ptr->data == key)
    {
        head = head->next;
        free(ptr);
        return;
    }
    while (ptr->next->data != key)
    {
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            printf("%d element does not exist.\n", key);
            return;
        }
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}
void reversal()
{
    if (head == NULL)
    {
        printf("No linked list is there.\n");
        return;
    }
    struct node *ptr = head;
    struct node *prev = NULL, *next = NULL;
    while (ptr != NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
}
void main()
{
    int c;
again:
    printf("Choose operation:\n");
    if (head == NULL)
    {
        printf("Press 0 to create a linked list of n no. of nodes (Operation only available as first operatio)\n");
    }
    printf("Press 1 to perform Insertion at beginning\nPress 2 to perform Insertion at end\nPress 3 to perform Insertion at any Specific position\nPress 4 to perform Serching of an element\nPress 5 to perform Deletion at beginning\nPress 6 to perform Deletion at end\nPress 7 to perform Deletion at Specific Position\nPress 8 to perform deletion of a specific element\nPress 9 to perform traversal\nPress 10 to perform reversal of linked list\nPress 11 to exit\n");
    scanf("%d", &c);
    switch (c)
    {
    case 0:
        createlist();
        break;
    case 1:
        Insert_At_Beginning();
        break;
    case 2:
        Insert_At_End();
        break;
    case 3:
        Insert_At_Specific_Position();
        break;
    case 4:
        search();
        break;
    case 5:
        Delete_At_Beginning();
        break;
    case 6:
        Delete_At_End();
        break;
    case 7:
        Delete_at_Specific_position();
        break;
    case 8:
        Delete_Specific_Element();
        break;
    case 9:
        traverse();
        break;
    case 10:
        reversal();
        break;
    case 11:
        return;
    default:
        printf("Invalid choice.\n");
    }
    goto again;
}