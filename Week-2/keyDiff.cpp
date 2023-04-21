#include <stdio.h> 
int main()
{
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, c = 0, key;
        printf("Enter the number of array elements: ");
        scanf("%d", &n);
        int array[n];
        printf("Enter the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }
        printf("Enter the key: ");
        scanf("%d", &key);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (array[j] - array[i] == key || array[j] - array[i] == (-1) * key)
                {
                    c++;
                }
            }
        }
        printf("%d\n", c);
    }
}