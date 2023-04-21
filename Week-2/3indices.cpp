#include <stdio.h> 
int main()
{
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, flag = 0;
        printf("Enter the number of array elements: ");
        scanf("%d", &n);
        int array[n];
        printf("Enter the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = array[i] + array[j];
                for (int k = j + 1; k < n; k++)
                {
                    if (sum == array[k])
                    {
                        flag = 1;
                        printf("%d %d %d\n", i, j, k);
                        break;
                    }
                }
                if (flag == 1)
                    break;
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
        {
            printf("No sequence found.\n");
        }
    }
}