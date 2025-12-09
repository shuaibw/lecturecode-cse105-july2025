package lec1_intro1;

public class ComplexMemory {
    public static void main(String[] args) {
        // Array of strings - simple and safe!
        String[] words = new String[3];
        
        words[0] = "Java";
        words[1] = "is";
        words[2] = "easier";
        
        // Print them
        for (int i = 0; i < 3; i++) {
            System.out.print(words[i] + " ");
        }
        System.out.println();
        
        // No manual memory management needed!
        // Garbage collector cleans up automatically.
    }
}

/*
COMPLEX DATA IN JAVA:
1. Single, simple reference (String[]) - no pointer confusion.
2. One allocation - Java handles the details.
3. No need to track or free anything.
4. Much harder to make memory management mistakes.
5. Automatic safety checks prevent common errors.

THE BIG PICTURE:
- C gives you complete control but requires careful memory management.
- Java takes care of memory for you, trading a little performance
  for much better safety and simplicity.
- When you're learning data structures, you want to focus on
  the LOGIC, not fighting with malloc/free!
*/
