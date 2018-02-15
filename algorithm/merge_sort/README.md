# Merge sort

## Description
+ Do not use A[0]

## Stability
+ stable

## Pseudo code

### Merge

```cpp
MERGE(A, p, q, r)
    n1 = q - p + 1
    n2 = r - q
    new two arrays: L[1..n1+1], R[1..n2+1]
    for i = 1 to n1
        L[i] = A[p + i - 1]
    for i = 1 to n2
        R[i] = A[q + i]
    L[n1+1] = INFINITY
    R[n2+1] = INFINITY
    i = 1
    j = 1
    for k = p to r
        if L[i] <= R[j]
            A[k] = L[i]
            i += 1
        else
            A[k] = R[j]
            j += 1
```

### Merge sort

```cpp
MERGE_SORT(A, p, r)
    if p < r
        q = ⌊(p + r)/2⌋
        MERGE_SORT(A, p, q)
        MERGE_SORT(A, q+1, r)
        MERGE_SORT(A, p, q, r)
```
