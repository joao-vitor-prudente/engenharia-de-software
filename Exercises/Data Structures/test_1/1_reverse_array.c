#include <stdio.h>
#include <stdlib.h>

int get_len();

int *allocate_arr(int len);

void fill_arr(int *arr, int len);

void reverse_arr(int *arr, int *rev_arr, int len);

void print_arr(int *arr, int len);

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
      int *rev_arr = allocate_arr(len);
      if (arr == NULL)
      {
            printf("Error: could not allocate memory.");
            return 1;
      }
      reverse_arr(arr, rev_arr, len);
      print_arr(rev_arr, len);
      free_arr(arr);
      free_arr(rev_arr);
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

void reverse_arr(int *arr, int *rev_arr, int len)
{
      for (size_t i = 0; i < len; i++)
      {
            *(rev_arr + i) = *(arr + len - i - 1);
      }
      
}

void print_arr(int *arr, int len)
{
      printf("[");
      for (size_t i = 0; i < len; i++)
      {
            printf("\n\t%d,", *(arr + i));
      }
      printf("\n]\n");
}

void free_arr(int *arr)
{
      free(arr);
}

