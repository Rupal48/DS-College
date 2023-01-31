#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *next;
    int val;
};
struct Node *head = NULL; // pop
struct Node *tail = NULL; // push
void push(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->next = NULL;
    newNode->val = val;
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
void pop()
{
    if (head == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    struct Node *toDelete = head;
    head = head->next;
    free(toDelete);
}
void BFS(int start, int **adj, int size, int *visited)
{
    if (start >= size)
        return;
    push(start);
    visited[start] = 1;
    while (head != NULL)
    {
        int front = head->val;
        pop();
        printf("%d ", front);
        for (int i = 0; i < size; i++)
        {
            if (adj[front][i] == 1 && visited[i] == 0)
            {
                push(i);
                visited[i] = 1;
            }
        }
    }
}
void DFS(int current, int **adj, int size, int *visited)
{
    if (current >= size)
        return;
    if (visited[current] == 1)
        return;
    printf("%d ", current);
    visited[current] = 1;
    for (int i = 0; i < size; i++)
    {
        if (adj[current][i] == 1)
        {
            DFS(i, adj, size, visited);
        }
    }
}
int main()
{
    printf("Enter Number of Nodes:");
    int size;
    scanf("%d", &size);
    int **adj = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        adj[i] = (int *)malloc(size * sizeof(int));

    printf("Nodes Created from 0 to size-1\n");
    printf("Enter Number of Edges:");
    int edges;
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++)
    {
        printf("Edge From:");
        int from;
        scanf("%d", &from);
        printf("Edge To:");
        int to;
        scanf("%d", &to);
        adj[from][to] = 1;
        adj[to][from] = 1;
    }
    int visited[size];
    for (int i = 0; i < size; i++)
        visited[i] = 0;
    printf("Enter Starting Node:");
    int start = 0;
    scanf("%d", &start);
    printf("\nDFS:");
    DFS(start, adj, size, visited);
    for (int i = 0; i < size; i++)
        visited[i] = 0;
    printf("\nBFS:");
    BFS(start, adj, size, visited);
}