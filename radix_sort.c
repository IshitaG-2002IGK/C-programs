//  $ gcc radix_sort.c -o radix_sort
//  $ ./radix_sort
 

#include<stdio.h>
 
int getMax(int a[], int n)
{
    int max = a[0];
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
 
void countSort(int a[], int n, int exp)
{
    int output[n]; // output aay
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output aay
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        a[i] = output[i];
}
 
// The main function to that sorts a[] of size n using Radix Sort
void radixsort(int a[], int n)
{
    int m = getMax(a, n);
 
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
 
void print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
 
int main() 
{
    int a[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(a) / sizeof(a[0]);
    radixsort(a, n);
    print(a, n);
    return 0;
}