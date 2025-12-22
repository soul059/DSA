#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace  std;

/*
 * Count subarrays with exactly k distinct integers.

 * Uses the "at most K" trick: number of subarrays with exactly K distinct
 * = atMost(K) - atMost(K-1). atMost(maxDistinct) is computed via a
 * sliding-window two-pointer approach with an unordered_map to track counts.

 * Parameters:
 *  - nums: input array of integers (const reference)
 *  - k: desired number of distinct integers in subarrays

 * Returns:
 *  - number of subarrays that contain exactly k distinct integers

 * Complexity:
 *  - Time: O(n) average (each element enters/exits window once)
 *  - Space: O(min(n, U)) for the hashmap where U is number of unique values
 */

int subarraysWithKDistinct(const vector<int>& nums, int k) {
    auto atMost = [&](int maxDistinct) {
        int left = 0, subarrayCount = 0;
        int distinctCount = 0;
        unordered_map<int, int> count;
        
        for(int right = 0; right < int(nums.size()); ++right) {
            if(count[nums[right]] == 0) {
                distinctCount++;
            }
            count[nums[right]]++;
            
            while(distinctCount > maxDistinct) {
                count[nums[left]]--;
                if(count[nums[left]] == 0) {
                    distinctCount--;
                }
                left++;
            }
            subarrayCount += right - left + 1;
        }
        return subarrayCount;
    };
    
    if (k < 0) {
        return 0;
    } else if (k == 0) {
        return atMost(0);
    }
    return atMost(k) - atMost(k - 1);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << subarraysWithKDistinct(nums, k) << endl;
    return 0;
}