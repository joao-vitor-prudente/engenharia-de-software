# Stack Model

## Stack Exemple

```c
float cilinder_volume(float radius, float height) {
    return 3.14 * radius * radius * height;
}

int main() {
    float radius, height, volume:
    radius = 2.5;
    height = 3.0;
    volume = cilinder_volume(radius, height);
}
```


main starts

    alocate:
    radius
    height
    volume

cilinder_volume start

    alocade:
    radius
    height

cilinder_volume ends

    dealocate:
    radius
    height

main ends 

    dealocate:
    radius
    height
    volume

stack is empty

stack model == first in, last out


## Pointer

Allowes the use of memory addresses to make reference to a variable it self not a copy of its value

```c
int a;  // variavel do tipo inteiro
int *p; // ponteiro do tipo ponteiro para um inteiro
a = 5;  // atribui o valor 5 a variavel a
p = &a; // atribui o endereço de a a variavel p
*p = 6; // atribui o valor 6 a variavel a
```

When you declare variable outside any function, it is called global variable (bad practice) and you can access it everywhere to be modified

```c
int sum;

int add(int a, int b) {
    sum = a + b;
    // there is no need to return sum because sum = a + b modifies the global variable sum
}

int main() {
    add(2, 3);
    printf("%d", sum);
}
```

Avoiding global variables

```c
int add_and_multiply(int a, int b, int *sum, int *product) {
    *sum = a + b  // modifico o valor da variavel que o ponteiro de sum aponta (a propria variavel sum)
    *product = a * b
}

int main() {
    int sum, product;  // inicio soma e produto
    add_and_multiply(2, 3, &sum, &product);  // passo uma referencia a eles para a funcao
    printf("%d", sum);
    printf("%d", product);
}
```

## Vectors

Vectors are a simplificated method to manipulating pointers.

A vector is a sequence in memory of the same type of variable in a row.

Vector in memory:

... | #100 | #104 | #108 | ...

    v => pointer to #100
    v[0] => value of #100
    v[1] = v[0] + size * 1 => value of #104
    v[2] = v[1] + size * 2 => value of #108


You can access v[3] even though it doesn't belong to the array (memory leak) and if you don't know the size of the array, there is no way to tell where it ends

```c
int main() {
    int v[3];
    v[0] = 1;  // value of pointer to head of vector
    v[1] = 2;  // value of pointer to head of vector + 1
    v[2] = 3;  // value of pointer to head of vector + 2
    v[3] = 4;  // memory leak
}
```

## Matrices

Matrices are storeds in memory as a sequence of vectors with the same length

Matrix in memory:

... | #100 | #104 | #108 | #112 | ...