#include <stdio.h>
#include <stdlib.h>

int get_len();

int *allocate_arr(int len);

void fill_arr(int *arr, int len);

int get_min(int *arr, int len);

void free_arr(int *arr);

int main(int argc, char const *argv[])
{
      int len = get_len();
      int *arr = allocate_arr(len);
      if (arr == NULL)
      {
            printf("Error: could not allocate memory.");
            return 1;
      }
      fill_arr(arr, len);
      int min = get_min(arr, len);
      printf("min: %d\n", min);
      free_arr(arr);
      return 0;
}

int get_len()
{
      int len;
      printf("Enter array length:\n");
      scanf("%d", &len);
      return len;
}

int *allocate_arr(int len)
{
      int *arr = (int*)malloc(len * sizeof(int));
      if (arr == NULL)
      {
            return NULL;
      }
      
      return arr;
}

void fill_arr(int *arr, int len)
{
      for (size_t i = 0; i < len; i++)
      {
            printf("Enter value of array at index %ld\n", i);
            scanf("%d", arr + i);
      }      
}

int get_min(int *arr, int len)
{
      if (len == 0)
      {
            printf("Empty array.\n");
            return 0;
      }
      int min = *arr;
      for (size_t i = 0; i < len; i++)
      {
            min = (min > *(arr + i)) ? *(arr + i) : min;
      }
      return min;
}

void free_arr(int *arr)
{
      free(arr);
}

