#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
Greedy algorithm for Jump Game I:
- Maintain maxReach: the farthest index reachable so far.
- Iterate indices i from 0 to n-1:
    - If i > maxReach, index i is unreachable -> the last index cannot be reached (return false).
    - Otherwise update maxReach = max(maxReach, i + nums[i]).
- If the loop finishes, the last index is reachable -> return true.

Complexity:
- Time: O(n) — single pass through the array.
- Space: O(1) — constant extra space.
*/

bool jumpGame1(vector<int>& nums){
    int n = nums.size();
    int maxReach = 0;

    for(int i = 0; i < n; i++){
        if(i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }

    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << (jumpGame1(nums) ? "true" : "false") << endl;
    return 0;
}