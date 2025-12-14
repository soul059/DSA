#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 Celebrity Problem (brief):
 - Given an n x n matrix mat where mat[i][j] == 1 means person i knows person j,
    find an index of a "celebrity": someone known by everyone else but who knows no one.
 - If no such person exists, return -1.

 Algorithm (short):
 - Use two-pointer elimination: maintain top and bottom indices.
    Compare mat[top][bottom]; if top knows bottom, top can't be celebrity -> top++;
    else bottom can't be celebrity -> bottom--.
    Continue until one candidate remains.
 - Verify candidate by checking their entire row is 0 (they know no one)
    and their entire column (except diagonal) is 1 (everyone knows them).
 - Time: O(n) for elimination + O(n) for verification = O(n).
 - Space: O(1) extra (excluding input matrix).
*/

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