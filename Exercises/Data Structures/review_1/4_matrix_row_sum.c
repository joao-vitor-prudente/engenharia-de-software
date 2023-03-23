#include <stdio.h>
#include <stdlib.h>

typedef struct dimensions 
{
    int rows; 
    int cols;
} 
Dimensions;

void get_dimensions(Dimensions* dimensions)
{
    int rows, cols;
    printf("Enter number of rows:\n");
    scanf("%d", &rows);
    printf("Enter number of columns: \n");
    scanf("%d", &cols);
    dimensions->rows = rows;
    dimensions->cols = cols;
    printf("\n");
}

int **get_matrix(Dimensions* dimensions)
{
    int **matrix = (int**)malloc(dimensions->rows * sizeof(int*));
    if (matrix == NULL)
    {
        printf("could not allocate memory");
        exit(-1);
    }
    
    for (size_t i = 0; i < dimensions->rows; i++)
    {
        int *row = (int*)malloc(dimensions->cols * sizeof(int));
        if (row == NULL)
        {
            printf("could not allocate memory");
            exit(-1);
        }
        *(matrix + i) = row;
        for (size_t j = 0; j < dimensions->cols; j++)
        {
            printf("matrix[%ld][%ld] = \n", i, j);
            scanf("%d", *(matrix + i) + j);
        }  
    }
    printf("\n");
    return matrix;
}

void print_matrix(int** matrix, Dimensions* dimensions)
{
    for (size_t i = 0; i < dimensions->rows; i++)
    {
        for (size_t j = 0; j < dimensions->cols; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");  
    }
    printf("\n");
}

int *rows_sum(int** matrix, Dimensions* dimensions)
{
    int *sum_arr = (int*)malloc(dimensions->rows * sizeof(int));
    if (sum_arr == NULL)
    {
        printf("could not allocate memory");
        exit(-1);
    }
    int sum;

    for (size_t i = 0; i < dimensions->rows; i++)
    {
        sum = 0;
        for (size_t j = 0; j < dimensions->cols; j++)
        {
            sum += *(*(matrix + i) + j);
        }
        sum_arr[i] = sum;   
    }
    return sum_arr;
}

void print_sum_arr(int* sum_arr, Dimensions* dimensions)
{
    for (size_t i = 0; i < dimensions->rows; i++)
    {
        printf("%d\n", *(sum_arr + i));
    }
    
}

int main(int argc, char const *argv[])
{
    Dimensions *dimensions = (Dimensions*)malloc(sizeof(Dimensions));
    if (dimensions == NULL)
    {
        printf("could not allocate memory");
        exit(-1);
    }
    get_dimensions(dimensions);
    int **matrix = get_matrix(dimensions);
    print_matrix(matrix, dimensions);
    int *sum_arr = rows_sum(matrix, dimensions);
    print_sum_arr(sum_arr, dimensions);
    return 0;
}
