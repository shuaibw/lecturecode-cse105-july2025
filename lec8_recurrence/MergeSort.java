import java.util.Random;

public class MergeSort {
    
    public static void merge(int[] ara, int lo, int mid, int hi) {
        int[] merged = new int[hi - lo];
        int left = lo, right = mid, k = 0;
        
        // Merge the two sorted halves
        while (left < mid && right < hi) {
            if (ara[left] < ara[right]) {
                merged[k++] = ara[left++];
            } else {
                merged[k++] = ara[right++];
            }
        }
        
        // Copy remaining elements from left half
        while (left < mid) {
            merged[k++] = ara[left++];
        }
        
        // Copy remaining elements from right half
        while (right < hi) {
            merged[k++] = ara[right++];
        }
        
        // Copy merged array back to original
        for (int idx = 0; idx < hi - lo; idx++) {
            ara[lo + idx] = merged[idx];
        }
    }
    
    public static void mergesort(int[] ara, int lo, int hi) {
        if (hi - lo <= 1) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        mergesort(ara, lo, mid);
        mergesort(ara, mid, hi);
        merge(ara, lo, mid, hi);
    }
    
    public static void printArray(int[] arr, int n) {
        System.out.print("[");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]);
            if (i < n - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
    
    public static boolean isSorted(int[] arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) {
        // take n from command line, create array of size n with random integers
        if (args.length < 1) {
            System.out.println("Usage: java MergeSort <num_elements>");
            return;
        }
        int n = Integer.parseInt(args[0]);
        int[] arr = new int[n];
        Random rand = new Random(123);  // deterministic seed
        for (int i = 0; i < n; i++) {
            arr[i] = rand.nextInt(n / 10);  // random integers in [0, n/10)
        }
        
        System.out.println("Before sorting (n=" + n + "):");
        if (n <= 20) {
            printArray(arr, n);
        } else {
            System.out.print("First 10: ");
            printArray(arr, 10);
        }
        
        mergesort(arr, 0, n);
        
        System.out.println("\nAfter sorting:");
        if (n <= 20) {
            printArray(arr, n);
        } else {
            System.out.print("First 100: ");
            printArray(arr, 100);
        }
        
        if (isSorted(arr, n)) {
            System.out.println("\n✓ Array is correctly sorted!");
        } else {
            System.out.println("\n✗ ERROR: Array is NOT sorted!");
        }
    }
}
