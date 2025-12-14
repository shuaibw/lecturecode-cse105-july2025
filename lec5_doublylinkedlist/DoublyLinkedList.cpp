#include <iostream>

using namespace std;

/*
 * ============================================================================
 * DOUBLY LINKED LIST OPERATION TIME COMPLEXITY
 * ============================================================================
 *
 * Operation                    | Time Complexity | Notes
 * ------------------------------|-----------------|------------------------
 * Insert at Head               | O(1)            | Direct access via head pointer
 * Insert at Tail               | O(1)            | Direct access via tail pointer
 * Insert at Index              | O(n)            | Must traverse to position
 * Find Node (by value)         | O(n)            | Linear search through list
 * Get Head                     | O(1)            | Direct access
 * Get Tail                     | O(1)            | Direct access
 * Get Node at Index            | O(n)            | Must traverse from head/tail
 * Remove at Head               | O(1)            | Update head pointer only
 * Remove at Tail               | O(1)            | Update tail pointer only
 * Remove at Index              | O(n)            | Must find node to remove
 * Print Forward/Backward       | O(n)            | Visit each node once
 *
 * KEY INSIGHTS:
 * - DLL is better than SLL for tail operations (O(1) vs O(n))
 * - Can traverse in both directions
 * - Extra memory for prev pointer (space trade-off)
 * - Head and tail operations are both O(1)
 * ============================================================================
 */

class Node {
   public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL {
   public:
    Node* head;
    Node* tail;
    
    DLL() {
        head = nullptr;
        tail = nullptr;
    }
    
    // Print the list forward
    void printForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << "<->";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    // Print the list backward
    void printBackward() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << "<->";
            current = current->prev;
        }
        std::cout << std::endl;
    }
    
    // Create list from array
    void createFromArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            insertAtEnd(arr[i]);
        }
    }
    
    // Insert at front
    void insertAtFront(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    // Insert at index
    void insertAtIdx(int index, int val) {
        if (index == 0) {
            insertAtFront(val);
            return;
        }
        Node* prev = getNodeAt(index - 1);
        if (prev == nullptr) return;
        if (prev->next != nullptr) {
            Node* newNode = new Node(val);
            newNode->next = prev->next;
            newNode->prev = prev;
            prev->next->prev = newNode;
            prev->next = newNode;
        } else {
            insertAtEnd(val);
        }
    }
    

    // Get node at index
    Node* getNodeAt(int index) {
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr) {
            if (currentIndex == index) {
                return current;
            }
            current = current->next;
            currentIndex++;
        }
        return nullptr;
    }
    
    // Find index of value
    int indexOf(int val) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == val) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
    
    // Remove at front
    void removeAtFront() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }
    
    // Remove at end
    void removeAtEnd() {
        if (tail == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }
    
    // Remove at index
    void removeAtIdx(int index) {
        if (index == 0) {
            removeAtFront();
            return;
        }
        Node* temp = getNodeAt(index);
        if (temp == nullptr) return;
        temp->prev->next = temp->next;
        if (temp != tail) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        delete temp;
    }
};

int main(){
    std::cout << "=== Doubly Linked List Operations Testing ===" << std::endl << std::endl;
    
    // Test 1: Create from array
    std::cout << "1. Create from array [15, 42, 10, 5, 19]:" << std::endl;
    DLL dll;
    int arr[5] = {15, 42, 10, 5, 19};
    dll.createFromArray(arr, 5);
    std::cout << "   Forward:  ";
    dll.printForward();
    std::cout << "   Backward: ";
    dll.printBackward();
    
    // Test 2: Insert at front
    std::cout << "2. Insert 100 at front:" << std::endl;
    dll.insertAtFront(100);
    std::cout << "   Forward:  ";
    dll.printForward();
    
    // Test 3: Insert at end
    std::cout << "3. Insert 1 at end:" << std::endl;
    dll.insertAtEnd(1);
    std::cout << "   Forward:  ";
    dll.printForward();
    
    // Test 4: Insert at index
    std::cout << "4. Insert 50 at index 2:" << std::endl;
    dll.insertAtIdx(2, 50);
    std::cout << "   Forward:  ";
    dll.printForward();
    
    // Test 5: indexOf
    std::cout << "5. Find index of value 42:" << std::endl;
    std::cout << "   Index: " << dll.indexOf(42) << std::endl;
    std::cout << "   Index of 999 (not found): " << dll.indexOf(999) << std::endl;
    
    // Test 6: getNodeAt
    std::cout << "6. Get node at index 3:" << std::endl;
    Node* node = dll.getNodeAt(3);
    if(node) std::cout << "   Value: " << node->data << std::endl;
    else std::cout << "   Out of bounds" << std::endl;
    
    // Test 7: Remove at front
    std::cout << "7. Remove at front:" << std::endl;
    dll.removeAtFront();
    std::cout << "   Forward:  ";
    dll.printForward();
    
    // Test 8: Remove at end
    std::cout << "8. Remove at end:" << std::endl;
    dll.removeAtEnd();
    std::cout << "   Forward:  ";
    dll.printForward();
    
    // Test 9: Remove at index
    std::cout << "9. Remove at index 1:" << std::endl;
    dll.removeAtIdx(1);
    std::cout << "   Forward:  ";
    dll.printForward();
    std::cout << "   Backward: ";
    dll.printBackward();
    
    std::cout << "Done!" << std::endl;
    
    return 0;
}