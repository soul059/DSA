/*
 * ============================================================================
 * QUICK SORT ALGORITHM
 * ============================================================================
 * 
 * CONCEPT:
 * Quick Sort is a Divide and Conquer algorithm. It picks a 'pivot' element
 * and partitions the array around the pivot - elements smaller than pivot
 * go to the left, elements greater go to the right.
 * 
 * HOW IT WORKS:
 * 1. Choose a pivot element (here: first element)
 * 2. Partition: rearrange array so that:
 *    - All elements < pivot are on the left
 *    - All elements > pivot are on the right
 *    - Pivot is at its final sorted position
 * 3. Recursively apply to left and right subarrays
 * 
 * PARTITION LOGIC (Hoare's Partition Scheme):
 * - Use two pointers: i from left, j from right
 * - Move i right until element > pivot found
 * - Move j left until element <= pivot found
 * - Swap arr[i] and arr[j]
 * - Repeat until i and j cross
 * - Place pivot at correct position (swap with arr[j])
 * 
 * EXAMPLE:
 * Array: [10, 80, 30, 90, 40, 50, 70] (pivot = 10)
 * After partition: [10] is at correct position
 * 
 * Array: [4, 6, 2, 5, 7, 9, 1, 3] (pivot = 4)
 * After partition: [3, 1, 2] [4] [7, 9, 5, 6]
 * 
 * TIME COMPLEXITY:
 * - Best Case:    O(n log n) - Pivot divides array into equal halves
 * - Average Case: O(n log n)
 * - Worst Case:   O(n²) - Already sorted array (with first/last as pivot)
 * 
 * SPACE COMPLEXITY: 
 * - O(log n) for recursive call stack (average case)
 * - O(n) in worst case
 * 
 * STABILITY: Not Stable - Equal elements may change relative order
 * 
 * ADVANTAGES:
 * - In-place sorting (only O(log n) extra space for recursion)
 * - Cache-friendly due to good locality of reference
 * - Average case is O(n log n) - very fast in practice
 * - Tail-recursive optimization possible
 * 
 * DISADVANTAGES:
 * - O(n²) worst case (can be mitigated with random pivot)
 * - Not stable
 * - Not adaptive (doesn't benefit from partially sorted arrays)
 * 
 * OPTIMIZATION TIPS:
 * - Use random pivot or median-of-three to avoid worst case
 * - Switch to insertion sort for small subarrays (n < 10)
 * - Use tail recursion optimization
 * ============================================================================
 */

#include<iostream>
#include<algorithm> // Include the <algorithm> header for the swap function
using namespace  std;

// Partition function using Hoare's partition scheme
// Places pivot at its correct position and returns the pivot index
int part(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose first element as pivot
    int i = low;           // Left pointer
    int j = high;          // Right pointer

    while (i < j) {
        // Move i right: find element greater than pivot
        while (pivot >= arr[i] && i <= high - 1) {
            i++;
        }
        // Move j left: find element smaller than or equal to pivot
        while (pivot < arr[j] && j >= low + 1) {
            j--;
        }
        // Swap elements at i and j if they haven't crossed
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot at its correct position (j is the partition point)
    swap(arr[low], arr[j]);

    return j;  // Return the partition index
}

// Main Quick Sort function
void quickSort(int arr[], int low, int high) {
    // Base case: if low >= high, subarray has 0 or 1 element
    if (low < high) {
        // Partition the array and get the pivot index
        int pIndex = part(arr, low, high);
        
        // Recursively sort elements before pivot
        quickSort(arr, low, pIndex - 1);
        
        // Recursively sort elements after pivot
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "before quick sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, n - 1);

    cout << "after quick sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
