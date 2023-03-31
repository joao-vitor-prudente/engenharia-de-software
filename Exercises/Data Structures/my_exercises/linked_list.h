struct LinkedList;

struct Node;

struct LinkedList *new_list();

int push_to_ll(struct LinkedList *list, int data);

int pop_from_ll(struct LinkedList *list);

int insert_into_ll(struct LinkedList *list, int index, int data);

int remove_from_ll(struct LinkedList *list, int index);

int *ll_to_array(struct LinkedList *list);

void print_ll(struct LinkedList *list);

void free_ll(struct LinkedList *list);