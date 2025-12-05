
/*
File: next greater ele.cpp
Purpose:
    Compute the Next Greater Element (NGE) for each element of an integer array.
    For every index i, the NGE is the first element to the right of arr[i] that is strictly greater than arr[i].
    If no such element exists, the NGE is -1.

Algorithm (monotonic stack, short):
    - Traverse the array from right to left.
    - Maintain a stack that stores candidate next-greater values in strictly decreasing order (top is the smallest candidate > current).
    - For current element x = arr[i]:
        * Pop elements from the stack while stack.top() <= x (they cannot be NGE for x or any element to the left of x).
        * If stack is empty after popping, NGE for x is -1; otherwise NGE is stack.top().
        * Push x onto the stack as a future candidate for elements to the left.
    - This produces the NGE for every position in one pass.

Complexity:
    - Time: O(n) amortized — each element is pushed and popped at most once.
    - Space: O(n) worst-case for the stack and O(n) for the returned result array.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace  std;



vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = (int)arr.size();
    vector<int> result(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= arr[i]) s.pop();
        result[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return result;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> result = nextGreaterElement(arr);
    for (int x : result) cout << x << " ";
    cout << "\n";
    return 0;
}
