// $ gcc shell_sort.c -o shell_sort
// $ ./shell_sort
 

#include <stdio.h>
void shellsort(int arr[], int n)
{
    int i, j, k, temp;
    for (i = n / 2; i > 0; i = i / 2)
    
        for (j = i; j < n; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    temp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = temp;
                }
            }
        }
    }
}
int main()
{
    int arr[30];
    int k,  n;
    printf("Enter total no. of elements : ");
    scanf("%d", &n);
    printf("\nEnter %d nbers: ", n);
 
    for (k =  0 ; k < n; k++)
    {
        scanf("%d", &arr[k]);
    }
    shellsort(arr, n);
    printf("\n Sorted array is: ");
    for (k = 0; k < n; k++)
        printf("%d ", arr[k]);
    return 0;
}