#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace  std;

/*
 * Find the length of the minimum window substring in s that contains all characters of t.

 * Uses a sliding-window two-pointer approach with an unordered_map to track character counts.

 * Parameters:
 *  - s: input string where we search for the window (const reference)
 *  - t: target string containing characters to be included in the window (const reference)

 * Returns:
 *  - length of the minimum window substring containing all characters of t, or -1 if no such window exists

 * Complexity:
 *  - Time: O(n) average (each character enters/exits window once)
 *  - Space: O(m) for the hashmap where m is the number of unique characters in t
 */

int minWindowSubstring(const string& s, const string& t) {
    unordered_map<char, int> targetCount;
    for (char c : t) {
        targetCount[c]++;
    }

    int need = targetCount.size();
    int left = 0, minLength = INT_MAX, minStart = 0, right = 0;    
    while(right < s.size()) {
        char c = s[right];
        if(targetCount.find(c) != targetCount.end()) {
            targetCount[c]--;
            if(targetCount[c] == 0) {
                need--;
            }
        }
        while(need == 0) {
            if(right - left + 1 < minLength) {
                minLength = min(minLength, right - left + 1);
                minStart = left;
            }
            char leftChar = s[left];
            if(targetCount.find(leftChar) != targetCount.end()) {
                targetCount[leftChar]++;
                if(targetCount[leftChar] > 0) {
                    need++;
                }
            }
            left++;
        }
        right++;
    }

    return minLength == INT_MAX ? -1 : minLength;
}

int main(){
    string s, t;
    cin >> s >> t;
    int result = minWindowSubstring(s, t);
    cout << result << endl;
    return 0;
}