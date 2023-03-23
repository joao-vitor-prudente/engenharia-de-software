#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
    char name[81];
    float hourly_payment;
    int mounthly_hours;
}
Employee;

Employee** register_employees(int n)
{
    Employee **employees = (Employee**)malloc(sizeof(Employee*) * n);

    if (employees == NULL) {printf("Error: memory allocation failed.\n"); exit(1);}

    for (size_t i = 0; i < n; i++)
    {
        Employee *employee = (Employee*)malloc(sizeof(Employee));

        if (employee == NULL) {printf("Error: memory allocation failed.\n"); exit(1);}

        printf("Enter employee name:\n");
        scanf("%s", employee->name);        
        printf("Enter employee hourly payment:\n");
        scanf("%f", &(employee->hourly_payment));
        printf("Enter employee mounthly hours:\n");
        scanf("%d", &(employee->mounthly_hours));

        *(employees + i) = employee;
        
    }
    return employees;    
}

Employee* search_employee(Employee **employees, int n)
{
    char name[81];
    printf("Enter employee name:\n");
    scanf("%s", name);  
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp((*(employees + i))->name, name) == 0)
        {
            return (*(employees + i));
        }
    }
    return NULL;
}

void print_employees(Employee **employees, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("{%s, %f, %d}\n", (*(employees + i))->name, (*(employees + i))->hourly_payment, (*(employees + i))->mounthly_hours);
    }    
}

void cleanup(Employee **employees, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(*(employees + i));
    }
    free(employees);
}

int main(int argc, char const *argv[])
{
    printf("Enter number of employees:\n");
    int n;
    scanf("%d", &n);
    Employee **employees = register_employees(n);
    print_employees(employees, n);
    Employee *employee = search_employee(employees, n);
    if (employee == NULL) {printf("Employee not found.\n"); exit(1);}
    printf("{%s, %f, %d}\n", employee->name, employee->hourly_payment, employee->mounthly_hours);
    cleanup(employees, n);
    return 0;
}
