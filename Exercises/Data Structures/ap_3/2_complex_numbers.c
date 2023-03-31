#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex Complex;

struct complex
{
      double real;
      double imag;
};

Complex *complex__enter__();

void complex__init__(Complex *c, double real, double imag);

void complex__exit__(Complex *c);

void complex__print__(Complex *c);

Complex *complex__add__(Complex *c1, Complex *c2);

Complex *complex__sub__(Complex *c1, Complex *c2);

Complex *complex__mul__(Complex *c1, Complex *c2);

Complex *complex__div__(Complex *c1, Complex *c2);

int main(int argc, char const *argv[])
{
      Complex *c1 = complex__enter__();
      if (c1 == NULL)
      {
            printf("Error: Memory allocation failed.\n");
            return(1);
      }
      Complex *c2 = complex__enter__();
      if (c2 == NULL)
      {
            printf("Error: Memory allocation failed.\n");
            complex__exit__(c1);
            return(1);
      }
      complex__init__(c1, 1.0, 2.0);
      complex__init__(c2, 3.0, 4.0);

      Complex *c3 = complex__add__(c1, c2);
      if (c3 == NULL)
      {
            printf("Error: Memory allocation failed.\n");
            complex__exit__(c1);
            complex__exit__(c2);
            return(1);
      }
      Complex *c4 = complex__sub__(c1, c2);
      if (c4 == NULL)
      {
            printf("Error: Memory allocation failed.\n");
            complex__exit__(c1);
            complex__exit__(c2);
            complex__exit__(c3);
            return(1);
      }
      Complex *c5 = complex__mul__(c1, c2);
      if (c5 == NULL)
      {
            printf("Error: Memory allocation failed.\n");
            complex__exit__(c1);
            complex__exit__(c2);
            complex__exit__(c3);
            complex__exit__(c4);
            return(1);
      }
      Complex *c6 = complex__div__(c1, c2);
      if (c6 == NULL)
      {
            printf("Error: Memory allocation failed.\n");
            complex__exit__(c1);
            complex__exit__(c2);
            complex__exit__(c3);
            complex__exit__(c4);
            complex__exit__(c5);
            return(1);
      }

      complex__print__(c1);
      complex__print__(c2);
      complex__print__(c3);
      complex__print__(c4);
      complex__print__(c5);
      complex__print__(c6);

      complex__exit__(c1);
      complex__exit__(c2);
      complex__exit__(c3);
      complex__exit__(c4);
      complex__exit__(c5);
      complex__exit__(c6);
      return 0;
}


Complex *complex__enter__()
{
      Complex *complex = (Complex *)malloc(sizeof(Complex));
      return complex;
}

void complex__init__(Complex *c, double real, double imag)
{
      c->real = real;
      c->imag = imag;
}

void complex__exit__(Complex *c)
{
      free(c);
}

void complex__print__(Complex *c)
{
      printf("%f + %fi\n", c->real, c->imag);
}

Complex *complex__add__(Complex *c1, Complex *c2)
{
      Complex *c3 = complex__enter__();
      if (c3 == NULL)
      {
            return NULL;
      }
      c3->real = c1->real + c2->real;
      c3->imag = c1->imag + c2->imag;
      return c3;
}

Complex *complex__sub__(Complex *c1, Complex *c2)
{
      Complex *c3 = complex__enter__();
      if (c3 == NULL)
      {
            return NULL;
      }
      c3->real = c1->real - c2->real;
      c3->imag = c1->imag - c2->imag;
      return c3;
}

Complex *complex__mul__(Complex *c1, Complex *c2)
{
      Complex *c3 = complex__enter__();
      if (c3 == NULL)
      {
            return NULL;
      }
      c3->real = c1->real * c2->real - c1->imag * c2->imag;
      c3->imag = c1->real * c2->imag + c1->imag * c2->real;
      return c3;
}

Complex *complex__div__(Complex *c1, Complex *c2)
{
      Complex *c3 = complex__enter__();
      if (c3 == NULL)
      {
            return NULL;
      }
      c3->real = (c1->real * c2->real + c1->imag * c2->imag) / (c2->real * c2->real + c2->imag * c2->imag);
      c3->imag = (c1->imag * c2->real - c1->real * c2->imag) / (c2->real * c2->real + c2->imag * c2->imag);
      return c3;
}