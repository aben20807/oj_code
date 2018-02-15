# Shell sort

## Description
+ Shell sort is a generalization of insertion sort.
+ Use A108870 integer sequence to reduce worst-case time complexity.

## Stability
+ unstable

## Pseudo code

### Shell sort

```cpp
SHELL_SORT(A)
    gaps = [] // a integer sequence
    foreach(gap in gaps)
        for i = gap to n-1
            x = A[i]
            j = i
            while j >= gap && A[j - gap] > x
                SWAP(A[j], A[j-gap])
                j -= gap
```
