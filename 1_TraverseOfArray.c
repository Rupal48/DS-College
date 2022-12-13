#include <stdio.h>
void main()
{
    int n, i, a;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Resultant Array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}