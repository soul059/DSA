/*
 * ============================================================================
 * MERGE SORT ALGORITHM
 * ============================================================================
 * 
 * CONCEPT:
 * Merge Sort is a Divide and Conquer algorithm. It divides the array into 
 * two halves, recursively sorts them, and then merges the sorted halves.
 * 
 * HOW IT WORKS:
 * 1. DIVIDE: Split the array into two halves
 * 2. CONQUER: Recursively sort both halves
 * 3. COMBINE: Merge the two sorted halves into one sorted array
 * 
 * EXAMPLE:
 * Array: [38, 27, 43, 3, 9, 82, 10]
 * 
 * DIVIDE PHASE:
 *                    [38, 27, 43, 3, 9, 82, 10]
 *                   /                          \
 *           [38, 27, 43, 3]              [9, 82, 10]
 *           /            \                /        \
 *       [38, 27]      [43, 3]         [9, 82]    [10]
 *       /    \        /    \          /    \
 *     [38]  [27]    [43]  [3]       [9]   [82]
 * 
 * MERGE PHASE:
 *     [27, 38]    [3, 43]         [9, 82]    [10]
 *         \          /                \        /
 *        [3, 27, 38, 43]            [9, 10, 82]
 *                \                      /
 *              [3, 9, 10, 27, 38, 43, 82]
 * 
 * TIME COMPLEXITY:
 * - Best Case:    O(n log n)
 * - Average Case: O(n log n)
 * - Worst Case:   O(n log n)
 * Note: Always O(n log n) regardless of input - very consistent!
 * 
 * SPACE COMPLEXITY: O(n) - Requires additional space for merging
 * 
 * STABILITY: Stable - Equal elements maintain their relative order
 * 
 * ADVANTAGES:
 * - Guaranteed O(n log n) time complexity
 * - Stable sorting algorithm
 * - Well-suited for linked lists
 * - Parallelizable - divide step can run in parallel
 * - Good for external sorting (sorting data on disk)
 * 
 * DISADVANTAGES:
 * - O(n) extra space required
 * - Not in-place
 * - For small arrays, overhead of recursive calls may be significant
 * ============================================================================
 */

#include<iostream>
#include<vector>

using namespace  std;

// Merge function: combines two sorted subarrays into one sorted array
// arr[low..mid] and arr[mid+1..high] are the two sorted subarrays
void merge(int arr[],int low ,int mid ,int high){
    int left = low;       // Starting index of left subarray
    int right = mid+1;    // Starting index of right subarray
    vector<int> temp;     // Temporary array to store merged result
    
    // Compare elements from both subarrays and add smaller one to temp
    while (left <= mid && right <= high)
    {
        if(arr[left] <= arr[right] ){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    // Copy remaining elements of left subarray (if any)
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements of right subarray (if any)
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    // Copy the merged elements back to the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    
    
    
}

// Main Merge Sort function using Divide and Conquer
void mergeSort(int arr[],int low,int high){
    // Base case: single element or invalid range
    if(low >= high) return;
    
    // Find the middle point to divide the array
    int mid = (low + high)/2;
    
    // Recursively sort the left half
    mergeSort(arr,low,mid);
    
    // Recursively sort the right half
    mergeSort(arr,mid+1,high);
    
    // Merge the two sorted halves
    merge(arr,low,mid,high);
    return;
}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout<<"before merge sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    mergeSort(arr,0,n-1);

    cout<<"after merge sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }

    
    return 0;
}