import java.util.*;

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
    int data;
    Node next;

    Node(int val) {
        data = val;
        next = null;
    }
}

public class SimpleLinkedList {

    // Print a linked list from its head
    static void printLinkedList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + "->");
            current = current.next;
        }
        System.out.println();
    }

    // Create a linked list from an array
    static Node createFromArray(int arr[]) {
        Node head = new Node(arr[0]);
        Node current = head;
        for (int i = 1; i < arr.length; i++) {
            current.next = new Node(arr[i]);
            current = current.next;
        }
        return head;
    }

    // Get index of a node containing value, -1 if not found
    static int indexOf(Node head, int val) {
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

    // Return node located at index, null if out of bounds
    static Node getNodeAt(Node head, int index) {
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

    // Insert a new node at the front of the list
    static Node insertAtFront(Node head, int val) {
        Node newNode = new Node(val);
        newNode.next = head;
        return newNode;  // New head
    }

    // Insert a new node at the specified index
    static Node insertAtIdx(Node head, int index, int val) {
        if (index == 0) {
            return insertAtFront(head, val);
        }
        Node prev = getNodeAt(head, index - 1);
        if (prev != null) {
            Node newNode = new Node(val);
            newNode.next = prev.next;
            prev.next = newNode;
            return head;
        }
        return head; // index out of bounds, no insertion
    }

    // Insert a new node at the end of the list
    static Node insertAtEnd(Node head, int val) {
        if (head == null) {
            return new Node(val);
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = new Node(val);
        return head;
    }

    // Reverse a linked list with recursion
    static Node reverseList(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        Node newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }

    public static void main(String[] args) {
        System.out.println("=== Linked List Operations Testing ===" + "\n");
        
        // Test 1: Create from array
        System.out.println("1. Create from array [15, 42, 10, 5, 19]:");
        int arr[] = {15, 42, 10, 5, 19};
        Node head = createFromArray(arr);
        printLinkedList(head);
        
        // Test 2: Insert at front
        System.out.println("2. Insert 100 at front:");
        head = insertAtFront(head, 100);
        printLinkedList(head);
        
        // Test 3: Insert at index
        System.out.println("3. Insert 50 at index 2:");
        head = insertAtIdx(head, 2, 50);
        printLinkedList(head);
        
        // Test 4: Insert at end
        System.out.println("4. Insert 1 at end:");
        head = insertAtEnd(head, 1);
        printLinkedList(head);
        
        // Test 5: indexOf
        System.out.println("5. Find index of value 42:");
        System.out.println("   Index: " + indexOf(head, 42));
        System.out.println("   Index of 999 (not found): " + indexOf(head, 999));
        
        // Test 6: getNodeAt
        System.out.println("6. Get node at index 3:");
        Node node = getNodeAt(head, 3);
        if (node != null) System.out.println("   Value: " + node.data);
        else System.out.println("   Out of bounds");
        
        // Test 7: printLinkedList (already shown above)
        System.out.print("7. Current list: ");
        printLinkedList(head);
        
        System.out.println("Done!");
    }
}
