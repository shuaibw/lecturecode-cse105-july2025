# Lecture 3: Resizing Arrays

Demonstrates the implementation of dynamic arrays with automatic resizing in both C and Java.

## Files

- **`SimpleArrayList.c`** - C implementation of a resizing array
- **`SimpleArrayList.java`** - Java implementation of a resizing array

## Key Concepts

- **Dynamic Resizing**: Arrays grow when full and shrink when underutilized
- **Growth Strategy**: Doubles capacity when size reaches capacity (O(n) amortized)
- **Shrinking Strategy**: Halves capacity when size drops to 25% of capacity
- **Trade-off**: Memory efficiency vs. fewer reallocations

## Operations

- `initialize(capacity)` - Create array with initial capacity
- `insertItem(value)` - Add element at end (resize if needed)
- `removeItem()` - Remove from end (shrink if needed)
- `printArray()` - Display all elements

## Running

```bash
# C version
gcc SimpleArrayList.c -o SimpleArrayList && ./SimpleArrayList 100

# Java version
javac SimpleArrayList.java && java SimpleArrayList 100
```
