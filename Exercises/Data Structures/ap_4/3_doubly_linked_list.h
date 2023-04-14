
struct LinkedList;

struct Node;

struct LinkedList *create_ll();

int push_first(struct LinkedList *list, int data);

int push_last(struct LinkedList *list, int data);

int pop_first(struct LinkedList *list);

int pop_last(struct LinkedList *list);

int pop_node(struct LinkedList *list, struct Node *node);

int push_by_index(struct LinkedList *list, int index, int data);

int pop_by_index(struct LinkedList *list, int index);

void pop_by_value(struct LinkedList *list, int value, bool all);

struct LinkedList *filter(struct LinkedList *list, bool (*func)(int));

struct LinkedList *map(struct LinkedList *list, int (*func)(int));

struct LinkedList *scan(struct LinkedList *list, int (*func)(int, int), int initial);

struct LinkedList *create_range(int lower_bound, int upper_bound, int step);

struct LinkedList *reverse(struct LinkedList *list);

void sort(struct LinkedList *list, int *(*func)(int*, int*));

int reduce(struct LinkedList *list, int (*func)(int, int), int initial);

void print_ll(struct LinkedList *list);

void free_ll(struct LinkedList *list);