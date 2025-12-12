#include <iostream>

using namespace std;

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

int main() {
    // Create a simple linked list: 21 -> 43 -> 31 -> 10
    Node* n1 = new Node(21);
    Node* n2 = new Node(43);
    Node* n3 = new Node(31);
    Node* n4 = new Node(10);

    Node* head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Node* tail = n4;
    printLinkedList(head);
    freeLinkedList(head);

    int arr[5] = {15, 42, 10, 5, 19};
    head = createFromArray(arr, 5);
    printLinkedList(head);
    freeLinkedList(head);

    return 0;
    
}
