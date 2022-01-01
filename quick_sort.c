// // $ gcc quick_sort.c -o quick_sort
// // $ ./quick_sort
 

#include <stdio.h>
void quickSort(int numbers[], int array_size);
void q_sort(int numbers[], int left, int right);
void display(int a[], int n)
{
int i;
printf("\n\t\tThe Sorted list of numbers is : \n");
for (i=0;i<n;++i)
    printf("\t%d",a[i]);
}

void q_sort(int a[], int left, int right)
{
int pivot, lhold, rhold;
lhold = left;
rhold = right;
pivot = a[left];
while(left<right)
{
    while((a[right]>=pivot) && (left<right))
        right-- ;
        if(left!=right)
        {
            a[left] = a[right];
            left++ ;
        }

    while((a[left]<=pivot) && (left<right))
        left ++ ;
        if(left!=right)
        {
            a[right] = a[left];
            right-- ;

        }
}

a[left] =  pivot ;
pivot   =  left  ;
left    =  lhold ;
right   =  rhold ;
if (left < pivot)
    q_sort(a, left, pivot-1);
if (right > pivot)
    q_sort(a, pivot+1, right);

    
}
void main()
{
    int i, n, a[100],ch;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Enter the elements:");
    for (i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("QUICK SORT");
    q_sort(a,0,n-1);
    display(a,n);

    
}


// #include<stdio.h>
// void quickSort(int numbers[], int array_size);
// void q_sort(int numbers[], int left, int right);
// void display(int a[],int n)
// {
// int i;
// printf("\n\t\t\tSorted List\n");
// for(i=0;i<n;++i)
//     printf("\t%d",a[i]);
// }
// void q_sort(int a[], int left, int right)
// {
// int pivot, l_hold, r_hold;
// l_hold = left;
// r_hold = right;
// pivot = a[left];
// while (left < right)
// {
//     while ((a[right] >= pivot) && (left < right))
//     right--;
//     if (left != right)
//     {
//         a[left] = a[right];
//         left++;
//     }
//     while ((a[left] <= pivot) && (left < right))
//     left++;
//     if (left != right)
//     {
//         a[right] = a[left];
//         right--;
//     }
// }
//     a[left] = pivot;
//     pivot = left;
//     left = l_hold;
//     right = r_hold;
//     if (left < pivot)
//         q_sort(a, left, pivot-1);
//     if (right > pivot)
//         q_sort(a, pivot+1, right);
// }
// void main()
// {
// int a[100],n,i,ch;
// printf("\nEnter The Number Of Elements\t: ");
// scanf("%d",&n);
// printf("\nEnter Elements\n");
// for(i=0;i< n;++i)
//     scanf("%d",&a[i]);
// printf("<-----Quick SORT----->\n");
// q_sort(a,0,n-1);
// display(a,n);
// }
