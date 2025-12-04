/*
 * Median of Row-wise Sorted Matrix
 * Approach: Binary search on answer range [min, max]; for each mid count elements <= mid
 *           using upper bound on each row; median has exactly (n*m)/2 elements smaller
 * Time: O(n * log(max-min) * log m)
 * Space: O(1)
 * Key: Binary search on value space, not index; count elements to find median position
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;


int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
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

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
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

    int ans = median(mat,n,m);
        
    cout << "median is:"<<ans << endl;
    
    return 0;
}