typedef struct coordinate Coordinate;


void coordinate__init__(Coordinate* coordinate, float x, float y);

Coordinate* coordinate__enter__();

void coordinate__exit__(Coordinate* coordinate);

void coordinate__context__(void(*f)(Coordinate*));

void coordinate__shared_context__(void(*f)(Coordinate**), int);

double calculate_distance(Coordinate* coordinate1, Coordinate* coordinate2);