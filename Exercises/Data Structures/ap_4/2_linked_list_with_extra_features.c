#include <stdio.h>
#include <stdlib.h>
#include "2_linked_list_with_extra_features.h"

int enter_list(struct LinkedList *list, int option)
{
      int size, err;
      printf("How many items to push to list?\n");
      scanf("%d", &size);
      for (size_t i = 0; i < size; i++)
      {
            int cur;
            printf("Enter item %ld:\n", i+1);
            scanf("%d", &cur);
            err = (option == 0) ? push_to_ll(list, cur) : prepend(list, cur);
            if (err == 1) break;
      }
      return err;
}

int main(int argc, char const *argv[])
{
      struct LinkedList *list1 = new_list();
      if (list1 == NULL) {printf("Error: Could not allocate memory for list1"); return 1;}
      struct LinkedList *list2 = new_list();
      if (list2 == NULL) {printf("Error: Could not allocate memory for list2"); return 1;}
      int err;
      
      err = enter_list(list1, 0);
      if (err == 1) {printf("Error: Could not allocate memory for node"); return 1;}
      err = enter_list(list2, 1);
      if (err == 1) {printf("Error: Could not allocate memory for node"); return 1;}
      
      print_ll(list1);
      print_ll(list2);

      printf("Length of list1: %d\n", get_length(list1));
      printf("Length of list2: %d\n", get_length(list2));

      printf("Last item of list1: %d\n", get_tail(list1));
      printf("Last item of list2: %d\n", get_tail(list2));

      printf("Type a number to filter by: \n");
      int filter;
      scanf("%d", &filter);
      printf("Number of items in list1 greater than %d: %d\n", filter, filter_greater_than(list1, filter));
      printf("Number of items in list2 greater than %d: %d\n", filter, filter_greater_than(list2, filter));
      printf("List1 concatenated with list2:\n");
      concat(list1, list2);
      print_ll(list1);
      free_ll(list1);
      free(list2);
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

int get_length(struct LinkedList *list)
{
      int len = 0;
      struct Node *current = list->head;
      while (current != NULL) 
      {
            len++;
            current = current->next;
      }
      return len;
}

int filter_greater_than(struct LinkedList *list, int value)
{
      int len = 0;
      struct Node *current = list->head;
      while (current != NULL) 
      {
            if (current->data > value) len++;
            current = current->next;
      }
      return len;
}

int get_tail(struct LinkedList *list)
{
      struct Node *current = list->head;
      while (current->next != NULL) current = current->next;
      return current->data;
}

int concat(struct LinkedList *list1, struct LinkedList *list2)
{
      struct Node *tail_list1 = list1->head;
      while (tail_list1->next != NULL) tail_list1 = tail_list1->next;
      tail_list1->next = list2->head;
}

int prepend(struct LinkedList *list, int data)
{
      struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
      if (new_node == NULL) {return 1;}
      new_node->data = data;
      struct Node *tail = list->head;
      if (tail == NULL) {
            list->head = new_node; 
            return 0;
      }
      while (tail->next != NULL) tail = tail->next;
      tail->next = new_node;
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