
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<vector>
using namespace  std;

/*
 * nextGreaterElement - short documentation

 * Purpose:
 *   Compute the Next Greater Element (NGE) for each element in a circular integer array.
 *   For each position i, return the first element > arr[i] found to the right (wrapping around);
 *   return -1 if no such element exists.

 * API:
 *   Input:  const vector<int>& arr
 *   Output: vector<int> result of same size, where result[i] is the NGE for arr[i] or -1.

 * Algorithm (brief):
 *   - Use a monotonic decreasing stack to keep candidate greater values.
 *   - Iterate indices from 2*n-1 down to 0 to simulate two passes (handles circularity).
 *   - idx = i % n. Pop while stack.top() <= arr[idx]. If i < n, set result[idx] = stack.empty() ? -1 : stack.top().
 *   - Push arr[idx] onto the stack.

 * Complexity:
 *   - Time: O(n) — each element is pushed and popped at most once.
 *   - Space: O(n) — for the result and the stack.

 * Notes:
 *   - Handles empty arrays gracefully (returns an empty vector).
 *   - Uses strict greater comparison; equal values are not considered greater.
 */

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = (int)arr.size();
    vector<int> result(n, -1);
    stack<int> s;
    for(int i = 2*n -1 ; i >=0; i--){
        int idx = i % n;
        while(!s.empty() && s.top() <= arr[idx]) s.pop();
        if(i < n) {
            result[idx] = s.empty() ? -1 : s.top();
        }
        s.push(arr[idx]);
    }
    return result;
}

int main(){
    int n;
    if(!(cin >> n)) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> result = nextGreaterElement(arr);
    for(int x : result) cout << x << " ";
    cout << "\n";
    if (result.empty()) cout << "No elements found.\n";
    else cout << "Next Greater Elements computed successfully.\n";
    return 0;
}