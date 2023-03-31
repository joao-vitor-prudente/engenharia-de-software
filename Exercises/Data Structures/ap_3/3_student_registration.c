#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student Student;

struct student
{
      char *name;
      float grade1, grade2, grade3;
};

typedef struct registry Registry;

struct registry
{
      Student **students;
      int len;
};

Student *student__enter__();

void student__init__(Student *student, char name[20], float grade1, float grade2, float grade3);

void student__exit__(Student *student);

Registry *registry__enter__();

void registry__init__(Registry *registry);

void registry__exit__(Registry *registry);

int push_to_registry(Registry *registry, Student *student);

int main(int argc, char const *argv[])
{
      Registry *registry = registry__enter__();
      if (registry == NULL)
      {
            return -1;
      }
      while (1)
      {
            printf("Enter student name:\n");
            char name[20];
            scanf("%s", name);
            if (strcmp(name, "nao") == 0){break;}
            printf("Enter student grades:\n");
            float grade1, grade2, grade3;
            scanf("%f %f %f", &grade1, &grade2, &grade3);
            Student *student = student__enter__();
            if (student == NULL)
            {
                  printf("Error: could not allocate memory.\n");
                  registry__exit__(registry);
                  return -1;
            }
            student__init__(student, name, grade1, grade2, grade3);
            int err = push_to_registry(registry, student);
            if (err == -1)
            {
                  printf("Error: could not allocate memory.\n");
                  registry__exit__(registry);
                  return -1;
            }
      }
      for (size_t i = 0; i < registry->len; i++)
      {
            printf(
                  "Student %s has grades %.2f, %.2f, %.2f\n", 
                  registry->students[i]->name, 
                  registry->students[i]->grade1, 
                  registry->students[i]->grade2, 
                  registry->students[i]->grade3
            );
      }
      registry__exit__(registry);
      return 0;
}

Student *student__enter__()
{
      Student *student = (Student *)malloc(sizeof(Student));
      return student;
}

void student__init__(Student *student, char *name, float grade1, float grade2, float grade3)
{
      student->name = (char *)malloc(20 * sizeof(char));
      strcpy(student->name, name);
      student->grade1 = grade1;
      student->grade2 = grade2;
      student->grade3 = grade3;
}

void student__exit__(Student *student)
{
      free(student);
}

Registry *registry__enter__()
{
      Registry *registry = (Registry *)malloc(sizeof(Registry));
      return registry;
}

void registry__init__(Registry *registry)
{
      registry->len = 0;
      registry->students = (Student **)malloc(sizeof(Student *));
}

void registry__exit__(Registry *registry)
{
      for (size_t i = 0; i < registry->len; i++)
      {
            student__exit__(registry->students[i]);
      }
      free(registry->students);
      free(registry);
}

int push_to_registry(Registry *registry, Student *student)
{
      registry->students = (Student **)realloc(registry->students, (registry->len + 1) * sizeof(Student *));
      if (registry->students == NULL)
      {
            return -1;
      }
      registry->students[registry->len] = student;
      registry->len++;
      return 0;
}


