/*
 * LONGEST SUBARRAY WITH SUM K - HashMap (Prefix Sum)
 * 
 * Works for both positive and negative numbers
 * Store prefix sum and its first occurrence index
 * If (prefixSum - k) exists, subarray found
 * 
 * Time: O(n) | Space: O(n)
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

int longestSubArrayWithGivenSum(vector<int> &arr, int k){
    unordered_map<int, int> mp;
    int sum = 0;
    int maxlen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if(sum == k){
            maxlen = max(maxlen,i+1);
        }
        int rem = sum - k;
        if(mp.find(rem) != mp.end()){ // if rem is avelable in map then do this {in not in map map.find() simpilay point to end of map which mean map.end()}
            int len = i -  mp[rem];
            maxlen = max (maxlen,len);
        }
        if(mp.find(sum) == mp.end()){mp[sum] = i; } // this will comapair if sum is present in map then it never be the {map.end() it will return last + 1 itrator mean if map has 3 elements then end will be 4 }
    }
    

    return maxlen;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    int res = longestSubArrayWithGivenSum(arr, k);

    cout<< "max length of sub array is: "<<res<<endl;

    
    return 0;
}