# Lecture 1: Asymptotic Analysis

This folder demonstrates the practical difference between different algorithmic complexities.

## Files

- **`compare.c`** - Compares quadratic O(n²) vs linear O(n) algorithms for finding duplicates in a sorted array
- **`dup.c`** - Similar duplicate-finding comparison with timing measurements
- **`plot.ipynb`** - Jupyter notebook for visualizing performance differences

## Key Concepts

Shows why big-O notation matters by benchmarking:
- **Quadratic approach**: Nested loops checking every pair → O(n²)
- **Linear approach**: Single pass on sorted array → O(n)

## Running

```bash
gcc compare.c -o compare && ./compare
gcc dup.c -o dup && ./dup
```
