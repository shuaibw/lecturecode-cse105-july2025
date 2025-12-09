# CSE 105 Lecture Code - Fundamentals

Overview of introductory lectures covering language basics, algorithm analysis, and data structures.

## Lectures

### [Lecture 0: Introduction](./lec0_intro1)
**C vs Java Comparison**
- Basic syntax and structures in both languages
- Memory management differences
- String, array, and data handling

### [Lecture 1: Asymptotic Analysis](./lec1_asymptotic)
**Algorithm Efficiency in Practice**
- O(n²) vs O(n) algorithm comparison
- Performance measurements
- Finding duplicates problem with different approaches

### [Lecture 3: Resizing Arrays](./lec3_resizingArray)
**Dynamic Arrays Implementation**
- C and Java implementations side-by-side
- Automatic resizing strategies
- Growth and shrinking mechanics
- Amortized time complexity

## Quick Start

Each lecture folder has its own README with file descriptions and instructions to run the code.

```bash
# Example: Run C code from lec1
cd lec1_asymptotic
gcc compare.c -o compare && ./compare
```

For Java code, compile and run similarly using `javac` and `java` commands as specified in each lecture's README.
```bash
javac ClassName.java
java ClassName
```