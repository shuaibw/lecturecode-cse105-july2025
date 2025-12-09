package lec1_intro1;

public class ArrayMemory {
    public static void main(String[] args) {
        // Create array of 5 integers - memory automatically allocated!
        int[] numbers = new int[5];
        
        // Fill the array
        for (int i = 0; i < 5; i++) {
            numbers[i] = i * 10;
        }
        
        // Print the array
        System.out.print("Array: ");
        for (int i = 0; i < 5; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
        
        // Java knows the array size!
        System.out.println("Array length: " + numbers.length);
        
        // No need to free memory - garbage collector handles it!
        
        // Array bounds are checked automatically!
        // This would throw an exception instead of corrupting memory:
        // numbers[10] = 100;  // ArrayIndexOutOfBoundsException
    }
}

/*
ARRAYS IN JAVA:
1. Size specified at creation, but can create new arrays anytime.
2. Built-in .length property tells you the size.
3. Automatic bounds checking prevents memory corruption.
4. Memory automatically managed - no malloc/free needed.
5. Much safer than C arrays, with minimal performance cost.
*/
