#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

pair<int , int> rowWithMax1s(vector<vector<int>> &matrix, int n, int m,int targate) {
    int low =0,high = n*m-1;
    while (low<=high)
    {
        int mid = (low+high) /2;
        int row = mid/m;
        int col = mid%m;
        if(matrix[row][col] == targate){
            return {row,col};
        }
        else if (matrix[row][col] < targate)
        {
            low = mid+1;
        }
        else {high = mid-1;}
        
    }
    return {-1,-1};
}

int main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0; i<m; i++){
       for(int j=0;j<n;j++){
            cin>>mat[i][j];
       }
    }

    pair<int,int> ans = rowWithMax1s(mat,n,m,t);
        
    cout << "index is:"<<ans.first<<","<<ans.second << endl;
    
    return 0;
}