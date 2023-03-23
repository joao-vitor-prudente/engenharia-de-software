#include <stdio.h>
#include <stdlib.h>

typedef struct person Person;

int get_len();

Person **allocate_arr(int len);

int fill_arr(Person **arr, int len);

void print_arr(Person **arr, int len);

void free_arr(Person **arr);

int main(int argc, char const *argv[])
{
      int len = get_len();
      Person **arr = allocate_arr(len);
      if (arr == NULL)
      {
            printf("Error: could not allocate memory.");
            return 1;
      }
      int err = fill_arr(arr, len);
      if (err == 1)
      {
            printf("Error: could not allocate memory.");
            return 1;
      }
      
      print_arr(arr, len);
      free_arr(arr);
      return 0;
}

typedef struct person
{
      char *name;
      int age;
      float height;    
}
Person;

int get_len()
{
      int len;
      printf("Enter array length:\n");
      scanf("%d", &len);
      return len;
}

Person **allocate_arr(int len)
{
      Person **arr = (Person**)malloc(len * sizeof(Person*));
      if (arr == NULL)
      {
            return NULL;
      }
      
      return arr;
}

int fill_arr(Person **arr, int len)
{
      for (size_t i = 0; i < len; i++)
      {
            char *name = (char*)malloc(50 * sizeof(char));
            if (name == NULL) {return 1;}
            
            int age;
            float height;

            printf("Enter name:\n");
            scanf("%s%*c", name);

            printf("Enter age:\n");
            scanf("%d", &age);

            printf("Enter height:\n");
            scanf("%f", &height);
            
            Person *p = (Person*)malloc(sizeof(Person));
            if (p == NULL) {return 1;}
            p->name = name;
            p->age = age;
            p->height = height;
            *(arr + i) = p;
      } 
      return 0;
}

void print_arr(Person **arr, int len)
{
      for (size_t i = 0; i < len; i++)
      {
            Person *p = *(arr + i);
            printf("{\n\tname: %s\n\tage: %d\n\theight: %f\n}\n", p->name, p->age, p->height);
      }
}

void free_arr(Person **arr)
{
      free(arr);
}

