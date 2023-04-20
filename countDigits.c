#include <stdio.h>

int repeat(int arr[], int index)
{
  int count = 0;
  int i;
  for (i = 0; i <= 10; i++)
  {
    if (arr[i] == index)
    {
      count++;
    }
  }
  return count;
}

int main()
{
  int arr[] = {9, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int temp, temp1;
  int i, j;
  int it = 1;
  while (it == 1)
  {
    it = 0;
    for (i = 0; i < 10; i++)
    {
      temp = repeat(arr, i);
      if (arr[i] != temp)
      {
        it = 1;
        arr[i] = temp;
      }
      temp = 0;
    }
  }

  for (i = 0; i < 10; i++)
  {
    printf("%d", arr[i]);
  }
  printf("\n");
  return 0;
}
