#include <iostream>

using namespace std;

/*
 * ============================================================================
 * STACK OPERATION TIME COMPLEXITY (Array Implementation)
 * ============================================================================
 *
 * Operation                    | Time Complexity | Notes
 * ------------------------------|-----------------|------------------------
 * Push                         | O(1)            | Fixed capacity
 * Pop                          | O(1)            | Remove from top
 * Peek/Top                     | O(1)            | View top element
 * isEmpty                      | O(1)            | Check if empty
 * isFull                       | O(1)            | Check if full
 * Size                         | O(1)            | Current element count
 *
 * KEY INSIGHTS:
 * - LIFO (Last In, First Out) data structure
 * - All operations at one end (top)
 * - Fixed capacity with overflow detection
 * - You can use dynamic resizing to avoid overflow (not implemented here)
 * ============================================================================
 */

class ArrayStack {
    int* data;
    int top;   // Index of next available position
    int capacity; // Initial capacity

public:
    ArrayStack(int capacity = 10) {
        this->capacity = capacity;
        data = new int[capacity];
        top = 0;  // Empty stack
    }

    ~ArrayStack() {
        delete[] data;
    }

    // Check if stack is full
    bool isFull() {
        return top >= capacity;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == 0;
    }

    // Push element onto stack
    void push(int val) {
        if (isFull()) {
            cout << "Error: Stack overflow!" << endl;
            return;
        }
        data[top++] = val;
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack underflow!" << endl;
            return -1;
        }
        return data[--top];
    }

    // Peek at top element without removing
    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1;
        }
        return data[top - 1];
    }

    // Get current size
    int size() {
        return top;
    }

    // Print stack contents
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Array-Based Stack Demo ===" << endl << endl;

    ArrayStack stack(5);

    // Test 1: Push elements
    cout << "1. Pushing elements: 10, 20, 30, 40, 50" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.print();
    cout << "   Size: " << stack.size() << endl;

    // Test 2: Peek
    cout << "\n2. Peek at top element:" << endl;
    cout << "   Top: " << stack.peek() << endl;

    // Test 3: Pop elements
    cout << "\n3. Pop 2 elements:" << endl;
    cout << "   Popped: " << stack.pop() << endl;
    cout << "   Popped: " << stack.pop() << endl;
    stack.print();

    // Test 4: Push more
    cout << "\n4. Push 60:" << endl;
    stack.push(60);
    stack.print();

    // Test 5: Stack overflow
    cout << "\n5. Try to push 70 (should overflow):" << endl;
    stack.push(70);
    stack.print();

    // Test 6: Stack info
    cout << "\n6. Stack info:" << endl;
    cout << "   Is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "   Is full? " << (stack.isFull() ? "Yes" : "No") << endl;
    cout << "   Size: " << stack.size() << endl;

    // Test 7: Pop all elements
    cout << "\n7. Pop all elements:" << endl;
    while (!stack.isEmpty()) {
        cout << "   Popped: " << stack.pop() << endl;
    }
    stack.print();

    // Test 8: Error handling
    cout << "\n8. Try to pop from empty stack:" << endl;
    stack.pop();
    stack.peek();

    cout << "\nDone!" << endl;

    return 0;
}
