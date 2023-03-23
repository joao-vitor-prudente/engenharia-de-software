#include <stdio.h>
#include <stdlib.h>

int get_len();

float *allocate_arr(int len);

void fill_arr(float *arr, int len);

float dot_product(float *arr1, float *arr2, int len);

void free_arr(float *arr);

int main(int argc, char const *argv[])
{
      int len = get_len();
      float *arr1 = allocate_arr(len);
      if (arr1 == NULL)
      {
            printf("Error: could not allocate memory.\n");
            return 1;
      }
      float *arr2 = allocate_arr(len);
      if (arr2 == NULL)
      {
            printf("Error: could not allocate memory.\n");
            return 1;
      }
      fill_arr(arr1, len);
      fill_arr(arr2, len);
      float dot = dot_product(arr1, arr2, len);   
      free_arr(arr1);
      free_arr(arr2);
      printf("dot product: %f\n", dot);
      return 0;
}

int get_len()
{
      int len;
      printf("Enter array length:\n");
      scanf("%d", &len);
      return len;
}

float *allocate_arr(int len)
{
      float *arr = (float*)malloc(len * sizeof(float));
      if (arr == NULL)
      {
            return NULL;
      }
      
      return arr;
}

void fill_arr(float *arr, int len)
{
      for (size_t i = 0; i < len; i++)
      {
            printf("Enter value of array at index %ld\n", i);
            scanf("%f", arr + i);
      }      
}

float dot_product(float *arr1, float *arr2, int len)
{
      float dot = 0;
      for (size_t i = 0; i < len; i++)
      {
            dot += *(arr1 + i) * *(arr2 + i);    
      }
      return dot;
}

void free_arr(float *arr)
{
      free(arr);
}
