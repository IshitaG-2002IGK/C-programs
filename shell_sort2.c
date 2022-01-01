// $ gcc shell_sort2.c -o shell_sort2
// $ ./shell_sort2
 
#include<stdio.h>
void shell_sort(int a[], int n)
{
    int i, j, k, n, temp;
    for(i = n/2; i>=0; i=i/2)
    {
        for(j=i; j<n ;j++)
        {
            for(k=j-i; k>=0; k=k-i)
            {
                if(a[k+i]> a[k])
                    break;
                else
                {
                    temp = a[k];
                    a[k] = a[k+i];
                    a[k+i]= temp;
                }
            }
        }
    }
}

void main()
{
    int a[30];
    int n,k;
    printf("Enter the number of elements");
    scanf("%d",&n);
    printf("Enter the elements");
    for( k=0; k<n ; k++)
    {
        scanf("%d", &k);

    }
    sorted_array(a, n);
    printf("Print the soorted list!");
    for( k=0; k<n ; k++)
    {
        scanf("%d", &k);

    }
}