#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int findCelebrity(vector<vector<int>>& mat, int n){
    int top = 0;
    int bottom = n - 1;
    while(top < bottom){
        if(mat[top][bottom] == 1){
            top++;
        } else {
            bottom--;
        }
    }
    int candidate = top;
    for(int i = 0; i < n; i++){
        if(i != candidate){
            if(mat[candidate][i] == 1 || mat[i][candidate] == 0){
                return -1;
            }
        }
    }
    return candidate;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    int celeb = findCelebrity(mat, n);
    cout << celeb << endl;
    return 0;
}