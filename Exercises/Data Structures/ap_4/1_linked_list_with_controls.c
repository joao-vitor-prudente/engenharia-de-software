#include <stdio.h>
#include <stdlib.h>
#include "1_linked_list_with_controls.h"

int main(int argc, char const *argv[])
{
      int res = 0;
      int err = 0;
      struct LinkedList *list = new_list();
      if (list == NULL) {printf("Error: Memory allocation failed.\n"); return 1;}

      while (res != 3 && err != 1)
      {
            printf("0. Push to list\n");
            printf("1. Pop from list\n");
            printf("2. Print list\n");
            printf("3. Exit\n");
            printf("Enter your choice: \n");
            scanf("%d", &res);
            if (res == 0)
            {
                  int data;
                  printf("Enter data: ");
                  scanf("%d", &data);
                  err = push_to_ll(list, data);
                  if (err == 1) printf("Error: Memory allocation failed.\n");
                  continue;
            }
            if (res == 1)
            {
                  err = pop_from_ll(list);
                  if (err == -1) printf("Error: List is empty.\n");
                  continue;
            }
            if (res == 2)
            {
                  print_ll(list);
                  continue;
            }
            if (res != 3) printf("Error: Invalid choice.\n");
            
      }
      free_ll(list);
      return 0;
}

struct LinkedList{
      struct Node *head;
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
      return list;
}

int push_to_ll(struct LinkedList *list, int data)
{
      struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
      if (new_node == NULL) {return 1;}
      new_node->data = data;
      new_node->next = list->head;
      list->head = new_node;
      return 0;
}

int pop_from_ll(struct LinkedList *list)
{
      if (list->head == NULL) {return -1;}
      struct Node *temp = list->head;
      list->head = list->head->next;
      free(temp);
      return 0;
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