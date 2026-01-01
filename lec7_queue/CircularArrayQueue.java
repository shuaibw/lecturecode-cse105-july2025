/*
 * ============================================================================
 * QUEUE OPERATION TIME COMPLEXITY (Circular Array Implementation)
 * ============================================================================
 *
 * Operation                    | Time Complexity | Notes
 * ------------------------------|-----------------|------------------------
 * Enqueue (add to rear)        | O(1)            | Insert at tail index
 * Dequeue (remove from front)  | O(1)            | Remove from head index
 * Peek/Front                   | O(1)            | View head element
 * isEmpty                      | O(1)            | Check count == 0
 * isFull                       | O(1)            | Check count == capacity
 * Size                         | O(1)            | Return count
 *
 * KEY INSIGHTS:
 * - FIFO (First In, First Out) data structure
 * - Fixed capacity (no dynamic resizing)
 * - Circular indexing: uses modulo (%) to wrap around
 * - More space-efficient than linear array queue
 * - No wasted space after dequeue operations
 * ============================================================================
 */

public class CircularArrayQueue {
    private int[] data;
    private int front;     // Front of queue (index)
    private int rear;      // Rear of queue (index)
    private int count;     // Number of elements
    private int capacity;

    public CircularArrayQueue(int cap) {
        capacity = cap;
        data = new int[capacity];
        front = 0;
        rear = 0;
        count = 0;
    }

    public CircularArrayQueue() {
        this(5);  // Default capacity of 5
    }

    // Check if queue is empty
    public boolean isEmpty() {
        return count == 0;
        
        // Alternative without count: front == rear (but ambiguous with full!)
        // To distinguish empty vs full without count:
        // Option 1: Sacrifice one slot (full when (rear+1)%capacity == front)
        // Option 2: Use a boolean flag (isEmpty flag)
        // Option 3: Use count (our approach - cleanest)
    }

    // Check if queue is full
    public boolean isFull() {
        return count == capacity;
        
        // Alternative without count: (rear+1) % capacity == front
        // Problem: This also means empty if we don't maintain count!
        // That's why we either:
        // - Maintain count (our approach)
        // - Waste one array slot (capacity-1 elements max)
        // - Use additional flag variable
    }

    // Add element to rear of queue
    public void enqueue(int val) {
        if (isFull()) {
            System.out.println("Error: Queue overflow!");
            return;
        }
        
        data[rear] = val;
        rear = (rear + 1) % capacity;  // Circular increment
        count++;
    }

    // Remove element from front of queue
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Error: Queue underflow!");
            return -1;
        }
        
        int val = data[front];
        front = (front + 1) % capacity;  // Circular increment
        count--;
        return val;
    }

    // Peek at front element without removing
    public int peek() {
        if (isEmpty()) {
            System.out.println("Error: Queue is empty!");
            return -1;
        }
        return data[front];
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
        int idx = front;
        for (int i = 0; i < count; i++) {
            System.out.print(data[idx] + " ");
            idx = (idx + 1) % capacity;  // Circular traversal
        }
        System.out.println();
    }

    public static void main(String[] args) {
        System.out.println("=== Circular Array-Based Queue Demo ===\n");

        CircularArrayQueue queue = new CircularArrayQueue(5);

        // Test 1: Enqueue elements
        System.out.println("1. Enqueue elements: 10, 20, 30, 40, 50");
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);
        queue.print();
        System.out.println("   Size: " + queue.size());

        // Test 2: Try to enqueue when full
        System.out.println("\n2. Try to enqueue 60 (should overflow):");
        queue.enqueue(60);
        queue.print();

        // Test 3: Peek
        System.out.println("\n3. Peek at front element:");
        System.out.println("   Front: " + queue.peek());

        // Test 4: Dequeue elements
        System.out.println("\n4. Dequeue 2 elements:");
        System.out.println("   Dequeued: " + queue.dequeue());
        System.out.println("   Dequeued: " + queue.dequeue());
        queue.print();

        // Test 5: Enqueue more (showing circular behavior)
        System.out.println("\n5. Enqueue 60 and 70 (circular wrap-around):");
        queue.enqueue(60);
        queue.enqueue(70);
        queue.print();

        // Test 6: Queue info
        System.out.println("\n6. Queue info:");
        System.out.println("   Is empty? " + (queue.isEmpty() ? "Yes" : "No"));
        System.out.println("   Is full? " + (queue.isFull() ? "Yes" : "No"));
        System.out.println("   Size: " + queue.size());

        // Test 7: Dequeue all elements
        System.out.println("\n7. Dequeue all elements:");
        while (!queue.isEmpty()) {
            System.out.println("   Dequeued: " + queue.dequeue());
        }
        queue.print();

        // Test 8: Error handling
        System.out.println("\n8. Try to dequeue from empty queue:");
        queue.dequeue();
        queue.peek();

        // Test 9: Enqueue after emptying
        System.out.println("\n9. Enqueue 100 after emptying:");
        queue.enqueue(100);
        queue.print();

        System.out.println("\nDone!");
    }
}
