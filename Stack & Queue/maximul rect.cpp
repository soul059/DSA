#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace  std;

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