#include <iostream>

using namespace std;

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
 * - More memory per element (due to pointers)
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

class LinkedListStack {
private:
    Node* head;
    int count;

public:
    LinkedListStack() {
        head = nullptr;
        count = 0;
    }

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Push element onto stack (insert at front)
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        count++;
    }

    // Pop element from stack (remove from front)
    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack underflow!" << endl;
            return -1;
        }
        
        Node* temp = head;
        int val = head->data;
        head = head->next;
        delete temp;
        count--;
        return val;
    }

    // Peek at top element without removing
    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    // Get current size
    int size() {
        return count;
    }

    // Print stack contents
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Linked List-Based Stack Demo ===" << endl << endl;

    LinkedListStack stack;

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
    cout << "\n4. Push 60 and 70:" << endl;
    stack.push(60);
    stack.push(70);
    stack.print();

    // Test 5: Stack info
    cout << "\n5. Stack info:" << endl;
    cout << "   Is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "   Size: " << stack.size() << endl;

    // Test 6: Pop all elements
    cout << "\n6. Pop all elements:" << endl;
    while (!stack.isEmpty()) {
        cout << "   Popped: " << stack.pop() << endl;
    }
    stack.print();

    // Test 7: Error handling
    cout << "\n7. Try to pop from empty stack:" << endl;
    stack.pop();
    stack.peek();

    // Test 8: Push after emptying
    cout << "\n8. Push 100 after emptying:" << endl;
    stack.push(100);
    stack.print();

    cout << "\nDone!" << endl;

    return 0;
}
