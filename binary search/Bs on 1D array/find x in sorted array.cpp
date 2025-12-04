/*
 * BINARY SEARCH - Find X in Sorted Array
 * 
 * Approach: Divide search space in half each iteration
 * - If arr[mid] == x: found
 * - If arr[mid] > x: search left half
 * - If arr[mid] < x: search right half
 * 
 * Time: O(log n) | Space: O(1) iterative, O(log n) recursive
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int binarySearch(vector<int> arr,int low,int high,int x){
    if(low > high) return -1;
    int mid = (low + high) / 2;

    if(arr[mid] == x) return mid;
    else if(arr[mid] > x) return binarySearch(arr,low,mid-1,x);

    return binarySearch(arr,mid+1,high,x);
} 

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>x;

    int ans = binarySearch(arr,0,n-1,x);
    cout<<"Element at index: "<<ans;

    return 0;
}