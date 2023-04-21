#include <stdio.h>
void Kth_Element(int[], int);
int Div(int[], int, int);
void Qsort(int[], int, int);
int main()
{
    int t, n, i;
    printf("Enter The Total Number of Test cases: ");
    scanf("%d", &t);
    while (t > 0)
    {
        t--;
        printf("Enter The Size Array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter The Array: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        Kth_Element(arr, n);
    }
    return 0;
}
void Kth_Element(int arr[], int n)
{
    int k;
    printf("Enter The Kth Term: ");
    scanf("%d", &k);
    if (k < n)
    {
        Qsort(arr, 0, n - 1);
        printf("The %d Smallest Element in array is: %d \n", k, arr[k - 1]);
    }
    else if (k == n)
    {
        Qsort(arr, 0, n - 1);
        printf("The Largest Element in array is: %d \n", arr[k - 1]);
    }

    else
    {
        printf("Not Present.\n");
    }
}
int Div(int arr[], int low, int high)
{
    int temp;
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];

    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
void Qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        int PI = Div(arr, low, high);
        Qsort(arr, low, PI - 1);
        Qsort(arr, PI + 1, high);
    }
}