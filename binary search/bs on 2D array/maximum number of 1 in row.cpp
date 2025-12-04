/*
 * Row with Maximum 1s in Binary Matrix
 * Approach: For each row, use lower bound to find first 1, count 1s = m - index
 *           Track row with maximum count of 1s
 * Time: O(n * log m) where n=rows, m=cols
 * Space: O(1)
 * Key: Binary search on each row since rows are sorted (0s before 1s)
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
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

    int ans = rowWithMax1s(mat,n,m);
        
    cout << "index is:"<<ans << endl;
    
    return 0;
}