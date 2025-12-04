/*
 * ============================================================================
 * BUBBLE SORT ALGORITHM
 * ============================================================================
 * 
 * CONCEPT:
 * Bubble Sort repeatedly steps through the list, compares adjacent elements,
 * and swaps them if they are in the wrong order. The largest elements 
 * "bubble up" to the end of the array with each pass.
 * 
 * HOW IT WORKS:
 * 1. Compare adjacent elements starting from the beginning
 * 2. If the left element > right element, swap them
 * 3. Continue until the end of array (largest element bubbles to the end)
 * 4. Repeat the process for remaining unsorted portion
 * 5. Stop when no swaps are made in a complete pass (optimization)
 * 
 * EXAMPLE:
 * Array: [5, 1, 4, 2, 8]
 * Pass 1: [1, 4, 2, 5, 8] - 8 bubbles to end
 * Pass 2: [1, 2, 4, 5, 8] - 5 already in place
 * Pass 3: [1, 2, 4, 5, 8] - No swaps, array is sorted!
 * 
 * TIME COMPLEXITY:
 * - Best Case:    O(n)   - Array already sorted (with optimization)
 * - Average Case: O(n²)
 * - Worst Case:   O(n²)  - Array sorted in reverse order
 * 
 * SPACE COMPLEXITY: O(1) - In-place sorting
 * 
 * STABILITY: Stable - Equal elements maintain their relative order
 * 
 * ADVANTAGES:
 * - Simple to understand and implement
 * - Detects if array is already sorted (adaptive)
 * - Stable sorting algorithm
 * - In-place algorithm
 * 
 * DISADVANTAGES:
 * - O(n²) makes it slow for large datasets
 * - Many swap operations compared to selection sort
 * ============================================================================
 */

#include<iostream>
using namespace  std;

// Iterative Bubble Sort with optimization
void bubbleSort(int arr[],int n){
    // Outer loop: each pass places one element in its correct position
    for (int i = 0; i < n-1; i++)
    {
        // Flag to detect if any swap occurred in this pass
        bool didswap= false;
        
        // Inner loop: compare adjacent elements
        // Note: n-1-i because last i elements are already sorted
        for (int j = 0; j < n-1-i; j++)
        {
            // If current element is greater than next, swap them
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap = true;
            }
        }
        
        // Optimization: if no swaps occurred, array is already sorted
        if (!didswap)
        {
            break;
        }
        
        
    }
    
}


// Recursive version of Bubble Sort
// Each recursive call handles one pass, reducing the range by 1
void recursiveBubbleSort(int arr[],int low,int high){
    // Base case: if low >= high, sorting is complete
    if(low < high){
        bool didswap = false;
        
        // One pass of bubble sort - bubble the largest to 'high' position
        for (int i = 0; i < high; i++)
        {
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                didswap = true;
            }
        }
        
        // Optimization: stop if no swaps (array is sorted)
        if (!didswap)
        {
            return;
        }
        
        // Recursive call: reduce range since largest is now at 'high'
        recursiveBubbleSort(arr,low,high-1);
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
    
    cout<<"before bubble sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    bubbleSort(arr,n);

    cout<<"after bubble sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }

    
    return 0;
}