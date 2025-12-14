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
    int data;
    Node next;
    Node prev;

    Node(int val) {
        data = val;
        next = null;
        prev = null;
    }
}

class DLL {
    Node head;
    Node tail;
    
    DLL() {
        head = null;
        tail = null;
    }
    
    // Print the list forward
    void printForward() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + "<->");
            current = current.next;
        }
        System.out.println();
    }
    
    // Print the list backward
    void printBackward() {
        Node current = tail;
        while (current != null) {
            System.out.print(current.data + "<->");
            current = current.prev;
        }
        System.out.println();
    }
    
    // Create list from array
    void createFromArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            insertAtEnd(arr[i]);
        }
    }
    
    // Insert at front
    void insertAtFront(int val) {
        Node newNode = new Node(val);
        if (head == null) {
            head = tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
    }
    
    // Insert at end
    void insertAtEnd(int val) {
        Node newNode = new Node(val);
        if (head == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }
    
    // Insert at index
    void insertAtIdx(int index, int val) {
        if (index == 0) {
            insertAtFront(val);
            return;
        }
        Node prev = getNodeAt(index - 1);
        if (prev == null) return;
        if (prev.next != null) {
            Node newNode = new Node(val);
            newNode.next = prev.next;
            newNode.prev = prev;
            prev.next.prev = newNode;
            prev.next = newNode;
        } else {
            insertAtEnd(val);
        }
    }
    
    // Get node at index
    Node getNodeAt(int index) {
        Node current = head;
        int currentIndex = 0;
        while (current != null) {
            if (currentIndex == index) {
                return current;
            }
            current = current.next;
            currentIndex++;
        }
        return null;
    }
    
    // Find index of value
    int indexOf(int val) {
        Node current = head;
        int index = 0;
        while (current != null) {
            if (current.data == val) {
                return index;
            }
            current = current.next;
            index++;
        }
        return -1;
    }
    
    // Remove at front
    void removeAtFront() {
        if (head == null) return;
        if (head == tail) {
            head = tail = null;
        } else {
            head = head.next;
            head.prev = null;
        }
    }
    
    // Remove at end
    void removeAtEnd() {
        if (tail == null) return;
        if (head == tail) {
            head = tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
    }
    
    // Remove at index
    void removeAtIdx(int index) {
        if (index == 0) {
            removeAtFront();
            return;
        }
        Node temp = getNodeAt(index);
        if (temp == null) return;
        
        temp.prev.next = temp.next;
        if (temp != tail) {
            temp.next.prev = temp.prev;
        } else {
            tail = temp.prev;
        }
    }
}

public class DoublyLinkedList {
    public static void main(String[] args) {
        System.out.println("=== Doubly Linked List Operations Testing ===\n");
        
        // Test 1: Create from array
        System.out.println("1. Create from array [15, 42, 10, 5, 19]:");
        DLL dll = new DLL();
        int arr[] = {15, 42, 10, 5, 19};
        dll.createFromArray(arr);
        System.out.print("   Forward:  ");
        dll.printForward();
        System.out.print("   Backward: ");
        dll.printBackward();
        
        // Test 2: Insert at front
        System.out.println("2. Insert 100 at front:");
        dll.insertAtFront(100);
        System.out.print("   Forward:  ");
        dll.printForward();
        
        // Test 3: Insert at end
        System.out.println("3. Insert 1 at end:");
        dll.insertAtEnd(1);
        System.out.print("   Forward:  ");
        dll.printForward();
        
        // Test 4: Insert at index
        System.out.println("4. Insert 50 at index 2:");
        dll.insertAtIdx(2, 50);
        System.out.print("   Forward:  ");
        dll.printForward();
        
        // Test 5: indexOf
        System.out.println("5. Find index of value 42:");
        System.out.println("   Index: " + dll.indexOf(42));
        System.out.println("   Index of 999 (not found): " + dll.indexOf(999));
        
        // Test 6: getNodeAt
        System.out.println("6. Get node at index 3:");
        Node node = dll.getNodeAt(3);
        if (node != null) System.out.println("   Value: " + node.data);
        else System.out.println("   Out of bounds");
        
        // Test 7: Remove at front
        System.out.println("7. Remove at front:");
        dll.removeAtFront();
        System.out.print("   Forward:  ");
        dll.printForward();
        
        // Test 8: Remove at end
        System.out.println("8. Remove at end:");
        dll.removeAtEnd();
        System.out.print("   Forward:  ");
        dll.printForward();
        
        // Test 9: Remove at index
        System.out.println("9. Remove at index 1:");
        dll.removeAtIdx(1);
        System.out.print("   Forward:  ");
        dll.printForward();
        System.out.print("   Backward: ");
        dll.printBackward();
        
        System.out.println("Done!");
    }
}
