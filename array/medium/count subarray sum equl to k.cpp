/*
 * COUNT SUBARRAYS WITH SUM EQUAL TO K
 * 
 * Approach: Prefix Sum + HashMap
 * If prefixSum - k exists in map, those many subarrays end here
 * 
 * Time: O(n) | Space: O(n)
 * 
 * Note: Initialize map[0] = 1 for subarrays starting from index 0
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace  std;

int countSubEqulK(vector<int> arr,int k){
    map<int,int> mpp;
    mpp[0] = 1; // this is need in case of x - k = 0; 
    int n = arr.size();
    int presum = 0, ctn =0;
    for(int i =0;i<n;i++){
        presum += arr[i];
        int remove = presum - k;
        ctn += mpp[remove];
        mpp[presum]+=1;
    } 
    return ctn;
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int res = countSubEqulK(arr,k);

    cout<<"count of subarray equals to k in this array is: "<<res<<endl;
  
    return 0;
}