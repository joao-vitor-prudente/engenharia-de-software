#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "3_doubly_linked_list.h"

struct LinkedList
{
      struct Node *head;
      struct Node *tail;
      int size;
};

struct Node
{
      int data;
      struct Node *next;
      struct Node *prev;
};

bool exemple_filter(int value) 
{
      return value > 2;
}

int exemple_map(int value)
{
      return value * value;
}

int exemple_reduce(int acc, int cur)
{
      return acc * cur;
}

int *exemple_sort(int *left, int *right)
{
      return (*left > *right) ? left : right;
}

int main(int argc, char const *argv[])
{
      struct LinkedList *list = create_ll();
      if (list == NULL) {printf("Could not allocate memory for list");return 1;}
      print_ll(list);
      // NULL

      int err;

      err = push_first(list, 1);
      if (err == 1) {printf("Could not allocate memory for node");return 1;}
      print_ll(list);
      // NULL 1 NULL

      err = push_first(list, 2);
      if (err == 1) {printf("Could not allocate memory for node");return 1;}
      print_ll(list);
      // NULL 2 1 NULL

      err = push_first(list, 3);
      if (err == 1) {printf("Could not allocate memory for node");return 1;}
      print_ll(list);
      // NULL 3 2 1 NULL

      err = push_first(list, 4);
      if (err == 1) {printf("Could not allocate memory for node");return 1;}
      print_ll(list);
      // NULL 4 3 2 1 NULL

      err = push_first(list, 3);
      if (err == 1) {printf("Could not allocate memory for node");return 1;}
      print_ll(list);
      // NULL 3 4 3 2 1 NULL

      err = push_first(list, 3);
      if (err == 1) {printf("Could not allocate memory for node");return 1;}
      print_ll(list);
      // NULL 3 3 4 3 2 1 NULL

      err = push_first(list, 2);
      if (err == 1) {printf("Could not allocate memory for node");return 1;}
      print_ll(list);
      // NULL 2 3 3 4 3 2 1 NULL

      struct LinkedList *filtered_list = filter(list, exemple_filter);
      if (filtered_list == NULL) {printf("Could not allocate memory for list");return 1;}
      print_ll(filtered_list);
      // NULL 3 3 4 3 NULL

      struct LinkedList *mapped_list = map(filtered_list, exemple_map);
      if (mapped_list == NULL) {printf("Could not allocate memory for list");return 1;}
      print_ll(mapped_list);
      // NULL 9 9 16 9 NULL
      
      struct LinkedList *range_6 = create_range(2, 6, 1);
      if (range_6 == NULL) {printf("Could not allocate memory for list");return 1;}
      print_ll(range_6);
      // NULL 5 4 3 2 NULL

      struct LinkedList *accumulated_range = scan(range_6, exemple_reduce, 1);
      if (accumulated_range == NULL) {printf("Could not allocate memory for list");return 1;}
      print_ll(accumulated_range);
      // NULL 120 60 20 5 NULL

      int factorial = reduce(range_6, exemple_reduce, 1);
      printf("%d\n", factorial);

      struct LinkedList *reversed_list = reverse(accumulated_range);
      if (reversed_list == NULL) {printf("Could not allocate memory for list");return 1;}
      print_ll(reversed_list);
      // NULL 5 20 60 120 NULL      

      sort(list, exemple_sort);
      print_ll(list);

      free_ll(list);
      free_ll(filtered_list);
      free_ll(mapped_list);
      free_ll(range_6);
      free_ll(accumulated_range);
      free_ll(reversed_list);
      return 0;
}

struct LinkedList *create_ll()
{
      struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
      if (list == NULL)
      {
            return NULL;
      }
      list->head = NULL;
      list->tail = NULL;
      list->size = 0;
      return list;
}

int push_first(struct LinkedList *list, int data)
{
      struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
      if (new_node == NULL)
            return 1;
      new_node->data = data;
      list->size++;

      if (list->head == NULL)
      {
            list->head = new_node;
            list->tail = new_node;
            new_node->next = NULL;
            new_node->prev = NULL;
            return 0;
      }

      new_node->next = list->head;
      new_node->prev = NULL;
      list->head->prev = new_node;
      list->head = new_node;
      return 0;
}

int push_last(struct LinkedList *list, int data)
{
      struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
      if (new_node == NULL)
            return 1;
      new_node->data = data;
      list->size++;

      if (list->tail == NULL)
      {
            list->tail = new_node;
            list->head = new_node;
            new_node->prev = NULL;
            new_node->next = NULL;
            return 0;
      }

      new_node->prev = list->tail;
      new_node->next = NULL;
      list->tail->next = new_node;
      list->tail = new_node;
      return 0;
}

int pop_first(struct LinkedList *list)
{
      if (list->head == NULL)
            return -1;

      if (list->head->next == NULL)
      {
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            return 0;
      }

      struct Node *head = list->head;
      struct Node *new_head = head->next;
      free(head);
      list->head = new_head;
      new_head->prev = NULL;
      return 0;
}

int pop_last(struct LinkedList *list)
{
      if (list->tail == NULL)
            return -1;

      list->size--;

      if (list->tail->prev == NULL)
      {
            free(list->tail);
            list->tail = NULL;
            list->head = NULL;
            return 0;
      }

      struct Node *tail = list->tail;
      struct Node *new_tail = tail->prev;
      free(tail);
      list->tail = new_tail;
      new_tail->next = NULL;
      return 0;
}

