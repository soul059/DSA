#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace  std;

/*
 * Calculate the largest rectangle area in a histogram.
 
 * Function: largestRect(const vector<int>& arr)
 * ------------------------------------------------
 * Uses a monotonic increasing stack of indices to compute the maximum rectangular
 * area that can be formed under the histogram defined by arr.

 * Key idea:
 * - Maintain indices of bars with strictly increasing heights on the stack.
 * - When a lower height (or sentinel at i==n) is encountered, pop the top index,
 *   compute the area using that bar as the limiting height:
 *     width = (stack.empty() ? i : i - stack.top() - 1)
 *     area  = height[top] * width
 * - Update max area while popping; push current index afterwards.

 * Complexity:
 * - Time: O(n) — each index is pushed and popped at most once.
 * - Space: O(n) — stack of indices in worst case.

 * Parameters:
 * - arr: vector<int> of nonnegative bar heights (histogram).
 *
 * Returns:
 * - int: maximum rectangular area found.

 * Notes:
 * - The implementation uses i == n as a sentinel to flush the stack.
 * - The main function reads n and arr from stdin and prints the result.
 */

int largestRect(const vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    int max_area = 0;
    for(int i = 0; i <= n; i++){
        while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
            int cur = st.top();
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            int area = arr[cur] * width;
            max_area = max(max_area, area);
        }
        st.push(i);
    }

    return max_area;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_area = largestRect(arr);

    cout<<max_area;

    return 0;
}