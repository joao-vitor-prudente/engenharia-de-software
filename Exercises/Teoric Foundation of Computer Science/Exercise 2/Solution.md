# Exercício 2

## 1 - Fazer tabelas verdade e classificar proposições

- A) 

 p | r | p → (p ∨ r)
---|---|------------
 V | V | V → V = V
 V | F | V → V = V
 F | V | F → V = V
 F | F | F → F = V

**Tautologia**

- B) 

 p | q | p → (p ∧ q)
---|---|------------
 V | V | V → V = V
 V | F | V → F = F
 F | V | F → F = V
 F | F | F → F = V

**Contingência**

- C) 

 p | q | p ∧ q → p
---|---|----------
 V | V | V → V = V
 V | F | F → V = V
 F | V | F → F = V
 F | F | F → F = V

**Tautologia**

- D) 

 p | q | p → (q → p) ∧ q
---|---|------------------------
 V | V | V → (V ∧ V) = V → V = V
 V | F | V → (F ∧ F) = V → F = F
 F | V | F → (F ∧ V) = F → F = V
 F | F | F → (F ∧ F) = F → F = V

**Contingência**

- E) 

 p | q | p ↔ p ∧ (p ∨ q)
---|---|------------------------
 V | V | V ↔ (v ∧ v) = V ↔ V = V
 V | F | V ↔ (v ∧ f) = V ↔ F = F
 F | V | F ↔ (f ∧ f) = F ↔ F = V
 F | F | F ↔ (f ∧ f) = F ↔ F = V

**Contingência**

- F) 

 p | q | p ∧ (p ∧ (p ∨ q))
---|---|------------------------
 V | V | V ∧ (V ∧ V) = V ∧ V = V
 V | F | V ∧ (V ∧ V) = V ∧ V = V
 F | V | F ∧ (F ∧ V) = F ∧ F = F
 F | F | F ∧ (F ∧ F) = F ∧ F = F

**Contingência**

- G) 

 p | q | ¬ (p ∨ q) ↔ (¬ p ∧ ¬ q)
---|---|------------------------
 V | V | F ↔ (F ∧ F) = F ↔ F = V
 V | F | F ↔ (F ∧ V) = F ↔ F = V
 F | V | F ↔ (V ∧ F) = F ↔ F = V
 F | F | V ↔ (V ∧ V) = V ↔ V = V

**Tautologia**

- H) 

 p | q | (p → q) ∧ ¬ q → ¬ p
---|---|------------------------
 V | V | (V ∧ F) → F = F → F = V
 V | F | (F ∧ V) → F = F → F = V
 F | V | (V ∧ F) → V = F → F = V
 F | F | (V ∧ V) → V = V → V = V

**Tautologia**

- I) 

 p | q | ¬ (p ∧ q) ↔ ¬ p ∧ ¬ q
---|---|----------------------
 V | V | F ↔ F = V
 V | F | V ↔ F = F
 F | V | V ↔ F = F
 F | F | V ↔ V = V

**Contingência**

- J) 

 p | q | p ∨ q → p ∧ q
---|---|--------------
 V | V | V → V = V
 V | F | V → V = V
 F | V | V → V = V
 F | F | F → F = V

**Tautologia**

- K) 

 p | q | p → (p → q ∨ q)
---|---|------------------------
 V | V | V → (V → V) = V → V = V
 V | F | V → (V → F) = V → F = F
 F | V | F → (F → V) = F → V = V
 F | F | F → (F → F) = F → V = V

**Contingência**

- L) 

 p | q | (p → (p → q)) → q
---|---|------------------------
 V | V | (V → V) → V = V → V = V
 V | F | (V → F) → F = F → F = V
 F | V | (F → V) → V = V → V = V
 F | F | (F → V) → F = V → F = F

**Contingência**

- M) 

 p | q | p → (¬ p → q ∨ ¬ q)
---|---|------------------------------------------
 V | V | V → (F → V ∨ F) = V → (F → V) = V → V = V
 V | F | V → (F → F ∨ V) = V → (F → V) = V → V = V
 F | V | F → (V → V ∨ F) = F → (V → V) = F → V = V
 F | F | F → (V → F ∨ V) = F → (V → V) = F → V = V

