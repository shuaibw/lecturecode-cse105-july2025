/*
 * ============================================================================
 * STACK OPERATION TIME COMPLEXITY (Linked List Implementation)
 * ============================================================================
 *
 * Operation                    | Time Complexity | Notes
 * ------------------------------|-----------------|------------------------
 * Push                         | O(1)            | Insert at front
 * Pop                          | O(1)            | Remove from front
 * Peek/Top                     | O(1)            | View front element
 * isEmpty                      | O(1)            | Check if head is null
 * Size                         | O(1)            | Track with counter
 *
 * KEY INSIGHTS:
 * - LIFO (Last In, First Out) data structure
 * - No capacity limit (grows dynamically)
 * - All operations at the head of the list
 * - No overflow possible (only limited by memory)
 * - More memory per element (due to references)
 * ============================================================================
 */

class Node {
    int data;
    Node next;
    
    Node(int val) {
        data = val;
        next = null;
    }
}

class LinkedListStack {
    private Node head;
    private int count;

    public LinkedListStack() {
        head = null;
        count = 0;
    }

    // Check if stack is empty
    public boolean isEmpty() {
        return head == null;
    }

    // Push element onto stack (insert at front)
    public void push(int val) {
        Node newNode = new Node(val);
        newNode.next = head;
        head = newNode;
        count++;
    }

    // Pop element from stack (remove from front)
    public int pop() {
        if (isEmpty()) {
            System.out.println("Error: Stack underflow!");
            return -1;
        }
        
        int val = head.data;
        head = head.next;
        count--;
        return val;
    }

    // Peek at top element without removing
    public int peek() {
        if (isEmpty()) {
            System.out.println("Error: Stack is empty!");
            return -1;
        }
        return head.data;
    }

    // Get current size
    public int size() {
        return count;
    }

    // Print stack contents
    public void print() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return;
        }
        System.out.print("Stack (top to bottom): ");
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        System.out.println("=== Linked List-Based Stack Demo ===\n");

        LinkedListStack stack = new LinkedListStack();

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
        System.out.println("\n4. Push 60 and 70:");
        stack.push(60);
        stack.push(70);
        stack.print();

        // Test 5: Stack info
        System.out.println("\n5. Stack info:");
        System.out.println("   Is empty? " + (stack.isEmpty() ? "Yes" : "No"));
        System.out.println("   Size: " + stack.size());

        // Test 6: Pop all elements
        System.out.println("\n6. Pop all elements:");
        while (!stack.isEmpty()) {
            System.out.println("   Popped: " + stack.pop());
        }
        stack.print();

        // Test 7: Error handling
        System.out.println("\n7. Try to pop from empty stack:");
        stack.pop();
        stack.peek();

        // Test 8: Push after emptying
        System.out.println("\n8. Push 100 after emptying:");
        stack.push(100);
        stack.print();

        System.out.println("\nDone!");
    }
}
