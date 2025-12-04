/*
 * Search in Rotated Sorted Array with Duplicates
 * Approach: Modified binary search - when duplicates cause arr[low]==arr[mid]==arr[high],
 *           shrink both ends; otherwise identify sorted half and eliminate accordingly
 * Time: O(log n) average, O(n) worst case (all duplicates)
 * Space: O(1)
 * Key: Handle duplicates by shrinking search space when equality at all three pointers
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int serchEleInRoteedSorted(vector<int> arr,int target){
    int low =0,high=arr.size()-1;
    while(low<= high){
        int mid = (low+high) /2;
        if(arr[mid] == target) return mid;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low] <= arr[mid]){ // left half is sorted
            if(arr[low] <= target && target <= arr[mid])
                high = mid -1; // right half elemented
            else 
                low = mid + 1; //left half elemented
        }
        else{ // right half is sorted
            if(arr[mid] <= target && target <= arr[high])
                low = mid + 1; //left half elemented
            else 
                high = mid -1; // right half elemented
        }
    }
    return -1;
}

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>x;

    int ans = serchEleInRoteedSorted(arr,x);
    cout<<"serched index is: "<<ans<<endl;
    return 0;
}