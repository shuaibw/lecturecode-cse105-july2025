package lec1_intro1;

public class PointerArithmetic {
    // Reverse an array in place using indices
    public static void reverseArray(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        
        while (start < end) {
            // Swap elements
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            
            start++;
            end--;
        }
    }
    
    public static void main(String[] args) {
        int[] numbers = {10, 20, 30, 40, 50, 60};
        
        System.out.print("Original: ");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
        
        reverseArray(numbers);
        
        System.out.print("Reversed: ");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
    }
}

/*
NO POINTER ARITHMETIC IN JAVA:
1. Use indices instead of pointer arithmetic.
2. Array bounds automatically checked - can't corrupt memory.
3. arr.length gives size - don't need to track it separately.
4. If you go out of bounds, you get a clear error, not a crash.
5. Cleaner, safer code that's easier to understand.

TRADE-OFF:
- C: Maximum control and performance, but you can shoot yourself.
- Java: Safety and convenience, with only tiny performance cost.

For learning data structures and algorithms, Java lets you
focus on the CONCEPTS without getting bogged down in memory
management details!
*/
