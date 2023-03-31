# Exercicio 1

## 1 - calcular saida:

-  ### a xor (not b)

- ### (a or b) and b

- ### a xor (a xor b)

### A) a = 1 e b = 0

- 1 xor (not 1) = 1 xor 1 = 1

- (1 or 0) and 0 = 0

- 1 xor (1 xor 0) = 1 xor 1 = 0

### B) a = 0 e b = 1

- 0 xor (not 1) = 0 xor 0 = 0

- (0 or 1) and 1 = 1 and 1 = 1

- 0 xor (0 xor 1) = 0 xor 1 = 1

## 2 - simplificar:

- ### (not a) nor (not b)

 a | b | not a | not b | not a nor not b
---|---|-------|-------|-----------------
 0 | 0 | 1     | 1     | 0
 0 | 1 | 1     | 0     | 0
 1 | 0 | 0     | 1     | 0
 1 | 1 | 0     | 0     | 1

(not a) nor (not b) === a and b

## 3 - simplificar:

- ### (a nand (a nand b)) nand ((a nand b) nand b)

 a | b | a nand b | a nand (a nand b) | (a nand b) nand b | (a nand (a nand b)) nand ((a nand b) nand b)
---|---|----------|-------------------|-------------------|-------------------------------------------
 0 | 0 | 1        | 1                 | 1                 | 0
 0 | 1 | 1        | 1                 | 0                 | 1
 1 | 0 | 1        | 0                 | 1                 | 1
 1 | 1 | 0        | 1                 | 1                 | 0

(a nand (a nand b)) nand ((a nand b) nand b) === a xor b

## 4 - determinar saida apos quatro pulsos no circuito

entrada -(0)-> flipflop1 -(0)-> (saida1 (0), not -(1)-> flipflop2 --(0)> saida2 (0))

obs: saida1 e saida2 sao as saidas numeradas da direita para a esquerda na figura

- pulso 1:

-(1...0)-> flipflop1 -(1)->

-(0)-> flipflop2 -(0)->

saida1 = 1; saida2 = 0

- pulso 2:

-(1...0)-> flipflop1 -(0)->

-(1)-> flipflop2 -(1)->

saida1 = 0; saida2 = 1

- pulso 3:

-(1...0)-> flipflop1 -(1)->

(0)-> flipflop2 -(1)->

saida1 = 1; saida2 = 1

- pulso 4:

-(1...0)-> flipflop1 -(0)->

-(1)-> flipflop2 -(0)->

saida1 = 0; saida2 = 0

## 5 - determinar em quais pulsos sera emitido um 1 pela saida B e C e em qual saida sera emitido um 1 no quarto pulso do relogio

relogio -> circuito de flip flops -> (saida1, saida2)

A = saida1 and not saida2

B = not saida1 and saida2

C = saida1 and saida2

- pulsos 0 mod 4: saida1 = 0; saida2 = 0

- pulsos 1 mod 4: saida1 = 1; saida2 = 0

- pulsos 2 mod 4: saida1 = 0; saida2 = 1

- pulsos 3 mod 4: saida1 = 1; saida2 = 1

 saidas | 0 mod 4 | 1 mod 4 | 2 mod 4 | 3 mod 4
--------|---------|---------|---------|--------
 A      | 0       | 1       | 0       | 0
 B      | 0       | 0       | 1       | 0
 C      | 0       | 0       | 0       | 1

A envia 1 nos pulsos 1 mod 4

B envia 1 nos pulsos 2 mod 4

C envia 1 no pulso 3 mod 4

todas as saidas enviam 0 em pulsos 0 mod 4

## 6 - seguir as instrucoes e determinar o estado final da memoria

 endereco | conteudo | mov 03 00 | mov 01 02 | mov 01 03
----------|----------|-----------|-----------|-----------
 00       | AB       | D6        | D6        | D6
 01       | 53       | 53        | NULL      | NULL
 02       | D3       | D3        | 53        | 53
 03       | D6       | NULL      | NULL      | NULL
 04       | 02       | 02        | 02        | 02

## 7 - determinar numero de enderecos com dois e quatro digitos hexadecimais

2 digitos: 16² enderecos

4 digitos: 16⁴ enderecos

## 8 - determinar quantas unidades de 1024 * 1024 * 3 bytes cabem em 256MB

