#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

int longestSubArrayWithGivenSum(vector<int> &arr, int k){
    int sum = arr[0];
    int maxlen = 0;
    int left = 0 , right = 0;

    while (right < arr.size())
    {
        while (sum > k && left < right)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            int len = right - left + 1;
            maxlen = max(maxlen, len);
        }
        right++;
        if(right < arr.size()){sum += arr[right];}
        
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