// $ gcc bubble_sort.c -o bubble_sort
// $ ./bubble_sort
 

#include <stdio.h>

int main()
{
  int a[100], n, i, j, temp;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (a[j] > a[j+1]) /* For decreasing order use '<' instead of '>' */
      {
        temp   = a[j];
        a[j]   = a[j+1];
        a[j+1] = temp;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (i = 0; i < n; i++)
     printf("%d\n", a[i]);

  return 0;
}