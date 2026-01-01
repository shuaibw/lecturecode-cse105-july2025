#include <iostream>

using namespace std;

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

class CircularArrayQueue {
private:
    int* data;
    int front;     // Front of queue (index)
    int rear;      // Rear of queue (index)
    int count;     // Number of elements
    int capacity;

public:
    CircularArrayQueue(int cap = 5) {
        capacity = cap;
        data = new int[capacity];
        front = 0;
        rear = 0;
        count = 0;
    }

    ~CircularArrayQueue() {
        delete[] data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
        
        // Alternative without count: front == rear (but ambiguous with full!)
        // To distinguish empty vs full without count:
        // Option 1: Sacrifice one slot (full when (rear+1)%capacity == front)
        // Option 2: Use a boolean flag (isEmpty flag)
        // Option 3: Use count (our approach - cleanest)
    }

    // Check if queue is full
    bool isFull() {
        return count == capacity;
        
        // Alternative without count: (rear+1) % capacity == front
        // Problem: This also means empty if we don't maintain count!
        // That's why we either:
        // - Maintain count (our approach)
        // - Waste one array slot (capacity-1 elements max)
        // - Use additional flag variable
    }

    // Add element to rear of queue
    void enqueue(int val) {
        if (isFull()) {
            cout << "Error: Queue overflow!" << endl;
            return;
        }
        
        data[rear] = val;
        rear = (rear + 1) % capacity;  // Circular increment
        count++;
    }

    // Remove element from front of queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue underflow!" << endl;
            return -1;
        }
        
        int val = data[front];
        front = (front + 1) % capacity;  // Circular increment
        count--;
        return val;
    }

    // Peek at front element without removing
    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return -1;
        }
        return data[front];
    }

    // Get current size
    int size() {
        return count;
    }

    // Print queue contents
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << data[idx] << " ";
            idx = (idx + 1) % capacity;  // Circular traversal
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Circular Array-Based Queue Demo ===" << endl << endl;

    CircularArrayQueue queue(5);

    // Test 1: Enqueue elements
    cout << "1. Enqueue elements: 10, 20, 30, 40, 50" << endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.print();
    cout << "   Size: " << queue.size() << endl;

    // Test 2: Try to enqueue when full
    cout << "\n2. Try to enqueue 60 (should overflow):" << endl;
    queue.enqueue(60);
    queue.print();

    // Test 3: Peek
    cout << "\n3. Peek at front element:" << endl;
    cout << "   Front: " << queue.peek() << endl;

    // Test 4: Dequeue elements
    cout << "\n4. Dequeue 2 elements:" << endl;
    cout << "   Dequeued: " << queue.dequeue() << endl;
    cout << "   Dequeued: " << queue.dequeue() << endl;
    queue.print();

    // Test 5: Enqueue more (showing circular behavior)
    cout << "\n5. Enqueue 60 and 70 (circular wrap-around):" << endl;
    queue.enqueue(60);
    queue.enqueue(70);
    queue.print();

    // Test 6: Queue info
    cout << "\n6. Queue info:" << endl;
    cout << "   Is empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "   Is full? " << (queue.isFull() ? "Yes" : "No") << endl;
    cout << "   Size: " << queue.size() << endl;

    // Test 7: Dequeue all elements
    cout << "\n7. Dequeue all elements:" << endl;
    while (!queue.isEmpty()) {
        cout << "   Dequeued: " << queue.dequeue() << endl;
    }
    queue.print();

    // Test 8: Error handling
    cout << "\n8. Try to dequeue from empty queue:" << endl;
    queue.dequeue();
    queue.peek();

    // Test 9: Enqueue after emptying
    cout << "\n9. Enqueue 100 after emptying:" << endl;
    queue.enqueue(100);
    queue.print();

    cout << "\nDone!" << endl;

    return 0;
}
