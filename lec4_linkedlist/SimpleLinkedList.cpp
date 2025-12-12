#include <iostream>

using namespace std;

/*
 * ============================================================================
 * LINKED LIST OPERATION TIME COMPLEXITY
 * ============================================================================
 *
 * Operation                    | Time Complexity | Notes
 * ------------------------------|-----------------|------------------------
 * Insert at Head (prepend)      | O(1)            | Direct access, no search
 * Insert at Tail (append)       | O(1)            | With tail pointer, O(n) without
 * Insert at Index               | O(n)            | Must find position first
 * Find Node (by value)          | O(n)            | Linear search through list
 * Get Head                      | O(1)            | Direct access
 * Get Tail                      | O(1)            | With tail pointer; O(n) without
 * Get Node at Index             | O(n)            | Must traverse from head
 * Remove Head                   | O(1)            | Update head pointer only
 * Remove Tail                   | O(n)            | Must find node before tail
 * Remove at Index               | O(n)            | Must find node before target
 * Print/Traverse All            | O(n)            | Visit each node once
 * Get Length                    | O(n)            | Must traverse entire list
 *
 * KEY INSIGHTS:
 * - Singly linked lists excel at head operations (O(1))
 * - Tail operations require maintaining a tail pointer for efficiency
 * - Any search-based operation is O(n) since we must traverse
 * - No random access like arrays (no O(1) index access)
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

// Print a linked list from its head
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << endl;
}

void freeLinkedList(Node* head){
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Create a linked list from an array
Node* createFromArray(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// Get index of a node containing value, -1 if not found
int indexOf(Node* head, int val) {
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

// Return node located at index, nullptr if out of bounds
Node* getNodeAt(Node* head, int index) {
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

// Insert a new node at the front of the list
Node* insertAtFront(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;  // New head
}

// Insert a new node at the specified index
Node* insertAtIdx(Node* head, int index, int val){
    if(index == 0){
        return insertAtFront(head, val);
    }
    Node* prev = getNodeAt(head, index - 1);
    if(prev != nullptr){
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        return head;
    }
    return head; // index out of bounds, no insertion
}

// Insert a new node at the end of the list
Node* insertAtEnd(Node* head, int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = new Node(val);
    return head;
}

// Reverse the linked list recursively
Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main() {
    cout << "=== Linked List Operations Testing ===" << endl << endl;
    
    // Test 1: Create from array
    cout << "1. Create from array [15, 42, 10, 5, 19]:" << endl;
    int arr[5] = {15, 42, 10, 5, 19};
    Node* head = createFromArray(arr, 5);
    printLinkedList(head);
    
    // Test 2: Insert at front
    cout << "2. Insert 100 at front:" << endl;
    head = insertAtFront(head, 100);
    printLinkedList(head);
    
    // Test 3: Insert at index
    cout << "3. Insert 50 at index 2:" << endl;
    head = insertAtIdx(head, 2, 50);
    printLinkedList(head);
    
    // Test 4: Insert at end
    cout << "4. Insert 1 at end:" << endl;
    head = insertAtEnd(head, 1);
    printLinkedList(head);
    
    // Test 5: indexOf
    cout << "5. Find index of value 42:" << endl;
    cout << "   Index: " << indexOf(head, 42) << endl;
    cout << "   Index of 999 (not found): " << indexOf(head, 999) << endl;
    
    // Test 6: getNodeAt
    cout << "6. Get node at index 3:" << endl;
    Node* node = getNodeAt(head, 3);
    if(node) cout << "   Value: " << node->data << endl;
    else cout << "   Out of bounds" << endl;
    
    // Test 7: printLinkedList (already shown above)
    cout << "7. Current list: ";
    printLinkedList(head);
    
    // Test 8: Clean up
    cout << "8. Freeing memory..." << endl;
    freeLinkedList(head);
    cout << "Done!" << endl;

    return 0;
}
