# Exercicio 3

## 1 - o conjunto-verdade das proposicoes nos numeros naturais

- ### A) 

### $$ P(x) = x + 2 > 7 $$

$$ \{ x \in \mathbb{N} | x\> 5 \} $$

- ### B) 

### $$ P(x) = x + 5 < 3 $$

$$ \varnothing $$

- ### C) 

### $$ P(x) = x + 5 > 1 $$

$$ \mathbb{N} $$

## 2 - seja A = {1, 2, 3, 4, 5} determine o valor logico das afirmacoes

- ### A) 

### $$ P = \exists x \in A | x + 3 = 10 $$

$$ x = 7 \land 7 \notin A \implies P = F $$

- ### B) 

### $$ P = \exists x \in A | x + 3 < 5 $$

$$ x < 2 \land 1 < 2 \land 1 \in A \implies P = V $$

- ### C) 

### $$ P = \exists x \in A | x + 3 < 10 $$

$$ x < 7 \land x < 7 \forall x \in A \implies P = V $$

- ### D) 

### $$ P = \exists x \in A | x + 3 \leq 7 $$

$$ x \leq 4 \land x \leq 4 \forall x \in B := \{1, 2, 3, 4\} \land A \cup B \neq \varnothing \implies P = V $$

## 3 - seja B = {1, 2, 3} determine o valor logico das afirmacoes

- ### A)

### $$ P = \exists x \forall y | Q := x² < y + 1 = V $$

$$ y = 1 \land x = 1 \space satisfaz \space Q $$

$$ y = 2 \land x = 1 \space satisfaz \space Q $$

$$ y = 3 \land x = 1 \space satisfaz \space Q $$

$$ \therefore \forall y \in B, \exists x \in B | x² < y + 1 $$

$$ \implies P = V $$

- ### B)

### $$ P = \forall x \exists y | Q := x² + y² < 12 = V $$

$$ x = 1 \land y = 1 \space satisfaz \space Q $$

$$ x = 2 \land y = 1 \space satisfaz \space Q $$

$$ x = 3 \land y = 1 \space satisfaz \space Q $$

$$ \therefore \forall x \in B, \exists y \in B | x² + y² < 12 $$

$$ \implies P = V $$

- ### C)

### $$ P = \forall x \forall y | Q := x² + y² < 12 = V $$

$$ x = 3 \land y = 3 \space nao \space satisfaz \space Q $$

$$ \therefore \exists x \in B | \exists y \in B | x² + y² > 12 $$

$$ \implies P = F $$

## 4 - negue as afirmacoes

- ### A) 

### Todos os estudantes moram em dormitórios

Existe pelo menos um estudante que nao mora em dormitorio

- ### B)

### Todos os grandes físicos são do sexo masculino

Existe pelo menos um fisico que nao é do sexo masculino

- ### C)

### Alguns estudantes têm 22 anos de idade ou mais

Nao existe nenhum estudante que tenha menos de 22 anos

- ### D)

### Se o professor está ausente, então alguns estudantes não terminam seu projeto

Se o professor esta presente entao todos os alunos termonam seu projeto

- ### E)

### Todos os estudantes terminaram seu projeto e o professor está presente

Existe pelo menos um aluno que nao terminou o projeto ou o professor nao esta presente

- ### F)

### Alguns estudantes não terminama o seu projeto ou o professor está ausente

Todos os alunos terminaram seu projeto e o professor esta presente

- ### G)

### $$ \exists x \forall y, P(x, y) $$

$$ \exists y | P(x, y) \space é \space falso \space \forall x $$

- ### H)

### $$ \exists x \forall y, P(x, y) $$

$$ \exists y | P(x, y) \space é \space falso \space \forall x $$

- ### I)

### $$ \exists x \exists y \forall z, P(x, y, z) $$

$$ \exists z | P(x, y, z) \space é \space falso \space \forall x, y $$

## 5 - determinar se P(x) := x + 2 = 5 é uma funcao proposicional para os dominios

- ### A)

### $$ \mathbb{N} $$

- conjunto verdade:

$$ \{ 3 \} $$

- conjunto falsidade:

$$ \mathbb{N} - \{ 3 \} $$

- ### B)

### $$ M = \{ -x |x \in \mathbb{N} \} $$

- conjunto verdade:

$$ \varnothing $$

- conjunto falsidade:

$$ M $$

- ### C)

### $$ \mathbb{C} $$

- conjunto verdade:

$$ \{ 3 \} $$

- conjunto falsidade:

$$ \mathbb{C} - \{ 3 \} $$

## 6 - achar contra exemplo no conjunto C ={3, 5, 7, 9}

- ### A)

### $$ x + 3 \geq 7 \forall x $$

$$ 3 \in C \land 3 + 3 < 7 $$

$$ 5 \in C \land 5 + 3 > 7 $$

$$ \therefore contra-exemplos = \{ 3 \} $$

- ### B)

### $$ x \equiv 1 mod 2  \forall x $$

$$ 3 = 1 + 1 * 2 \equiv 1 mod 2 $$

$$ 5 = 1 + 2 * 2 \equiv 1 mod 2 $$

$$ 7 = 1 + 3 * 2 \equiv 1 mod 2 $$

$$ 9 = 1 + 4 * 2 \equiv 1 mod 2 $$

$$ \therefore contra-exemplos = \varnothing $$

- ### C)

### $$ x \in \mathbb{P} \forall x $$

$$ P \subset \mathbb{N} \land C \subset \mathbb{N} \land \forall x \in C, 2 < x < 10 $$

$$ D = \{ x \in \mathbb{P} | 2 < x < 10 \} = \{ 3, 5, 7 \} $$

$$ C - D = \{ 9 \} $$

$$ \therefore contra-exemplos = \{ 9 \} $$

- ### D)

### $$ |x| = x \forall x $$

$$ C \subset \mathbb{N} $$

$$ D = \{ x \in \mathbb{N} | |x| = x \} = \mathbb{N} $$

$$ C - D = \varnothing $$

$$ \therefore contra-exemplos = \varnothing $$