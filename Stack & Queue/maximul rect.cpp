#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace  std;

/*
 * @file maximul rect.cpp
 * @brief Finds the maximum rectangular area containing only 1s in a binary matrix

 * Algorithm Overview:
 * 1. maxAreaRectHistogram: Uses stack-based approach to find largest rectangle in histogram
 *    - Maintains monotonic increasing stack of indices
 *    - For each bar, calculates area with that bar as the smallest height
 *    - Time: O(n), Space: O(n)

 * 2. maxAreaRectMatrix: Converts 2D problem to multiple 1D histogram problems
 *    - Treats each row as base of histogram
 *    - Heights accumulate for consecutive 1s vertically, reset to 0 on encountering 0
 *    - Calls histogram function for each row and tracks max area
 *    - Time: O(rows * cols), Space: O(cols)

 * Example: For matrix [[1,0,1],[1,1,1]], row 1 heights = [2,1,2], max rect = 3
 */

int maxAreaRectHistogram(const vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int max_area = 0;
    for(int i = 0; i <= n; i++){
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
            int cur = st.top();
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            int area = heights[cur] * width;
            max_area = max(max_area, area);
        }
        st.push(i);
    }
    return max_area;
}

int maxAreaRectMatrix(const vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int max_area = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == 0){
                heights[j] = 0;
            } else {
                heights[j] += 1;
            }
        }
        int area = maxAreaRectHistogram(heights);
        max_area = max(max_area, area);
    }
    
    return max_area;
}

int main(){
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }
    int result = maxAreaRectMatrix(matrix);
    cout << result << endl;
    return 0;
}