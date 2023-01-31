#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int i, j, small;
    for (i = 0; i < n - 1; i++)
    {
        small = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[small])
                small = j;
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}
swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void insertionSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && temp <= a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}
void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LeftArray[n1], RightArray[n2];
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates
                           // the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int p = partition(a, start, end);
        quickSort(a, start, p - 1);
        quickSort(a, p + 1, end);
    }
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
void printArr(int a[], int n)
{
    int i;
    printf("Sorted Array : ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int c;
again:
    printf("\nChoose operation:\nPress 0 to create array\nPress 1 to perform Selection Sort\nPress 2 to perform Bubble Sort\nPress 3 to perform Insertion Sort\nPress 4 to perform Merge Sort\nPress 5 to perform Quick Sort\nPress 6 to perform Heap Sort\nPress 7 to exit\n");
    scanf("%d", &c);
    switch (c)
    {
    case 0:;
        int a[100], n;
        printf("Enter the no. of elements in the array : ");
        scanf("%d", &n);
        printf("Enter the elements in your array : ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
    case 1:
        selectionSort(a, n);
        printArr(a, n);
        break;
    case 2:
        bubbleSort(a, n);
        printArr(a, n);
        break;
    case 3:
        insertionSort(a, n);
        printArr(a, n);
        break;
    case 4:
        mergeSort(a, 0, n - 1);
        printArr(a, n);
        break;
    case 5:
        quickSort(a, 0, n - 1);
        printArr(a, n);
        break;
    case 6:
        heapSort(a, n);
        printArr(a, n);
        break;
    case 7:
        printf("Exiting.......");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
    goto again;
}