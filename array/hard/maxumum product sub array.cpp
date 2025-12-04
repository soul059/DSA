/*
 * MAXIMUM PRODUCT SUBARRAY
 * 
 * Approach: Track prefix and suffix products
 * Reset to 1 when product becomes 0
 * Answer is max of all prefix and suffix products
 * 
 * Time: O(n) | Space: O(1)
 * 
 * Why prefix & suffix? Handles negative numbers
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int maxProductSubarr(vector<int> arr,int n){
    int maxi = INT_MIN;
    int prefix =1;
    int suffix = 1;
    for(int i=0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        maxi = max(maxi,max(prefix,suffix));
    }

    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int res = maxProductSubarr(arr,n);
    cout<<"max product subarray's product is: "<<res<<endl;
    return 0;
}