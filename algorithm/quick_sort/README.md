# Quick sort

## Stability
+ unstable (Typical)

## Pseudo code

### Partition

```cpp
PARTATION(A, p, r)
    x = A[r]
    i = p - 1
    for j = p to r - 1
        if A[j] <= x
            i += 1
            SWAP(A[i], A[j])
    SWAP(A[i+1], A[r])
    return i + 1
```

### Quick sort

```cpp
QUICK_SORT(A, p, r)
    if p < r
        q = PARTATION(A, p, r)
        QUICK_SORT(A, p, q-1)
        QUICK_SORT(A, q+1, r)
```
