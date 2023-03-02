# Propositional Logic

## Definitions

- **Proposition**: A proposition is a statement that is either true or false.

## Principles of Classical Logic

- **Law of Identity**: A proposition is true if and only if it is true.

- **Law of Non-contradiction**: A proposition is true if and only if it is false.

- **Law of Excluded Middle**: A proposition is true or false.

## Connectives

- **Conjunction**: And (∨)

- **Disjunction**: Or (∧)

- **Implication**: If... then (⇒)

- **Biconditional**: If and only if (⇔)

- **Negation**: Not (¬)

## Truth Tables

- **Conjunction**: And (∨)

| p | q | p ∧ q |
|---|---|-------|
| T | T | T     |
| T | F | F     |
| F | T | F     |
| F | F | F     |

- **Disjunction**: Or (∧)

| p | q | p ∨ q |
|---|---|-------|
| T | T | T     |
| T | F | T     |
| F | T | T     |
| F | F | F     |

- **Implication**: If... then (⇒)

| p | q | p ⇒ q |
|---|---|-------|
| T | T | T     |
| T | F | F     |
| F | T | T     |
| F | F | T     |

- **Biconditional**: If and only if (⇔)

| p | q | p ⇔ q |
|---|---|-------|
| T | T | T     |
| T | F | F     |
| F | T | F     |
| F | F | T     |

- **Negation**: Not (¬)

| p | ¬p |
|---|----|
| T | F  |
| F | T  |

## Equivalences

- **De Morgan's Laws**

  - ¬(p ∧ q) ⇔ ¬p ∨ ¬q

  - ¬(p ∨ q) ⇔ ¬p ∧ ¬q

- **Double Negation**

    - ¬¬p ⇔ p


# Derived Connectives

- **Nand**: Not and (⊼)

- **Nor**: Not or (⊽)

- **Xnor**: Not either... or not both (⊻)

- **Xor**: Either... or not both (⊕)

## Truth Tables

- **Nand**: Not and (⊼)

| p | q | p ⊼ q |
|---|---|-------|
| T | T | F     |
| T | F | T     |
| F | T | T     |
| F | F | T     |

- **Nor**: Not or (⊽)

| p | q | p ⊽ q |
|---|---|-------|
| T | T | F     |
| T | F | F     |
| F | T | F     |
| F | F | T     |

- **Xnor**: Not either... or not both (⊻)

| p | q | p ⊻ q |
|---|---|-------|
| T | T | T     |
| T | F | F     |
| F | T | F     |
| F | F | T     |

- **Xor**: Either... or not both (⊕)

| p | q | p ⊕ q |
|---|---|-------|
| T | T | F     |
| T | F | T     |
| F | T | T     |
| F | F | F     |