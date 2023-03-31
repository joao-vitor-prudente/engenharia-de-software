#include <stdio.h>
#include <stdlib.h>

int *get_arr(int *len, int step)
{
    *len = 0;
    int buf = step;
    int *arr = (int*)malloc(buf * sizeof(int));
    if (arr == NULL) {printf("Error: memory allocation failed.\n"); exit(1);}
    int number;
    while (1)
    {
        scanf("%d", &number);

        if (number < 0) {break;}

        if (*len == buf)
        {
            buf += step;
            arr = (int*)realloc(arr, buf * sizeof(int));
            if (arr == NULL) {printf("Error: memory allocation failed.\n"); exit(1);}
        }
        *(arr + *len) = number;
        ++(*len);
    }
    return arr;
}

int *filter(int *arr, int len, int *evens_len)
{
    *evens_len = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            ++(*evens_len);
        }        
    }

    int index_evens = 0;
    int *evens = (int*)malloc(*evens_len *sizeof(int));
    for (size_t i = 0; i < len; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            *(evens + index_evens) = *(arr + i);
            ++index_evens;
        }  
    } 
    return evens; 
}

int main(int argc, char const *argv[])
{
    int step = 5;
    int len, evens_len;
    int *arr = get_arr(&len, step);
    int *evens = filter(arr, len, &evens_len);
    for (size_t i = 0; i < evens_len; i++)
    {
        printf("%d\n", *(evens + i));
    }
    free(arr);
    free(evens);
    return 0;
}
