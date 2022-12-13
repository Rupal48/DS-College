#include <stdio.h>
void main()
{
    int i, n, p, arr[1000];
    printf("Enter the no. of elements you want inside the array:");
    scanf("%d", &n);
    printf("Enter the elements in the array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position whose element you want to delete:");
    scanf("%d", &p);
    for (i = p - 1; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("New Array:");
    for (i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
}