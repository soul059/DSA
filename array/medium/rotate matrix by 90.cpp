/*
 * ROTATE MATRIX BY 90 DEGREES (Clockwise)
 * 
 * Approach: 1. Transpose the matrix (swap rows & columns)
 *           2. Reverse each row
 * 
 * Time: O(n²) | Space: O(1)
 * 
 * Anti-clockwise: Reverse each row first, then transpose
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

void rotateMatBy90(vector<vector<int>> &mat,int n){
    for(int i = 0;i<n-1;i++ ){
        for(int j =i+1; j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i =0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
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

    cout<<"before rotating"<<endl;
    for(int i=0; i<n; i++){
       for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
       }
       cout<<endl;
    }

    rotateMatBy90(mat,n);

    cout<<"after rotating"<<endl;
    for(int i=0; i<n; i++){
       for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
       }
       cout<<endl;
    }


    return 0;
}