/*
 * ============================================================================
 * INSERTION SORT ALGORITHM
 * ============================================================================
 * 
 * CONCEPT:
 * Insertion Sort builds the sorted array one element at a time by repeatedly
 * picking the next element and inserting it into its correct position in the
 * already sorted portion. Similar to how we sort playing cards in our hands.
 * 
 * HOW IT WORKS:
 * 1. Start with the second element (first element is trivially sorted)
 * 2. Compare it with elements before it
 * 3. Shift all larger elements one position to the right
 * 4. Insert the current element at its correct position
 * 5. Repeat for all remaining elements
 * 
 * EXAMPLE:
 * Array: [5, 2, 4, 6, 1, 3]
 * Step 1: [5] | 2, 4, 6, 1, 3  → Insert 2 → [2, 5] | 4, 6, 1, 3
 * Step 2: [2, 5] | 4, 6, 1, 3  → Insert 4 → [2, 4, 5] | 6, 1, 3
 * Step 3: [2, 4, 5] | 6, 1, 3  → Insert 6 → [2, 4, 5, 6] | 1, 3
 * Step 4: [2, 4, 5, 6] | 1, 3  → Insert 1 → [1, 2, 4, 5, 6] | 3
 * Step 5: [1, 2, 4, 5, 6] | 3  → Insert 3 → [1, 2, 3, 4, 5, 6]
 * 
 * TIME COMPLEXITY:
 * - Best Case:    O(n)   - Array already sorted (only comparisons, no shifts)
 * - Average Case: O(n²)
 * - Worst Case:   O(n²)  - Array sorted in reverse order
 * 
 * SPACE COMPLEXITY: O(1) - In-place sorting
 * 
 * STABILITY: Stable - Equal elements maintain their relative order
 * 
 * ADVANTAGES:
 * - Simple implementation
 * - Efficient for small datasets
 * - Adaptive: O(n) for nearly sorted arrays
 * - Stable sorting algorithm
 * - In-place algorithm
 * - Online algorithm: can sort as data is received
 * 
 * DISADVANTAGES:
 * - O(n²) makes it inefficient for large datasets
 * - Many shifts required for reverse sorted arrays
 * ============================================================================
 */

#include<iostream>
using namespace  std;

// Iterative Insertion Sort
void insertionSort(int arr[],int n){
    // Start from index 0, consider each element for insertion
    for(int i=0;i<n;i++){
        int j = i+1;
        
        // Move elements of arr[0..i] that are greater than arr[j]
        // one position ahead of their current position
        while (j > 0 && arr[j] < arr[j-1])
        {
            // Swap current element with previous until correct position found
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

// Recursive version of Insertion Sort
// Sorts one element in each recursive call and moves forward
void recursiveInsertionSort(int arr[],int low,int high){
    // Base case: when low >= high, all elements are sorted
   if(low < high){
        int j = low + 1;
        
        // Insert arr[low+1] into sorted portion arr[0..low]
        while(j > 0 && arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
        
        // Recursive call: move to next element
        recursiveInsertionSort(arr,low+1,high);
    }
}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout<<"before insertion sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    insertionSort(arr,n);

    cout<<"after insertion sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }

    
    return 0;
}