#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace  std;

/*
File: sum of subarr min.cpp
Purpose:
- Compute sum of minimums of all subarrays of a given array modulo 1e9+7.

High-level approach (short form):
- Use monotonic stacks to compute for every index i:
    - next smaller element index to the right (strictly smaller)
    - previous smaller-or-equal element index to the left
  This asymmetric tie-handling (>= on right, > on left) ensures each subarray's minimum
  is attributed to exactly one index when duplicates exist.

- Contribution technique:
    - For element arr[i], let:
        left  = number of choices for subarray start so that arr[i] is minimum = i - prev[i]  (or i+1 if prev = -1)
        right = number of choices for subarray end   so that arr[i] is minimum = next[i] - i      (or n-i if next = -1)
    - Number of subarrays where arr[i] is the minimum = left * right
    - Add arr[i] * left * right to global sum (apply modulo at each step).

Functions:
- nse(arr): returns vector next where next[i] = index of next strictly smaller element to the right or -1 if none.
  Implementation: iterate i from n-1..0, maintain increasing stack of indices; pop while arr[stack.top] >= arr[i].

- psee(arr): returns vector prev where prev[i] = index of previous smaller-or-equal element to the left or -1 if none.
  Implementation: iterate i from 0..n-1, maintain increasing stack but pop while arr[stack.top] > arr[i] (preserve equals).

Complexity:
- Time: O(n) — each element pushed/popped at most once per stack pass.
- Space: O(n) — for stacks and result arrays.

Numeric considerations:
- Use 64-bit type for intermediate multiplications (arr[i] * left * right) to avoid overflow.
- Apply modulo = 1e9+7 on additions/multiplications.

Edge cases:
- Empty input handled by early exit in main.
- Works with duplicate values due to asymmetric comparator choice.
*/

vector<int> nse(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    vector<int> res(n);
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return res;
}

vector<int> psee(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[s.top()] > arr[i]) s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return res;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> next = nse(arr);
    vector<int> prev = psee(arr);
    long long mod = 1e9 + 7;
    long long res = 0;
    for(int i = 0; i < n; i++){
        long long left = (prev[i] == -1) ? (i + 1) : (i - prev[i]);
        long long right = (next[i] == -1) ? (n - i) : (next[i] - i);
        res = (res + (arr[i] * left * right) % mod) % mod;
    }
    return (int)res;
}

int main(){
    int n;
    if(!(cin >> n)) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << sumSubarrayMins(arr) << "\n";
    return 0;
}