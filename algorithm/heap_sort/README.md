# Heap sort

## Description
+ Do not use A[0]

## Stability
+ unstable

## Pseudo code

### Max heapify

```cpp
MAX_HEAPIFY(A, i)
    l = LEFT(i)
    r = RIGHT(i)
    if l <= A.size && A[l] > A[i]
        largest = l
    else
        largest = i
    if r <= A.size && A[r] > A[largest]
        largest = r
    if largest != i
        SWAP(A[i], A[largest])
        MAX_HEAPIFY(A, largest)
```

### Build heap

```cpp
BUILD_MAX_HEAP(A)
    for i = ⌊A.size/2⌋ downto 1
        MAX_HEAPIFY(A, i)
```

### Heap sort

```cpp
HEAP_SORT(A)
    BUILD_MAX_HEAP(A)
    for i = A.size downto 2
        SWAP(A[1], A[i])
        A.size -= 1
        MAX_HEAPIFY(A, 1)
```
