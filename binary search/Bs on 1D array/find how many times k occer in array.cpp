/*
 * COUNT OCCURRENCES OF K IN SORTED ARRAY
 * 
 * Count = upper_bound(k) - lower_bound(k)
 * 
 * Time: O(log n) | Space: O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int lowerBound(vector<int> arr,int x){
    int low =0,high=arr.size()-1;
    int ans = arr.size();
    while (low <=high){
        int mid = (low + high) / 2;
        if(arr[mid] >= x ){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
    
} 

int upperBound(vector<int> arr,int x){
    int low =0,high=arr.size()-1;
    int ans = arr.size();
    while (low <=high){
        int mid = (low + high) / 2;
        if(arr[mid] > x ){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
    
} 

int firstAndLast(vector<int> arr,int x){
    int lb = lowerBound(arr,x);
    if(lb == arr.size() && arr[lb] != x) return -1;
    return (upperBound(arr,x) -1 )-lb+1;
}

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>x;

    int ans = firstAndLast(arr,x);
    cout<<"occ of k in array is: "<<ans<<endl;
    return 0;
}