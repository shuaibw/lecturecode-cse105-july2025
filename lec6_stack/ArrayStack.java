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
 * ============================================================================
 */

class ArrayStack {
    private int[] data;
    private int top;          // Index of next available position
    private int capacity;

    public ArrayStack(int capacity) {
        this.capacity = capacity;
        data = new int[capacity];
        top = 0;  // Empty stack
    }

    // Check if stack is full
    public boolean isFull() {
        return top >= capacity;
    }

    // Check if stack is empty
    public boolean isEmpty() {
        return top == 0;
    }

    // Push element onto stack
    public void push(int val) {
        if (isFull()) {
            System.out.println("Error: Stack overflow!");
            return;
        }
        data[top++] = val;
    }

    // Pop element from stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Error: Stack underflow!");
            return -1;
        }
        return data[--top];
    }

    // Peek at top element without removing
    public int peek() {
        if (isEmpty()) {
            System.out.println("Error: Stack is empty!");
            return -1;
        }
        return data[top - 1];
    }

    // Get current size
    public int size() {
        return top;
    }

    // Print stack contents
    public void print() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return;
        }
        System.out.print("Stack (top to bottom): ");
        for (int i = top - 1; i >= 0; i--) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        System.out.println("=== Array-Based Stack Demo ===\n");

        ArrayStack stack = new ArrayStack(5);

        // Test 1: Push elements
        System.out.println("1. Pushing elements: 10, 20, 30, 40, 50");
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.print();
        System.out.println("   Size: " + stack.size());

        // Test 2: Peek
        System.out.println("\n2. Peek at top element:");
        System.out.println("   Top: " + stack.peek());

        // Test 3: Pop elements
        System.out.println("\n3. Pop 2 elements:");
        System.out.println("   Popped: " + stack.pop());
        System.out.println("   Popped: " + stack.pop());
        stack.print();

        // Test 4: Push more
        System.out.println("\n4. Push 60:");
        stack.push(60);
        stack.print();

        // Test 5: Stack overflow
        System.out.println("\n5. Try to push 70 (should overflow):");
        stack.push(70);
        stack.print();

        // Test 6: Stack info
        System.out.println("\n6. Stack info:");
        System.out.println("   Is empty? " + (stack.isEmpty() ? "Yes" : "No"));
        System.out.println("   Is full? " + (stack.isFull() ? "Yes" : "No"));
        System.out.println("   Size: " + stack.size());

        // Test 7: Pop all elements
        System.out.println("\n7. Pop all elements:");
        while (!stack.isEmpty()) {
            System.out.println("   Popped: " + stack.pop());
        }
        stack.print();

        // Test 8: Error handling
        System.out.println("\n8. Try to pop from empty stack:");
        stack.pop();
        stack.peek();

        System.out.println("\nDone!");
    }
}
