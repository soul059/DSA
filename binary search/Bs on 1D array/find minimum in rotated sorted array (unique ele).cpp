/*
 * FIND MINIMUM IN ROTATED SORTED ARRAY
 * 
 * Approach: Binary Search
 * - If left half sorted: min is arr[low], search right
 * - If right half sorted: min might be arr[mid], search left
 * 
 * Time: O(log n) | Space: O(1)
 * 
 * Minimum is the pivot point (rotation count)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int minInRotatedSorted(vector<int> arr,int target){
    int low=0, high= arr.size()-1;
    int mini = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low] <= arr[high]){ //optimization ont needed
            mini = min(mini,arr[low]);
            break;
        }
        if(arr[low] <= arr[mid]){ //left half sorted
            mini = min(mini,arr[low]);
            low = mid +1;
        }
        else{ //right half sorted
            mini = min(mini,arr[mid]);
            high = mid-1;
        }
    }
    return mini;
}

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = minInRotatedSorted(arr,x);
    cout<<"minimus element is: "<<ans<<endl;
    return 0;
}