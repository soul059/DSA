#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace  std;

int maxele(vector<vector<int>> mat, int n, int mid) {
    int max = INT_MIN;
    int rowIndex = 0;
    for (int i = 0; i < n; i++) {
        if (mat[i][mid] > max) {
            max = mat[i][mid];
            rowIndex = i;
        }
    }
    return rowIndex;
}
pair<int , int> findPeak(vector<vector<int>> &matrix, int n, int m) {
    int low =0,high = m-1;
    while (low<=high)
    {
        int mid = (low+high) /2;
        int row = maxele(matrix,n,mid); 
        int left = mid-1 >= 0 ? matrix[row][mid - 1] : -1;
        int right = mid+1 <m ? matrix[row][mid+1]:-1;

        if(matrix[row][mid] > left && matrix[row][mid] > right){
            return {row,mid};
        }
        else if(matrix[row][mid] < left) high = mid-1;
        else low = mid+1;
        
    }
    return {-1,-1};
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0; i<n; i++){
       for(int j=0;j<m;j++){
            cin>>mat[i][j];
       }
    }
    pair<int,int> ans = findPeak(mat,n,m);
        
    cout << "index is:"<<ans.first<<","<<ans.second << endl;
    
    return 0;
}