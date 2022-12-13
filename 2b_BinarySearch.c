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
    int LB = 0, UB = n - 1;
    while (UB >= LB)
    {
        int MID = (LB + UB) / 2;
        if (a == arr[MID])
        {
            printf("Found %d at position %d and index %d.", a, MID + 1, MID);
            goto end;
        }
        if (a < arr[MID])
        {
            UB = MID - 1;
        }
        else
        {
            LB = MID + 1;
        }
    }
    printf("Element not found in the array.");
end:
    return 0;
}