/*
 * SINGLE ELEMENT IN SORTED ARRAY
 * 
 * Every element appears twice except one. Find the single one.
 * 
 * Approach: Binary Search using index parity
 * - Before single: pairs are at (even, odd) indices
 * - After single: pairs are at (odd, even) indices
 * 
 * Time: O(log n) | Space: O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int findSingelInArr(vector<int> arr){
    if(arr.size() == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[arr.size()-1] != arr[arr.size()-2]) return arr[arr.size()-1];
    
    int low=1, high= arr.size()-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        if((mid %2 ==1 && arr[mid] == arr[mid-1]) || (mid%2 == 0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }
        else {
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = findSingelInArr(arr);
    cout<<"single element in array is: "<<ans<<endl;
    return 0;
}