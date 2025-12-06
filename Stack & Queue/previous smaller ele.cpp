
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<vector>
using namespace  std;

/*
 * previous smaller element (monotonic stack) - short documentation

 * Purpose:
 *  Compute for each element in an input array the nearest strictly smaller
 *  element to its left. If no such element exists, -1 is returned for that position.

 * Interface:
 *  vector<int> privousSmallerElement(const vector<int>& arr)
 *    - Input: arr (vector<int>) of length n
 *    - Output: vector<int> of length n where output[i] is the previous
 *      strictly smaller element for arr[i], or -1 if none.

 * Algorithm:
 *  Single pass left-to-right using a monotonic increasing stack of values.
 *  For each arr[i], pop stack while top >= arr[i]; if stack non-empty,
 *  top is the previous smaller element; then push arr[i].

 * Complexity:
 *  Time: O(n) (each element pushed/popped at most once)
 *  Space: O(n) worst-case for the stack and output vector

 * Behavior / Notes:
 *  - Strictly smaller semantics: equal values are not considered smaller.
 *  - Empty input yields an empty output vector.
 *  - Example: arr = [4, 2, 5, 3] -> result = [-1, -1, 2, 2]

 */

vector<int> privousSmallerElement(const vector<int>& arr) {
    int n = (int)arr.size();
    vector<int> result(n, -1);
    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top() >= arr[i]) s.pop();
        if(!s.empty()) {
            result[i] = s.top();
        }
        s.push(arr[i]);
    }
    return result;
}

int main(){
    int n;
    if(!(cin >> n)) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> result = privousSmallerElement(arr);
    for(int x : result) cout << x << " ";
    cout << "\n";
    if (result.empty()) cout << "No elements found.\n";
    else cout << "Previous Smaller Elements computed successfully.\n";
    return 0;
}