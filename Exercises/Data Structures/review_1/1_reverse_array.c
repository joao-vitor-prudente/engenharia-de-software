#include <stdio.h>
#include <stdlib.h>

int get_len();

float *get_arr(int n);

float *reverse(int n, float *v);

int main(int argc, char const *argv[])
{
    int n = get_len();

    float *v = get_arr(n);

    if (v == NULL)
    {
        printf("Error: memory could not be allocated.");
        return -1;
    }

    float *r = reverse(n, v);

    if (r == NULL)
    {
        printf("Error: memory could not be allocated.");
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%f ", r[i]);
    }
    free(v);
    free(r);
    return 0;
}

int get_len()
{
    int n;
    printf("Input size of array: ");
    scanf("%d", &n);
    return n;
}


float *get_arr(int n)
{
    float *v = (float *)malloc(n * sizeof(float));

    if (v == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < n; i++)
    {
        scanf("%f", &v[i]);
    }
    return v;
    
}

float *reverse(int n, float *v)
{
    float *r = (float *)malloc(n * sizeof(float));

    if (r == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < n; i++)
    {
        r[n - i - 1] = v[i];
    }
    return r;
}   