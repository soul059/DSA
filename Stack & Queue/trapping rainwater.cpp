#include<iostream>
#include<vector>
#include<algorithm>

using namespace  std;

/*
 * trapRainWaterBasic

 * Algorithm:
 * - Precompute for every position i:
 *     leftMax[i]  = maximum height among bars from index 0 to i (inclusive).
 *     rightMax[i] = maximum height among bars from index i to n-1 (inclusive).
 * - For each index i, the water that can be trapped above bar i equals
 *     min(leftMax[i], rightMax[i]) - height[i]
 *   (if this value is negative it contributes 0, but with the above precomputation it will be non-negative).
 * - Sum these values for all indices to get the total trapped water.

 * Complexity:
 * - Time:  O(n)   — one pass to build leftMax, one pass to build rightMax, one pass to accumulate result.
 * - Space: O(n)   — two auxiliary arrays of size n (leftMax and rightMax).
 *
 * Parameters:
 * - height: const vector<int>& containing heights of the bars (expected non-negative integers).
 *
 * Returns:
 * - int: total units of trapped rain water.

 * Notes:
 * - Returns 0 for empty input.
 * - This implementation is straightforward and easy to reason about, but uses extra linear space.
 */


int trapRainWaterBasic(const vector<int>& height) {
    int n = (int)height.size();
    if(n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for(int i = 1; i < n; ++i){
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for(int i = n - 2; i >= 0; --i){
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int totalWater = 0;
    for(int i = 0; i < n; ++i){
        totalWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return totalWater;
}


/*
 * trapRainWaterOptimized

 * Algorithm (two-pointer, constant-space):
 * - Use two pointers, left starting at 0 and right starting at n-1.
 * - Maintain leftMax = maximum height seen so far from the left side,
 *   and rightMax = maximum height seen so far from the right side.
 * - At each step, advance the pointer whose current height is smaller:
 *     - If height[left] <= height[right], then the water trapped at left is bounded
 *       by leftMax (since there exists a right boundary at least as high as height[right]),
 *       so:
 *         - if height[left] >= leftMax: update leftMax
 *         - else: add (leftMax - height[left]) to total water
 *       then increment left.
 *     - Otherwise (height[right] < height[left]), do the symmetric operation for right:
 *         - if height[right] >= rightMax: update rightMax
 *         - else: add (rightMax - height[right]) to total water
 *       then decrement right.
 * - Continue until left > right. This correctly accounts for trapped water using only
 *   the currently known maxima and the fact that the smaller side determines the fill level.

 * Complexity:
 * - Time:  O(n)   — single pass with both pointers moving inward.
 * - Space: O(1)   — only a few scalar variables are used.
 *
 * Parameters:
 * - height: const vector<int>& containing heights of the bars (expected non-negative integers).

 * Returns:
 * - int: total units of trapped rain water.

 * Notes:
 * - Returns 0 for empty input.
 * - This approach is preferred when minimizing extra memory usage is important.
 */

int trapRainWaterOptimized(const vector<int>& height) {
    int n = (int)height.size();
    if(n == 0) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= leftMax){
                leftMax = height[left];
            } else {
                totalWater += leftMax - height[left];
            }
            ++left;
        } else {
            if(height[right] >= rightMax){
                rightMax = height[right];
            } else {
                totalWater += rightMax - height[right];
            }
            --right;
        }
    }

    return totalWater;
}

int main(){
    
    return 0;
}