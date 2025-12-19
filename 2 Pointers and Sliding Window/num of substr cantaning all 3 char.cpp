#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

// Count substrings containing all three characters 'a','b','c'.
// lastIndex[0..2] stores latest indices for 'a','b','c' respectively.
// For each position i, minLastIndex = earliest of the three latest positions.
// All substrings ending at i that start at 0..minLastIndex contain all three -> add minLastIndex+1.
// Time: O(n), Space: O(1)

int numberOfSubstrContainingAll3Chars(const string& s) {
    int lastIndex[3] = {-1, -1, -1};
    int totalSubstr = 0;
    
    for(int i = 0; i < int(s.size()); i++){
        lastIndex[s[i] - 'a'] = i;
        int minLastIndex = min({lastIndex[0], lastIndex[1], lastIndex[2]});
        if(minLastIndex != -1){
            totalSubstr += minLastIndex + 1;
        }
    }
    return totalSubstr;
}

int main(){
    string s;
    cin >> s;
    cout << numberOfSubstrContainingAll3Chars(s) << endl;
    return 0;
}