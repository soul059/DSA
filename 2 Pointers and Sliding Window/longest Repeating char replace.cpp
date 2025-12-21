#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace  std;

/*
 * Compute the length of the longest substring that can be converted to a
 * repeating-character string by replacing at most k characters.

 * Uses a sliding-window approach: maintain character counts in the window,
 * track the count of the most frequent character (maxCount). If the number
 * of characters that must be replaced (window_size - maxCount) exceeds k,
 * advance the left boundary. Update the maximum window length seen.

 * Parameters:
 *  - s: input string
 *  - k: maximum allowed replacements

 * Returns:
 *  - length of the longest valid substring
 *
 * Time Complexity: O(n) average, Space Complexity: O(1) (bounded alphabet)
 */

int longestRepeatingCharReplace(const string& s, int k) {
    unordered_map<char, int> charCount;
    int left = 0, maxCount = 0, maxLength = 0;
    int right = 0;
    while(right < int(s.size())) {
        charCount[s[right]]++;
        maxCount = max(maxCount, charCount[s[right]]);
        
        if((right - left + 1) - maxCount > k) {
            charCount[s[left]]--;
            
            left++;
        }
        
        if((right - left + 1) - maxCount <= k) maxLength = max(maxLength, right - left + 1);
        right++;
    }
    
    return maxLength;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    cout << longestRepeatingCharReplace(s, k) << endl;
    return 0;
}