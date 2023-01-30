#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *queue = NULL;

// for queue
void push(int val)
{
  struct node *Node = (struct node *)malloc(sizeof(struct node));
  struct node *temp = queue;
  Node->data = val;
  Node->next = NULL;
  if (queue == NULL)
  {
    queue = Node;
  }
  else
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = Node;
  }
}

void pop()
{
  struct node *temp = queue;
  if (queue == NULL)
    return;
  queue = queue->next;
  free(temp);
}

// for adjList
struct node *insertNode(struct node *head, int data)
{
  struct node *newPtr = (struct node *)malloc(sizeof(struct node));
  newPtr->next = head;
  newPtr->data = data;
  return newPtr;
}

void traverse(struct node *head)
{
  struct node *temp = head;
  if (temp == NULL)
    printf("-------------traversing----------\n");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void bfs(int start, struct node *adjlist[], int visited[], int size)
{
  push(start);
  visited[start] = 1;
  while (queue != NULL)
  {
    int current = queue->data;
    printf("%d ", current);
    pop();
    struct node *temp = adjlist[current];
    while (temp != NULL)
    {
      if (visited[temp->data] == 0)
      {
        push(temp->data);
        visited[temp->data] = 1;
      }
      temp = temp->next;
    }
  }
}

int main()
{
  int numberOfNode, numberOfEdges;
  printf("enter the no. of nodes : ");
  scanf("%d", &numberOfNode);
  printf("nodes going from : 0 - %d \n", numberOfNode - 1);
  printf("enter the no. of edges : ");
  scanf("%d", &numberOfEdges);
  struct node *adjList[numberOfNode];
  int visited[numberOfNode];
  for (int i = 0; i < numberOfNode; i++)
  {
    adjList[i] = NULL;
    visited[i] = 0;
  }

  for (int i = 0; i < numberOfEdges; i++)
  {
    int from, to;
    printf("edge between : ");
    scanf("%d %d", &from, &to);
    adjList[to] = insertNode(adjList[to], from);
    adjList[from] = insertNode(adjList[from], to);
  }

  for (int i = 0; i < numberOfNode; i++)
  {
    printf("%d-->", i);
    traverse(adjList[i]);
  }

  bfs(0, adjList, visited, numberOfNode);
}
