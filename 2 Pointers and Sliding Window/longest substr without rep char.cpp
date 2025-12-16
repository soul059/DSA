#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace  std;

// Returns length of longest substring without repeating characters.
// Sliding window: expand `right` and insert new chars into `charSet`.
// On duplicate, shrink window from `left` by erasing chars until duplicate removed.
// Update maxLength when window expands.
// Time: O(n). Space: O(min(n, charset_size)).
int maxLengthSubstring(string s) {
    int left = 0, right = 0;
    int maxLength = 0;
    unordered_set<char> charSet;
    while (right < s.length()) {
        if (charSet.find(s[right]) == charSet.end()) {
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        } else {
            charSet.erase(s[left]);
            left++;
        }
    }
    
    return maxLength;
}

int main(){
    string s;
    cin >> s;
    cout << maxLengthSubstring(s) << endl;
    return 0;
}