**Tautologia**

- N) 

 p | q | (¬ p ∧ q) → ¬ p
---|---|------------------------
 V | V | (F ∧ V) → F = F → F = V
 V | F | (F ∧ F) → F = F → F = V
 F | V | (V ∧ V) → V = V → V = V
 F | F | (V ∧ F) → V = V → V = V

**Tautologia**

- O) 

 p | q | ¬ (p → ( ¬ p → (q ∨ ¬ q)))
---|---|--------------------------------
 V | V | ¬ (V → (F → V)) = ¬ (V → V) = F
 V | F | ¬ (V → (F → V)) = ¬ (V → V) = F
 F | V | ¬ (F → (V → V)) = ¬ (F → V) = F
 F | F | ¬ (F → (V → V)) = ¬ (F → V) = F

**Contradição**

- P) 

 p | q | r | (p → q ∨ r) ∧ q → (p → r)
---|---|---|--------------------------------------------------------------------------
 V | V | V | ((V → V ∨ V) ∧ V) → (V → V) = ((V → V) ∧ V) → V = (V ∧ V) → V = V → V = V
 V | V | F | ((V → V ∨ F) ∧ V) → (V → F) = ((V → V) ∧ V) → F = (V ∧ V) → F = V → F = F
 V | F | V | ((V → F ∨ V) ∧ F) → (V → V) = ((V → V) ∧ F) → V = (V ∧ F) → V = F → V = V
 V | F | F | ((V → F ∨ F) ∧ F) → (V → F) = ((V → F) ∧ F) → F = (F ∧ F) → F = F → F = V
 F | V | V | ((F → V ∨ V) ∧ V) → (F → V) = ((F → V) ∧ V) → V = (V ∧ V) → V = V → V = V
 F | V | F | ((F → V ∨ F) ∧ V) → (F → F) = ((F → V) ∧ V) → V = (V ∧ V) → V = V → V = V
 F | F | V | ((F → F ∨ V) ∧ F) → (F → V) = ((F → V) ∧ F) → V = (V ∧ F) → V = F → V = V
 F | F | F | ((F → F ∨ F) ∧ F) → (F → F) = ((F → F) ∧ F) → V = (V ∧ F) → V = F → V = V

**Contingência**

- Q) 

 p | q | p ∧ q ↔ (p ∨ q ↔ (p → ¬ q))
---|---|--------------------------------------------
 V | V | V ↔ (V ↔ (V → F)) = V ↔ (V ↔ F) = V ↔ F = F
 V | F | F ↔ (V ↔ (V → V)) = F ↔ (V ↔ V) = F ↔ V = F
 F | V | F ↔ (V ↔ (F → F)) = F ↔ (V ↔ V) = F ↔ V = F
 F | F | F ↔ (F ↔ (F → V)) = F ↔ (F ↔ V) = F ↔ F = V

**Contingência**

- R) 

 p | q | p → (p → q ∧ ¬ q)
---|---|------------------------
 V | V | V → (V → F) = V → F = F
 V | F | V → (V → F) = V → F = F
 F | V | F → (F → F) = F → V = V
 F | F | F → (F → F) = F → V = V

**Contingência**

- S) 

 p | q | r | (p ∧ q) ∨ (p ∧ r) ↔ p ∧ (q ∧ r)
