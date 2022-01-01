// $ gcc linear_search.c -o linear_search
// $ ./linear_search
 


#include<stdio.h>
int main()
{
    int i, a[100], search, n;
    printf("Enter the no. of elements");
    scanf("%d", &n);
    printf("Enter elements of array");
    for(i=0; i<n; i++)
    { 
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched");
    scanf("%d", &search);
    for(i=0;i<n;++i)
    {
        if(a[i]== search)
            break;
    }
    if(i<n)
    {
        printf("Element found at location %d",i);
    }
    else
    {
        printf("Not found!!");
    }

    return 0;
}



// ANOTHER PROGRAM
// #include<stdio.h>
  
// int main()
// {
//     int a[20],i,x,n;
//     printf("How many elements?");
//     scanf("%d",&n);
     
//     printf("Enter array elements:n");
//     for(i=0;i<n;++i)
//         scanf("%d",&a[i]);
     
//     printf("nEnter element to search:");
//     scanf("%d",&x);
     
//     for(i=0;i<n;++i)
//         if(a[i]==x)
//             break;
     
//     if(i<n)
//         printf("Element found at index %d",i);
//     else
//         printf("Element not found");
  
//     return 0;
// }
