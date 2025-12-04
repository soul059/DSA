/*
 * FIRST AND LAST OCCURRENCE OF X
 * 
 * Approach: Use lower_bound and upper_bound
 * - First occurrence = lower_bound(x)
 * - Last occurrence = upper_bound(x) - 1
 * 
 * Time: O(log n) | Space: O(1)
 * 
 * Count of x = last - first + 1
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

pair<int,int> firstAndLast(vector<int> arr,int x){
    int lb = lowerBound(arr,x);
    if(lb == arr.size() || arr[lb] != x) return {-1,-1};
    return {lb,upperBound(arr,x) -1};
}

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>x;

    pair<int,int> ans = firstAndLast(arr,x);
    cout<<"First occ at index: "<<ans.first<<"\t\t Last occ at index: "<<ans.second<<endl;
    return 0;
}