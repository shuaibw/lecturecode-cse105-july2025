#include <iostream>

using namespace std;

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
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedListQueue {
private:
    Node* head;  // Front of queue
    Node* tail;  // Rear of queue
    int count;

public:
    LinkedListQueue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Add element to rear of queue (insert at end)
    void enqueue(int val) {
        Node* newNode = new Node(val);
        
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Remove element from front of queue (remove from front)
    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue underflow!" << endl;
            return -1;
        }
        
        Node* temp = head;
        int val = head->data;
        head = head->next;
        
        if (head == nullptr) {
            tail = nullptr;  // Queue is now empty
        }
        
        delete temp;
        count--;
        return val;
    }

    // Peek at front element without removing
    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return -1;
        }
        return head->data;
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
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Linked List-Based Queue Demo ===" << endl << endl;

    LinkedListQueue queue;

    // Test 1: Enqueue elements
    cout << "1. Enqueue elements: 10, 20, 30, 40, 50" << endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.print();
    cout << "   Size: " << queue.size() << endl;

    // Test 2: Peek
    cout << "\n2. Peek at front element:" << endl;
    cout << "   Front: " << queue.peek() << endl;

    // Test 3: Dequeue elements
    cout << "\n3. Dequeue 2 elements:" << endl;
    cout << "   Dequeued: " << queue.dequeue() << endl;
    cout << "   Dequeued: " << queue.dequeue() << endl;
    queue.print();

    // Test 4: Enqueue more
    cout << "\n4. Enqueue 60 and 70:" << endl;
    queue.enqueue(60);
    queue.enqueue(70);
    queue.print();

    // Test 5: Queue info
    cout << "\n5. Queue info:" << endl;
    cout << "   Is empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "   Size: " << queue.size() << endl;

    // Test 6: Dequeue all elements
    cout << "\n6. Dequeue all elements:" << endl;
    while (!queue.isEmpty()) {
        cout << "   Dequeued: " << queue.dequeue() << endl;
    }
    queue.print();

    // Test 7: Error handling
    cout << "\n7. Try to dequeue from empty queue:" << endl;
    queue.dequeue();
    queue.peek();

    // Test 8: Enqueue after emptying
    cout << "\n8. Enqueue 100 after emptying:" << endl;
    queue.enqueue(100);
    queue.print();

    cout << "\nDone!" << endl;

    return 0;
}
