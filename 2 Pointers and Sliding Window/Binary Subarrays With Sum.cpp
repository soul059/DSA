#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * Count subarrays with sum equal to `goal` using a two-pointer sliding-window trick.
 * Computes atMost(g) = number of subarrays with sum <= g, then returns
 * atMost(goal) - atMost(goal - 1).
 * Assumes `nums` is a binary array (0/1). Runs in O(n) time and O(1) extra space.
 * Parameters:
 *   - nums: const vector<int>&, input array
 *   - goal: int, target sum
 * Returns:
 *   - int: number of subarrays whose sum equals goal
 */

int binarySubarraysWithSum(const vector<int>& nums, int goal) {
    auto atMost = [&](int g) {
        int left = 0, count = 0;
        for(int right = 0; right < int(nums.size()); ++right) {
            g -= nums[right];
            while(g < 0) {
                g += nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    };

    if (goal < 0) {
        return 0;
    } else if (goal == 0) {
        return atMost(0);
    }
    return atMost(goal) - atMost(goal - 1);
}

int main(){
    int n, goal;
    cin >> n >> goal;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << binarySubarraysWithSum(nums, goal) << endl;
    return 0;
}