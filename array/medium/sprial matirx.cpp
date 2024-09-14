#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

vector<int> spiralMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++;

        // Traverse downwards
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // Traverse upwards
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}


int main(){
    int n;
    cin>>n; // row
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0; i<n; i++){
       for(int j=0;j<n;j++){
            cin>>mat[i][j];
       }
    }

    for(int i=0; i<n; i++){
       for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
       }
       cout<<endl;
    }

    vector<int> res = spiralMatrix(mat);

    cout<<"after setting to Zero"<<endl;
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}