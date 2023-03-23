#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "3_coordinate.h"

typedef struct coordinate {
    float x;
    float y;
} Coordinate;

void func(Coordinate* coordinate) {
    coordinate__init__(coordinate, 1.0, 2.0);
    printf("x: %f, y: %f\n", coordinate->x, coordinate->y);
};

void func2(Coordinate** coordinates) {
    coordinate__init__(coordinates[0], 1.0, 2.0);
    coordinate__init__(coordinates[1], 3.0, 4.0);
    printf("x: %f, y: %f\n", coordinates[0]->x, coordinates[0]->y);
    printf("x: %f, y: %f\n", coordinates[1]->x, coordinates[1]->y);
    printf("distance: %f\n", calculate_distance(coordinates[0], coordinates[1]));
}

int main(int argc, char const *argv[])
{   
    void(*f)(Coordinate*) = func;
    //coordinate__context__(f);
    coordinate__shared_context__(func2, 2);
    return 0;
}
 
Coordinate* coordinate__enter__() {
    Coordinate* coordinate = malloc(sizeof(Coordinate));
}

void coordinate__init__(Coordinate* coordinate, float x, float y) {
    coordinate->x = x;
    coordinate->y = y;
}

void coordinate__exit__(Coordinate* coordinate) {
    free(coordinate);
}

void coordinate__context__(void(*f)(Coordinate*)) {
    Coordinate* coordinate = coordinate__enter__();
    f(coordinate);
    coordinate__exit__(coordinate);
}

void coordinate__shared_context__(void(*f)(Coordinate**), int n) {
    Coordinate** coordinates = malloc(sizeof(Coordinate*) * n);
    for (int i = 0; i < n; i++) {
        coordinates[i] = coordinate__enter__();
    }
    f(coordinates);
    for (int i = 0; i < n; i++) {
        coordinate__exit__(coordinates[i]);
    }
}

double calculate_distance(Coordinate* coordinate1, Coordinate* coordinate2) {
    float x = coordinate1->x - coordinate2->x;
    float y = coordinate1->y - coordinate2->y;
    double dist = sqrt(x*x + y*y);
    return dist;
}