---|---|---|--------------------------------------------------------------------
 V | V | V | ((V ∧ V) ∨ (V ∧ V)) ↔ (V ∧ (V ∧ V)) = (V ∨ V) ↔ (V ∧ V) = V ↔ V = V
 V | V | F | ((V ∧ V) ∨ (V ∧ F)) ↔ (V ∧ (V ∧ F)) = (V ∨ F) ↔ (V ∧ F) = V ↔ F = F
 V | F | V | ((V ∧ F) ∨ (V ∧ V)) ↔ (V ∧ (F ∧ V)) = (F ∨ V) ↔ (V ∧ F) = V ↔ F = F
 V | F | F | ((V ∧ F) ∨ (V ∧ F)) ↔ (V ∧ (F ∧ F)) = (F ∨ F) ↔ (V ∧ F) = F ↔ F = V
 F | V | V | ((F ∧ V) ∨ (F ∧ V)) ↔ (F ∧ (V ∧ V)) = (F ∨ F) ↔ (F ∧ V) = F ↔ F = V
 F | V | F | ((F ∧ V) ∨ (F ∧ F)) ↔ (F ∧ (V ∧ F)) = (F ∨ F) ↔ (F ∧ F) = F ↔ F = V
 F | F | V | ((F ∧ F) ∨ (F ∧ V)) ↔ (F ∧ (F ∧ V)) = (F ∨ F) ↔ (F ∧ F) = F ↔ F = V
 F | F | F | ((F ∧ F) ∨ (F ∧ F)) ↔ (F ∧ (F ∧ F)) = (F ∨ F) ↔ (F ∧ F) = F ↔ F = V

**Contingência**

- T)

 p | q | r | (p → q) ∧ (q → r) → (p → r)
---|---|---|--------------------------------------------------------
 V | V | V | ((V → V) ∧ (V → V)) → (V → V) = (V ∧ V) → V = V → V = V
 V | V | F | ((V → V) ∧ (V → F)) → (V → F) = (V ∧ F) → F = F → F = V
 V | F | V | ((V → F) ∧ (F → V)) → (V → V) = (F ∧ V) → V = F → V = V
 V | F | F | ((V → F) ∧ (F → F)) → (V → F) = (F ∧ V) → F = F → F = V
 F | V | V | ((F → V) ∧ (V → V)) → (F → V) = (V ∧ V) → V = V → V = V
 F | V | F | ((F → V) ∧ (V → F)) → (F → F) = (V ∧ F) → V = F → V = V
 F | F | V | ((F → F) ∧ (F → V)) → (F → V) = (V ∧ V) → V = V → V = V
 F | F | F | ((F → F) ∧ (F → F)) → (F → F) = (V ∧ V) → V = V → V = V

**Tautologia**

## 2 - Demonstrar tautologias sem tabela verdade

- A) 

X = (p ∧ q) → p

Prova por contradição:

Assumindo X = F

X = F → (p ∧ q = V) ∧ (p = F)

p = F → (p ∧ q = F) → (p ∧ q = V) ∧ (p ∧ q = F) → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- B) 

X = p → (p ∨ q)

Prova por contradição:

Assumindo X = F

X = F → (p = V) ∧ (p ∨ q = F)

(p = V) → (p ∨ q = V) → [(p ∨ q = F) ∧ (p ∨ q = v)]

[(p ∨ q = F) ∧ (p ∨ q = v)] → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- C) 

X = ¬ p → (p → q)

Prova por contradição:

Assumindo X = F

(X = F) → [(¬ p = V) ∧ (p = V) ∧ (q = F)] → (¬ p = p) 

(¬ p = p) → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- D) 

X = (p ∧ q) → (p → q)

Prova por contradição:

Assumindo X = F

(X = F) → [(p ∧ q = V) ∧ (p = V) ∧ (q = F)]

(p = V ∧ q = F) → (p ∧ q = F) → [(p ∧ q = V) ∧ (p ∧ q = F)]

[(p ∧ q = V) ∧ (p ∧ q = F)] → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- E) 

X = ¬ (p → q) → p

Prova por contradição:

Assumindo X = F

(X = F) → [(p → q = F) ∧ (p = F)]

(p → q = F) → (p = V ∧ q = F) → (p = V ∧ p = F)

(p = V ∧ p = F) → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- F) 

X = ¬ (p → q) → ¬ q

Prova por contradição:

Assumindo X = F

(X = F) → [(p → q = F) ∧ (q = V)]

(p → q = F) → (p = V ∧ q = F) → (q = V ∧ q = F)

(q = V ∧ q = F) → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- G) 

X = [¬ p ∧ (p ∨ q)] → q

Prova por contradição:

Assumindo X = F

(X = F) → {[¬ p ∧ (p ∨ q)] = V ∧ q = F}

