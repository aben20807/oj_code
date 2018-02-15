# Bubble sort

## Stability
+ stable

## Pseudo code

### Bubble sort

```cpp
BUBBLE_SORT(A)
    for i = 0 to A.size - 1
        for j = 0 to A.size - i - 1
            if A[j] > A[j + 1]
                SWAP(A[j], A[j+1])
```
