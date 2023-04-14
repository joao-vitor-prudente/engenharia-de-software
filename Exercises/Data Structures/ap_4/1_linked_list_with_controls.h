struct LinkedList;

struct Node;

struct LinkedList *new_list();

int push_to_ll(struct LinkedList *list, int data);

int pop_from_ll(struct LinkedList *list);

void print_ll(struct LinkedList *list);

void free_ll(struct LinkedList *list);