{[¬ p ∧ (p ∨ q)] = V} → (p = F ∧ q = V) → (q = F ∧ q = V)

(q = F ∧ q = V) → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- H) 

X = [(p → q) ∧ (q → r)] → (p → r)

Prova por contradição:

Assumindo X = F

(X = F) → {[(p → q) ∧ (q → r)] = V ∧ (p → r) = F}

{[(p → q) ∧ (q → r)] = V} → [(p → q = V) ∧ (q → r = V)]

(p → r = F) → (p = V ∧ r = F)

[(p = V) ∧ (p → q = V)] → (p = V ∧ q = V)

[(q = V) ∧ (q → r = V)] → (q = V ∧ r = V)

(r = F ∧ r = V) → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- I) 

X = [p ∧ (p → q)] → q

Prova por contradição:

Assumindo X = F

(X = F) → {[p ∧ (p → q)] = V ∧ q = F}

{[p ∧ (p → q)] = V} → [(p = V) ∧ (p → q = V)]

(p = V ∧ q = F) → (p → q = F) → [(p → q = F) ∧ (p → q = V)]

[(p → q = F) ∧ (p → q = V)] → ∃ a | a = V ∧ a = F (Impossível)

∴ X = V

**Tautologia**

- J) 

X = [(p ∨ q) ∧ (q → r)] → r

Assumindo X = F

(X = F) → {[(p ∨ q) ∧ (q → r)] = V ∧ r = F}

{[(p ∨ q) ∧ (q → r)] = V} → [(p ∨ q = V) ∧ q → r = V]

[(r = F) ∧ (q → r = V)] → (q = F)

[(q = F) ∧ (p ∨ q = V)] → (p = V)

p = V; q = F; r = F → {[(V ∨ F) ∧ (F → F) ] → F} → (V ∧ V → F)

(V ∧ V → F) → (V → F = F)

∴ X ∈ {V, F}

**Contingência**

## 3 - Demonstrar equivalência lógica entre proposições

- A) 

X = p ↔ q ∧ (p ∧ q)

Y = (¬ p ∧ ¬ q)

 p | q | X ↔ Y = (p ↔ q ∧ (p ∧ q)) ↔ (¬ p ∧ ¬ q)
---|---|------------------------------------------------------
 V | V | (V ↔ V) ↔ F = V ↔ F = F
 V | F | (V ↔ F) ↔ F = F ↔ F = V
 F | V | (V ↔ F) ↔ F = F ↔ F = F
 F | F | (F ↔ F) ↔ V = V ↔ V = V

**Não equivalentes**

- B) 

X = ¬ (p ↔ q)

Y = p ↔ ¬ q

 p | q | X ↔ Y = (¬ (p ↔ q)) ↔ (p ↔ ¬ q)
---|---|----------------------------------
 V | V | F ↔ F = V 
 V | F | V ↔ V = V
 F | V | V ↔ V = V
 F | F | F ↔ F = V

**Equivalentes**

- C) 

X = p → q

Y = ¬ q → ¬ p

 p | q | X ↔ Y = (p → q) ↔ (¬ q → ¬ p)
---|---|--------------------------------
 V | V | V ↔ V = V
 V | F | F ↔ V = F
 F | V | V ↔ F = F
 F | F | V ↔ V = V

**Não equivalentes**

- D) 

X = ¬ p ↔ q

Y = p ↔ ¬ q

 p | q | X ↔ Y = (¬ p ↔ q) ↔ (p ↔ ¬ q)
---|---|--------------------------------
 V | V | F ↔ F = V
 V | F | V ↔ V = V
 F | V | V ↔ V = V
 F | F | F ↔ F = V

**Equivalentes**

- E) 

X = ¬ (p ⊕ q)

Y = p ↔ q

 p | q | X ↔ Y = [¬ (p ⊕ q)] ↔ (p ↔ q)
---|---|--------------------------------
 V | V | V ↔ V = V
 V | F | F ↔ F = V
 F | V | F ↔ F = V
 F | F | V ↔ V = V


**Equivalentes**

- F) 

X = ¬ (p ↔ q)