256MB = 256 * 1024 * 1024 bytes

(256 * 1024 * 1024) / (1024 * 1024 * 3)

256 // 3 = 85 (divisao inteira)


## 9 - determinar 1024 * 768 * 8 bytes

1024 * 768 * 8 = 6291456 bytes

## 10 - determinar tamanho de 400 * 3500 caracteres ascii e unicode

ascii = 400 * 3500 * 1 byte = 1400000 bytes

unicode = 400 * 3500 * 2 bytes = 2800000 bytes

## 11 - determinar os 6 menores numeros  cuja representacao binara tem um unico bit 1

- 01: 000001
- 02: 000010
- 04: 000100
- 08: 001000
- 16: 010000
- 32: 100000

## 12 - determinar resultados em complemento de 2 com 5 bits

### A) 5 + 1

6 = 00110

### B) 5 - 1

4 = 00100

### C) 12 - 5

7 = 00111

### D) 8 - 7

1 = 00001

### E) 12 + 5

17 = 01001

### F) 5 - 11

-6 = 11010

## 13 - converter numero de ponto flutuante para decimal

### A) 11.11

2 + 1 + 0.5 + 0.25 = 3.75

### B) 100.0101

4 + 0.25 + 0.0625 = 4.3125 

### C) 0.1101

0.5 + 0.25 + 0.0625 = 0.8125

### D) 1.0

1

### E) 10.01

2 + 0.25 = 2.25

## 14

### A) Dado os bits A e B e o transporte C, determine um circuito que calcule o resultado A + B + C

 A | B | S | C
---|---|---|-------
 0 | 0 | 0 | 0
 0 | 1 | 1 | 0
 1 | 0 | 1 | 0
 1 | 1 | 0 | 1

S = A xor B
C = A and B

A + B + C = (A + B) + C

S = (A xor B) xor C

### B) dado os bits A, B e C, determine um circuito que calcule C' de A + B + C

 A | B | C | C'
---|---|---|----
 0 | 0 | 0 | 0
 0 | 0 | 1 | 0
 0 | 1 | 0 | 0
 0 | 1 | 1 | 1
 1 | 0 | 0 | 0
 1 | 0 | 1 | 1
 1 | 1 | 0 | 1
 1 | 1 | 1 | 1

C' = ((A xor B) and C) or (A and B)

### C) criar circuito para somar dois numeros de 4 bits


(a, b, c) -> full adder -> (
      s  := (a xor b) xor c, 
      c' := ((a xor b) and c) or (a and b)
)

A = 2³ * a3 + 2² * a2 + 2¹ * a1 + 2⁰ * a0

B = 2³ * b3 + 2² * b2 + 2¹ * b1 + 2⁰ * b0

(a0, b0, 0 ) -> full adder -> (s0, c1)

(a1, b1, c1) -> full adder -> (s1, c2)

(a2, b2, c2) -> full adder -> (s2, c3)

(a3, b3, c3) -> full adder -> (s3, c4)

S = 2³ * s3 + 2² * s2 + 2¹ * s1 + 2⁰ * s0

## 15 - espressar valores em binario

### A) 5 + 3 / 4

3 * 2⁻² = 0.75 

1 * 2⁻¹ = 0.5

1 * 2⁻² = 0.25

1 * 2⁻¹ + 1 * 2⁻² = 0.75

5 = 101

5 + 3 / 4 = 101.11

### B) 15 + 15 / 16


2⁻¹ + 2⁻² + 2⁻³ + 2⁻⁴ = 1/2 + 1/4 + 1/8 + 1/16 = (8 + 4 + 2 + 1) / 16 = 15 /16 = .1111

15 = 1111

15 + 15/16 = 1111.1111

### C) 5 + 3 / 8

2⁻² + 2⁻³  = 1/4 + 1/8 = (2 + 1) / 8 = 3/8 = .011

5 = 101

5 + 3 / 8 = 101.011


### D) 1 + 1 / 4

1 / 4 = 2⁻² = .01

1 = 1

1 + 1 / 4 = 1.01

### E) 6 + 5 / 8

2⁻¹ + 2⁻³ = 1/2 + 1/8 = (4 + 1) / 8 = 5/8 = .101

6 = 110

6 + 5 / 8 = 110.101