# Merge sort

## Description

## Stability
+ stable

## Pseudo code

### Merge

```cpp
MERGE(A, p, q, r)
    copy A[p..q] to L[]
    copy A[q+1..r] to R[]
    i = 0
    j = 0
    k = p
    while i < L.size && j < R.size
        if L[i] <= R[j]
            A[k++] = L[i++]
        else
            A[k++] = R[j++]
    while i < L.size
        A[k++] = L[i++]
    while j < R.size
        A[k++] = R[i++]
```

### Merge sort

```cpp
MERGE_SORT(A, p, r)
    if p < r
        q = ⌊(p + r)/2⌋
        MERGE_SORT(A, p, q)
        MERGE_SORT(A, q+1, r)
        MERGE(A, p, q, r)
```