Y = ¬ p ↔ q

 p | q | X ↔ Y = [¬ (p ↔ q)] ↔ (¬ p ↔ q)
---|---|----------------------------------
 V | V | F ↔ F = V
 V | F | V ↔ V = V
 F | V | V ↔ V = V
 F | F | F ↔ F = V

**Equivalentes**

- G) 

X = (p → q) ∧ (p → r)

Y = p → (q ∧ r)

 p | q | r | X ↔ Y = [(p → q) ∧ (p → r)] ↔ [p → (q ∧ r)]
---|---|---|----------------------------------------------
 V | V | V | (V ∧ V) ↔ (V → V) = V ↔ V = V
 V | V | F | (V ∧ F) ↔ (V → F) = F ↔ F = V
 V | F | V | (F ∧ V) ↔ (V → F) = F ↔ F = V
 V | F | F | (F ∧ F) ↔ (V → F) = F ↔ F = V
 F | V | V | (V ∧ V) ↔ (F → F) = V ↔ V = V
 F | V | F | (V ∧ V) ↔ (F → F) = V ↔ V = V
 F | F | V | (V ∧ V) ↔ (F → F) = V ↔ V = V
 F | F | F | (V ∧ V) ↔ (F → F) = V ↔ V = V

**Equivalentes**

- H) 

X = (p → r) ∧ (q → r)

Y = (p ∨ q) → r

 p | q | r | X ↔ Y = [(p → r) ∧ (q → r)] ↔ [(p ∨ q) → r]
---|---|---|----------------------------------------------
 V | V | V | (V ∧ V) ↔ (V → V) = V ↔ V = V
 V | V | F | (F ∧ F) ↔ (V → F) = F ↔ F = V
 V | F | V | (V ∧ V) ↔ (V → V) = V ↔ V = V
 V | F | F | (F ∧ V) ↔ (V → F) = F ↔ F = V
 F | V | V | (V ∧ V) ↔ (V → V) = V ↔ V = V
 F | V | F | (V ∧ F) ↔ (V → F) = F ↔ F = V
 F | F | V | (V ∧ V) ↔ (F → V) = V ↔ V = V
 F | F | F | (V ∧ V) ↔ (F → F) = V ↔ V = V

**Equivalentes**

- I) 

X = (p → q) ∨ (p → r)

Y = p → (q ∨ r)

 p | q | r | X ↔ Y = [(p → q) ∨ (p → r)] ↔ [p → (q ∨ r)]
---|---|---|---------------------------------------------
 V | V | V | (V ∨ V) ↔ (V → V) = V ↔ V = V
 V | V | F | (V ∨ F) ↔ (V → V) = V ↔ V = V
 V | F | V | (F ∨ V) ↔ (V → V) = V ↔ V = V
 V | F | F | (F ∨ F) ↔ (V → F) = F ↔ F = V
 F | V | V | (V ∨ V) ↔ (F → V) = V ↔ V = V
 F | V | F | (V ∨ V) ↔ (F → V) = V ↔ V = V
 F | F | V | (V ∨ V) ↔ (F → V) = V ↔ V = V
 F | F | F | (V ∨ V) ↔ (F → F) = V ↔ V = V

**Equivalentes**

- J) 

X = (p → r) ∨ (q → r)

Y = (p ∧ q) → r

 p | q | r | X ↔ Y = [(p → r) ∨ (q → r)] ↔ [(p ∧ q) → r]
---|---|---|--------------------------------------------------
 V | V | V | (V ∨ V) ↔ (V → V) = V ↔ V = V
 V | V | F | (F ∨ F) ↔ (V → F) = F ↔ F = V
 V | F | V | (V ∨ V) ↔ (F → V) = V ↔ V = V
 V | F | F | (F ∨ V) ↔ (F → F) = V ↔ V = V
 F | V | V | (V ∨ V) ↔ (F → V) = V ↔ V = V
 F | V | F | (V ∨ F) ↔ (F → F) = V ↔ V = V
 F | F | V | (V ∨ V) ↔ (F → V) = V ↔ V = V
 F | F | F | (V ∨ V) ↔ (F → F) = V ↔ V = V

**Equivalentes**
