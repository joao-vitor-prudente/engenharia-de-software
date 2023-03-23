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

int sum_arr(int *arr, int len)
{
    int sum = 0;
    for (size_t i = 0; i < len; i++) {sum += *(arr + i);}
    return sum;
    
}

int main(int argc, char const *argv[])
{
    int step = 5;
    int len;
    int *arr = get_arr(&len, step);
    int sum = sum_arr(arr, len);
    printf("sum=%d\n", sum);
    free(arr);
    return 0;
}
