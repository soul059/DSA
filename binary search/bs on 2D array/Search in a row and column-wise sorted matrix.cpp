/*
 * Search in Row & Column-wise Sorted Matrix
 * Approach: Start from top-right corner; if current > target go left, if < target go down
 * Time: O(n + m) where n=rows, m=cols
 * Space: O(1)
 * Key: Top-right (or bottom-left) allows eliminating one row/column each step
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

pair<int , int> rowWithMax1s(vector<vector<int>> &matrix,int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return {row,col};
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return {-1,-1};
}

int main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0; i<n; i++){
       for(int j=0;j<m;j++){
            cin>>mat[i][j];
       }
    }

    pair<int,int> ans = rowWithMax1s(mat,t);
        
    cout << "index is:"<<ans.first<<","<<ans.second << endl;
    
    return 0;
}
