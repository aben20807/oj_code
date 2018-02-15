# Insertion sort

## Stability
+ stable

## Pseudo code

### Insertion sort

```cpp
INSERTION_SORT(A)
    for i = 2 to A.size
        key = A[i]
        j = i - 1
        while j > 0 && A[j] > key
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key
```
