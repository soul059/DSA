/*
 * PASCAL'S TRIANGLE
 * 
 * Each element = C(row, col) = prev * (row-col) / col
 * 
 * Row generation: Start with 1, multiply and divide
 * 
 * Time: O(n²) | Space: O(n²)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

vector<int> genertaeRow(int row){
    vector<int> ans;
    int as = 1;
    ans.push_back(1);
    for(int col = 1;col<row;col++){
        as = as*(row-col);
        as = as/col;
        ans.push_back(as);
    }
    return ans;
}

vector<vector<int>> pascalTri(int n){
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++)
    {
        res.push_back(genertaeRow(i));
    }

    return res;
    
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> res = pascalTri(n);

    for(int i=0; i<n; i++){
       for(int j=0;j<=i;j++){
            cout<<res[i][j]<<" ";
       }
       cout<<endl;
    }
    return 0;
}