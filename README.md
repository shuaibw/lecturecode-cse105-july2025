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

### [Lecture 4: Linked Lists](./lec4_linkedlist)
**Singly Linked List Implementation**
- C++ and Java implementations
- Node-based data structure
- Dynamic memory allocation
- Insert, delete, and traversal operations

### [Lecture 5: Doubly Linked Lists](./lec5_doublylinkedlist)
**Doubly Linked List Implementation**
- C++ and Java implementations
- Bidirectional traversal
- Previous and next pointers
- Enhanced deletion operations

### [Lecture 6: Stack](./lec6_stack)
**Stack Data Structure & Applications**
- Array and linked list implementations
- LIFO principle demonstration
- Parenthesis matching, postfix evaluation, infix to postfix conversion
- C++ and Java implementations

### [Lecture 7: Queue](./lec7_queue)
**Queue Data Structure Implementation**
- Circular array and linked list implementations
- FIFO principle demonstration
- Efficient space utilization with circular arrays
- C++ and Java implementations

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