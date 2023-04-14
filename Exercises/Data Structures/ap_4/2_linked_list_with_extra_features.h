struct LinkedList;

struct Node;

struct LinkedList *new_list();

int push_to_ll(struct LinkedList *list, int data);

int pop_from_ll(struct LinkedList *list);

int get_length(struct LinkedList *list);

int filter_greater_than(struct LinkedList *list, int value);

int get_tail(struct LinkedList *list);

int concat(struct LinkedList *list1, struct LinkedList *list2);

int prepend(struct LinkedList *list, int data);

void print_ll(struct LinkedList *list);

void free_ll(struct LinkedList *list);