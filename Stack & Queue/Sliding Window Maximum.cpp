#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace  std;

/*
 * maxSlidingWindow(const vector<int>& nums, int k)

 * Computes the maximum value in each sliding window of size k over the input array.

 * Parameters:
 *  - nums: input vector of integers
 *  - k: window size (must be > 0)

 * Returns:
 *  - vector<int> containing the maximum for each window; length is max(0, nums.size() - k + 1)

 * Brief algorithm explanation:
 *  - Maintain a deque of indices whose corresponding values are in decreasing order.
 *  - For each index i:
 *      - Remove the front index if it is out of the current window (i - k).
 *      - Remove indices from the back while their values are less than nums[i] (they cannot be maxima).
 *      - Push the current index to the back.
 *      - Once i >= k - 1, the front of the deque is the index of the current window's maximum.

 * Complexity:
 *  - Time: O(n) — each index is pushed and popped at most once.
 *  - Space: O(k) for the deque (plus output storage).

 * Edge cases:
 *  - If nums is empty or k <= 0, the function returns an empty vector.
 */

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        // Remove elements smaller than the current element from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        // The front of the deque is the largest element for the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> result = maxSlidingWindow(nums, k);
    for(int maxVal : result){
        cout << maxVal << " ";
    }
    cout << endl;
    return 0;
}