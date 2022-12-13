#include <stdio.h>
void main()
{
    int i, n, a, p, arr[1000];
    printf("Enter the no. of elements you want inside the array:");
    scanf("%d", &n);
    printf("Enter the elements in the array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you wanna insert and its position:");
    scanf("%d %d", &a, &p);
    for (i = n + 1; i >= p; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[p - 1] = a;
    printf("New Array:");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", arr[i]);
    }
}