int pop_node(struct LinkedList *list, struct Node *node)
{
      if (list->head == node) return pop_first(list);
      if (list->tail == node) return pop_last(list);
      struct Node *before = node->prev;
      struct Node *after = node->next;
      before->next = after;
      after->prev = node;
      free(node);
      list->size--;
      return 0;
}

int push_by_index(struct LinkedList *list, int index, int data)
{
      if (index == 0)
            return push_first(list, data);

      struct Node *before = list->head;

      for (size_t i = 0; i < index - 1; i++)
      {
            if (before == NULL)
                  return -1;
            before = before->next;
      }

      if (before->next == NULL)
            return push_last(list, data);

      struct Node *after = before->next;

      struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
      if (new_node == NULL)
            return 1;
      new_node->data = data;

      before->next = new_node;
      new_node->prev = before;
      new_node->next = after;
      after->prev = new_node;
      list->size++;
      return 0;
}

int pop_by_index(struct LinkedList *list, int index)
{
      if (index == 0)
            return pop_first(list);

      struct Node *to_pop = list->head;
      for (size_t i = 0; i < index; i++)
      {
            if (to_pop == NULL)
                  return -1;
            to_pop = to_pop->next;
      }

      struct Node *before = to_pop->prev;
      struct Node *after = to_pop->next;
      if (to_pop->next == NULL)
            return pop_last(list);
      free(to_pop);
      before->next = after;
      after->prev = before;
      list->size--;
      return 0;
}

void pop_by_value(struct LinkedList *list, int value, bool all)
{
      struct Node *current = list->head;
      
      while (current != NULL) {
            if (current->data != value)
            {
                  current = current->next;
                  continue;
            }
            struct Node *temp = current;
            if (current == list->head) list->head = current->next;
            else current->prev->next = current->next;

            if (current == list->tail) list->tail = current->prev;
            else current->next->prev = current->prev;

            current = current->next;
            free(temp);
            list->size--;
            if (!all) return;
      }
}

struct LinkedList *filter(struct LinkedList *list, bool (*func)(int))
{
      struct LinkedList *new_list = create_ll();
      if (new_list == NULL) return new_list;
      struct Node *current = list->head;
      int err;
      while (current != NULL)
      {
            bool check = func(current->data);
            if (!check)
            {
                  current = current->next;
                  continue;
            }
            err = push_first(new_list, current->data);
            current = current->next;
            if (err != 1) continue;
            free_ll(new_list);
            return NULL;
      }
      return new_list;
}

struct LinkedList *map(struct LinkedList *list, int (*func)(int))
{
      struct LinkedList *new_list = create_ll();
      if (new_list == NULL) return new_list;
      struct Node *current = list->head;
      int err, value;
      while (current != NULL)
      {
            value = func(current->data);
            err = push_first(new_list, value);
            current = current->next;
            if (err != 1) continue;
            free_ll(new_list);
            return NULL;
      }
      return new_list;
}

struct LinkedList *scan(struct LinkedList *list, int (*func)(int, int), int initial)
{
      struct LinkedList *new_list = create_ll();
      if (new_list == NULL) return new_list;
      struct Node *current = list->head;
      int acc = initial;
      int err, value;
      while (current != NULL)
      {
            value = func(acc, current->data);
            acc = value;
            err = push_first(new_list, value);
            current = current->next;
            if (err != 1) continue;
            free_ll(new_list);
            return NULL;
      }
      return new_list;
}

struct LinkedList *create_range(int lower_bound, int upper_bound, int step)
{
      struct LinkedList *range = create_ll();
      if (range == NULL) return range;
      int err;

      for (size_t i = lower_bound; i < upper_bound; i += step)
      {
            err = push_first(range, i);
            if (err != 1) continue;
            free_ll(range);
            return NULL;
      }
      return range;
}

struct LinkedList *reverse(struct LinkedList *list)
{
      struct LinkedList *new_list = create_ll();
      if (new_list == NULL) return new_list;
      int err;
      struct Node *current = list->head;
      while (current != NULL)
      {
            err = push_first(new_list, current->data);
            current = current->next;
            if (err != 1) continue;
            free_ll(new_list);
            return NULL;
      }
      return new_list;
}

void sort(struct LinkedList *list, int *(*func)(int*, int*))
{
      struct Node *current = list->head;

      int *first, *left, *right;
      int temp;
      for (size_t i = 0; i < list->size - 1; i++)
      {
            for (size_t j = 0; j < list->size - 1 - i; j++)
            {
                  left = &(current->data);
                  right = &(current->next->data);
                  first = func(left, right);
                  if (first == right)
                  {
                        temp = current->data;
                        current->data = current->next->data;
                        current->next->data = temp;
                  }
                  current = current->next;      
            }
            current = list->head;  
      }   
}

int reduce(struct LinkedList *list, int (*func)(int, int), int initial)
{
      struct Node *current = list->head;
      int acc = initial;
      int value;
      while (current != NULL)
      {
            value = func(acc, current->data);
            acc = value;
            current = current->next;
      }
      return acc;
}

void print_ll(struct LinkedList *list)
{
      struct Node *temp = list->head;
      if (temp != NULL) printf("NULL ");
      while (temp != NULL)
      {
            printf("%d ", temp->data);
            temp = temp->next;
      }
      printf("NULL\n");
}

void free_ll(struct LinkedList *list)
{
      int err = 0;
      while (list->head != NULL)
      {
            pop_first(list);
      }
      free(list);
}