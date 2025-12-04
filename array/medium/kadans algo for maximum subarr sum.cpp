/*
 * KADANE'S ALGORITHM - Maximum Subarray Sum
 * 
 * Approach: Track current sum, reset if negative
 * Update max whenever current sum exceeds it
 * 
 * Time: O(n) | Space: O(1)
 * 
 * Also tracks start and end indices of max subarray
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

vector<int> kadansAlgo(vector<int> arr,int n){
    int sum = 0;
    int maxi = INT_MIN;
    int ansstart = -1, ansend = -1;
    int start;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0 )
        {
            start = i;
        }
        
        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            ansstart = start;
            ansend = i;
        }
        

        if (sum < 0)
        {
            sum =0;
        }    
    }

    vector<int> res;
    for (int i = ansstart; i <= ansend; i++)
    {
        res.push_back(arr[i]);
    }
    
     return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<int> res = kadansAlgo(arr,n);
    cout<<"maximum sum sub array is: ";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}