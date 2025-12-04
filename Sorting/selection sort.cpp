/*
 * ============================================================================
 * SELECTION SORT ALGORITHM
 * ============================================================================
 * 
 * CONCEPT:
 * Selection Sort works by repeatedly finding the minimum element from the 
 * unsorted portion of the array and placing it at the beginning.
 * 
 * HOW IT WORKS:
 * 1. Divide the array into two parts: sorted (left) and unsorted (right)
 * 2. Initially, sorted part is empty, unsorted part is the entire array
 * 3. Find the minimum element in unsorted part
 * 4. Swap it with the first element of unsorted part
 * 5. Move the boundary of sorted part one element to the right
 * 6. Repeat until the entire array is sorted
 * 
 * EXAMPLE:
 * Array: [64, 25, 12, 22, 11]
 * Pass 1: Find min (11), swap with 64 → [11, 25, 12, 22, 64]
 * Pass 2: Find min (12), swap with 25 → [11, 12, 25, 22, 64]
 * Pass 3: Find min (22), swap with 25 → [11, 12, 22, 25, 64]
 * Pass 4: Find min (25), already in place → [11, 12, 22, 25, 64]
 * 
 * TIME COMPLEXITY:
 * - Best Case:    O(n²) - Even if sorted, we still check all elements
 * - Average Case: O(n²)
 * - Worst Case:   O(n²)
 * 
 * SPACE COMPLEXITY: O(1) - In-place sorting, no extra space needed
 * 
 * STABILITY: Not Stable - Equal elements may change their relative order
 * 
 * ADVANTAGES:
 * - Simple to understand and implement
 * - Performs well on small arrays
 * - Minimum number of swaps (at most n-1 swaps)
 * 
 * DISADVANTAGES:
 * - O(n²) complexity makes it inefficient for large datasets
 * - Does not adapt to partially sorted arrays
 * ============================================================================
 */

#include<iostream>
using namespace  std;

void selectionSort(int arr[], int n){
    // Outer loop: iterate through each position in the array
    for (int i = 0; i < n-1; i++)
    {
        // Assume the current position has the minimum value
        int min = i;
        
        // Inner loop: find the actual minimum in the unsorted portion
        for (int j = i+1; j < n; j++)
        {
            // If we find a smaller element, update min index
            if (arr[min] > arr[j])
            {
                min = j;
            } 
        }
        
        // Optimization: skip swap if minimum is already at correct position
        if(min == i) continue;
        
        // Swap the found minimum with the first element of unsorted part
        swap(arr[i],arr[min]);
        
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
    
    cout<<"before selection sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    selectionSort(arr,n);

    cout<<"after selection sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }

    
    return 0;
}