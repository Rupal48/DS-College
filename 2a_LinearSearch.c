#include <stdio.h>
int main()
{
    int n, i, a;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you wanna find:");
    scanf("%d", &a);
    for (i = 0; i < n; i++)
    {
        if (a == arr[i])
        {
            printf("Found %d at position %d and index %d.", a, i + 1, i);
            goto end;
        }
    }
    printf("Element not found in the array.");
end:
    return 0;
}