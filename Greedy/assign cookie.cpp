#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * Assign cookies to children to maximize the number of satisfied children.
 * Each child has a greed factor and each cookie has a size.
 * A child is satisfied if they receive a cookie with size >= their greed factor.
 *
 * Parameters:
 *  - g: vector of integers representing the greed factors of the children (const reference)
 *  - s: vector of integers representing the sizes of the cookies (const reference)
 *
 * Returns:
 *  - maximum number of satisfied children
 *
 * Complexity:
 *  - Time: O(n log n + m log m) due to sorting both arrays
 *  - Space: O(1) additional space
 */

int findMaxCookies(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int childIndex = 0, cookieIndex = 0;
    while(childIndex < g.size() && cookieIndex < s.size()){
        if(s[cookieIndex] >= g[childIndex]){
            childIndex++;
        }
        cookieIndex++;
    }
    return childIndex;
}

int main(){
    int n, m;
    cin >> n;   
    vector<int> g(n);
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }
    cin >> m;
    vector<int> s(m);
    for(int i = 0; i < m; i++){
        cin >> s[i];
    }   
    cout << findMaxCookies(g, s) << endl;   
    return 0;
}