#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

// Sliding window approach:
// Expand right pointer and count zeros seen in the window.
// If zeroCount exceeds k, move left pointer rightwards until zeroCount <= k,
// decrementing zeroCount when a zero leaves the window.
// At each step (when zeroCount <= k) update maxLength with current window size.
// Time complexity: O(n), Space complexity: O(1).

int maxConsecutiveOnesIII(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int maxLength = 0;
    int zeroCount = 0;
    while(right < int(nums.size())){
        if(nums[right] == 0) zeroCount++;
        if(zeroCount > k){
            if(nums[left] == 0) zeroCount--;
            left++;
        } 
        if(zeroCount <= k){
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
    }
    
    return maxLength;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << maxConsecutiveOnesIII(nums, k) << endl;
    return 0;
}