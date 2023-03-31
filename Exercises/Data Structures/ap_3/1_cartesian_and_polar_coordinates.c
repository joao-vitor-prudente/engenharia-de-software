#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cartesian Cartesian;

typedef struct polar Polar;

struct cartesian
{
      double x;
      double y;
};

struct polar
{
      double r;
      double theta;
};

Cartesian *cartesian__enter__();

Polar *polar__enter__();

void cartesian__init__(Cartesian *cartesian, double x, double y);

void polar__init__(Polar *cartesian, double r, double theta);

void cartesian__exit__(Cartesian *cartesian);

void polar__exit__(Polar *cartesian);

Polar *cartesian_to_polar(Cartesian *cartesian);

Cartesian *polar_to_cartesian(Polar *polar);

int main(int argc, char const *argv[])
{
      Cartesian *cartesian = cartesian__enter__();
      if (cartesian == NULL) {
            printf("could not allocate memory"); 
            return 1;
      }
      Polar *polar = polar__enter__();
      if (polar == NULL) {
            printf("could not allocate memory"); 
            cartesian__exit__(cartesian);
            return 1;
      }

      cartesian__init__(cartesian, 9, 0);
      polar__init__(polar, 9, 0);

      Polar *polar2 = cartesian_to_polar(cartesian);
      if (polar2 == NULL) {
            printf("could not allocate memory"); 
            cartesian__exit__(cartesian);
            polar__exit__(polar);
            return 1;
      }
      Cartesian *cartesian2 = polar_to_cartesian(polar);
      if (cartesian2 == NULL) {
            printf("could not allocate memory"); 
            cartesian__exit__(cartesian);
            polar__exit__(polar);
            polar__exit__(polar2);
            return 1;
      }

      printf("cartesian1: x=%f, y=%f\n", cartesian->x, cartesian->y);
      printf("cartesian2: x=%f, y=%f\n", cartesian2->x, cartesian2->y);
      printf("polar1: r=%f, Θ=%f\n", polar->r, polar->theta);
      printf("polar2: r=%f, Θ=%f\n", polar2->r, polar2->theta);

      cartesian__exit__(cartesian);
      cartesian__exit__(cartesian2);
      polar__exit__(polar);
      polar__exit__(polar2);
      return 0;
}

Cartesian *cartesian__enter__()
{
      Cartesian *cartesian = (Cartesian *)malloc(sizeof(Cartesian));
      return cartesian;
}

Polar *polar__enter__()
{
      Polar *polar = (Polar *)malloc(sizeof(Polar));
      return polar;
}

void cartesian__init__(Cartesian *cartesian, double x, double y)
{
      cartesian->x = x;
      cartesian->y = y;
}

void polar__init__(Polar *polar, double r, double theta)
{
      polar->r = r;
      polar->theta = theta;
}

void cartesian__exit__(Cartesian *cartesian)
{
      free(cartesian);
}

void polar__exit__(Polar *polar)
{
      free(polar);
}

Polar *cartesian_to_polar(Cartesian *cartesian)
{
      Polar *polar = polar__enter__();
      if (polar == NULL) {return NULL;}
      double r = sqrt(pow(cartesian->x, 2) + pow(cartesian->y, 2));
      double w = atan(cartesian->y / cartesian->x);
      polar__init__(polar, r, w);
      return polar;
}

Cartesian *polar_to_cartesian(Polar *polar)
{
      Cartesian *cartesian = cartesian__enter__();
      if (cartesian == NULL) {return NULL;}
      double x = cos(polar->theta) * polar->r;
      double y = sin(polar->theta) * polar->r;
      cartesian__init__(cartesian, x, y);
      return cartesian;
}