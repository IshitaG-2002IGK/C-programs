#include <stdio.h>
int main()
{
    int a[100], n, i, j, pos, temp;
    printf("Enter number of elements");
    scanf("%d", &n);
    printf("Enter %d Numbers", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n - 1; i++)
    {
        pos=i;
        for(j = i + 1; j < n; j++)
        {
            if(a[pos] > a[j])
            pos=j;
        }
        if(pos != i)
        {
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
        }
    }
    printf("Sorted Array:");
    for(i = 0; i < n; i++)
        printf("%dn", a[i]);
    return 0;
}