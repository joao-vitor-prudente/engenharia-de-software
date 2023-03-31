#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char const *argv[])
{
      int err;
      struct LinkedList *list = new_list();
      if (list == NULL) {printf("could not allocate memory"); return 1;}
      print_ll(list);
      // NULL

      err = push_to_ll(list, 1);
      if (err == 1) {printf("could not allocate memory"); return 1;}
      print_ll(list);
      // 1 -> NULL

      err = push_to_ll(list, 2);
      if (err == 1) {printf("could not allocate memory"); return 1;}
      print_ll(list);
      // 2 -> 1 -> NULL

      err = push_to_ll(list, 3);
      if (err == 1) {printf("could not allocate memory"); return 1;}
      print_ll(list);
      // 3 -> 2 -> 1 -> NULL

      err = push_to_ll(list, 4);
      if (err == 1) {printf("could not allocate memory"); return 1;}
      print_ll(list);
      // 4 -> 3 -> 2 -> 1 -> NULL

      err = pop_from_ll(list);
      if (err == -1) {printf("list is empty"); return 1;}
      // 3 -> 2 -> 1 -> NULL
      print_ll(list);

      err = insert_into_ll(list, 2, 5);
      if (err == 1) {printf("could not allocate memory"); return 1;}
      if (err == -1) {printf("index out of range"); return 1;}
      print_ll(list);
      // 3 -> 2 -> 5 -> 1 -> NULL

      err = remove_from_ll(list, 2);
      if (err == -1) {printf("index out of range"); return 1;}
      print_ll(list);
      // 3 -> 2 -> 1 -> NULL

      int *arr = ll_to_array(list);
      if (arr == NULL) {printf("could not allocate memory"); return 1;}
      for (size_t i = 0; i < 3; i++)
      {
            printf("%d, ", arr[i]);
      }
      // 3, 2, 1,

      free_ll(list);
      return 0;
}

struct LinkedList{
      struct Node *head;
      int size;
};

struct Node {
      int data;
      struct Node *next;
};

struct LinkedList *new_list()
{
      struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
      if (list == NULL) {return NULL;}
      list->head = NULL;
      list->size = 1;
      return list;
}

int push_to_ll(struct LinkedList *list, int data)
{
      struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
      if (new_node == NULL) {return 1;}
      new_node->data = data;
      new_node->next = list->head;
      list->head = new_node;
      list->size++;
      return 0;
}

int pop_from_ll(struct LinkedList *list)
{
      if (list->head == NULL) {return -1;}
      struct Node *temp = list->head;
      list->head = list->head->next;
      list->size--;
      free(temp);
      return 0;
}

int insert_into_ll(struct LinkedList *list, int index, int data)
{
      struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
      if (new_node == NULL) {return 1;}
      new_node->data = data;
      struct Node *temp = list->head;
      for (int i = 0; i < index - 1; i++)
      {
            temp = temp->next;
            if (temp->next == NULL) {return -1;}
      }
      new_node->next = temp->next;
      temp->next = new_node;
      list->size++;
}

int remove_from_ll(struct LinkedList *list, int index)
{
      struct Node *current = list->head;
      for (int i = 0; i < index - 1; i++)
      {
            current = current->next;
            if (current->next == NULL) {return -1;}
      }
      struct Node *temp_node = current->next;
      current->next = temp_node->next;
      free(temp_node);
      list->size--;
      return 0;
}

int *ll_to_array(struct LinkedList *list)
{
      int *array = (int *)malloc(sizeof(int) * list->size);
      if (array == NULL) {return NULL;}
      struct Node *temp = list->head;
      int i = 0;
      while (temp != NULL)
      {
            array[i] = temp->data;
            temp = temp->next;
            i++;
      }
      return array;
}

void print_ll(struct LinkedList *list)
{
      struct Node *temp = list->head;
      while (temp != NULL)
      {
            printf("%d -> ", temp->data);
            temp = temp->next;
      }
      printf("NULL\n");
}

void free_ll(struct LinkedList *list)
{
      int err;
      do {err = pop_from_ll(list);} while (err != -1);
      free(list);
}