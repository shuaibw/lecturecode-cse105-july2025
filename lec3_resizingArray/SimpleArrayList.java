public class SimpleArrayList {
    static int size = 0, capacity = 10;
    static int[] arr;

    // Initialize the dynamic array to the given capacity
    static void initialize(int initialCapacity) {
        capacity = initialCapacity;
        arr = new int[capacity];
        size = 0;
    }

    // Insert the value at the end of the array
    static void insertItem(int value) {
        if (size == capacity) {
            capacity *= 2;
            int[] newArr = new int[capacity];
            System.arraycopy(arr, 0, newArr, 0, size);
            arr = newArr;
        }
        arr[size++] = value;
    }

    // Remove an element from the end of the array and return its value
    static int removeItem() {
        if (size == 0) {
            System.out.println("Array is empty, cannot remove element.");
            return -1; // Indicate error
        }
        int data = arr[--size];
        if (size <= capacity / 4 && capacity > 2) {
            capacity /= 2;
            int[] newArr = new int[capacity];
            System.arraycopy(arr, 0, newArr, 0, size);
            arr = newArr;
        }
        return data;
    }

    static void printArray() {
        System.out.print("[");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i]);
            if (i < size - 1) System.out.print(", ");
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.printf("Usage: %s <num_elements>\n", "SimpleArrayList");
            return;
        }
        int numElements = Integer.parseInt(args[0]);
        initialize(2);
        for (int i = 0; i < numElements; i++) {
            insertItem(i);
        }
        System.out.printf("Array after inserting %d elements:\n", numElements);
        // printArray();
        for (int i = 0; i < numElements; i++) {
            int removedValue = removeItem();
            // System.out.printf("Removed: %d\n", removedValue);
        }
        System.out.println("Array after removing all elements:");
        // printArray();
    }
}
