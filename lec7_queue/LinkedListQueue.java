/*
 * ============================================================================
 * QUEUE OPERATION TIME COMPLEXITY (Linked List Implementation)
 * ============================================================================
 *
 * Operation                    | Time Complexity | Notes
 * ------------------------------|-----------------|------------------------
 * Enqueue (add to rear)        | O(1)            | Insert at tail
 * Dequeue (remove from front)  | O(1)            | Remove from head
 * Peek/Front                   | O(1)            | View head element
 * isEmpty                      | O(1)            | Check if head is null
 * Size                         | O(1)            | Track with counter
 *
 * KEY INSIGHTS:
 * - FIFO (First In, First Out) data structure
 * - No capacity limit (grows dynamically)
 * - Operations at both ends (front and rear)
 * - Uses head and tail pointers for O(1) operations
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

class LinkedListQueue {
    private Node head;  // Front of queue
    private Node tail;  // Rear of queue
    private int count;

    public LinkedListQueue() {
        head = null;
        tail = null;
        count = 0;
    }

    // Check if queue is empty
    public boolean isEmpty() {
        return head == null;
    }

    // Add element to rear of queue (insert at end)
    public void enqueue(int val) {
        Node newNode = new Node(val);
        
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Remove element from front of queue (remove from front)
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Error: Queue underflow!");
            return -1;
        }
        
        int val = head.data;
        head = head.next;
        
        if (head == null) {
            tail = null;  // Queue is now empty
        }
        
        count--;
        return val;
    }

    // Peek at front element without removing
    public int peek() {
        if (isEmpty()) {
            System.out.println("Error: Queue is empty!");
            return -1;
        }
        return head.data;
    }

    // Get current size
    public int size() {
        return count;
    }

    // Print queue contents
    public void print() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.print("Queue (front to rear): ");
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        System.out.println("=== Linked List-Based Queue Demo ===\n");

        LinkedListQueue queue = new LinkedListQueue();

        // Test 1: Enqueue elements
        System.out.println("1. Enqueue elements: 10, 20, 30, 40, 50");
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);
        queue.print();
        System.out.println("   Size: " + queue.size());

        // Test 2: Peek
        System.out.println("\n2. Peek at front element:");
        System.out.println("   Front: " + queue.peek());

        // Test 3: Dequeue elements
        System.out.println("\n3. Dequeue 2 elements:");
        System.out.println("   Dequeued: " + queue.dequeue());
        System.out.println("   Dequeued: " + queue.dequeue());
        queue.print();

        // Test 4: Enqueue more
        System.out.println("\n4. Enqueue 60 and 70:");
        queue.enqueue(60);
        queue.enqueue(70);
        queue.print();

        // Test 5: Queue info
        System.out.println("\n5. Queue info:");
        System.out.println("   Is empty? " + (queue.isEmpty() ? "Yes" : "No"));
        System.out.println("   Size: " + queue.size());

        // Test 6: Dequeue all elements
        System.out.println("\n6. Dequeue all elements:");
        while (!queue.isEmpty()) {
            System.out.println("   Dequeued: " + queue.dequeue());
        }
        queue.print();

        // Test 7: Error handling
        System.out.println("\n7. Try to dequeue from empty queue:");
        queue.dequeue();
        queue.peek();

        // Test 8: Enqueue after emptying
        System.out.println("\n8. Enqueue 100 after emptying:");
        queue.enqueue(100);
        queue.print();

        System.out.println("\nDone!");
    }
}
