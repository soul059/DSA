/*
 * @brief Compute the length of the longest substring containing at most k distinct characters.
 *
 * Uses a sliding-window approach: expand the right pointer and count characters with an unordered_map;
 * when the number of distinct characters exceeds k, increment the left pointer and decrement counts
 * (erasing entries with zero count) until at most k distinct remain.
 
 * @param s Input string.
 * @param k Maximum number of distinct characters allowed in the substring.
 * @return Length of the longest substring with at most k distinct characters.
 
 * @complexity Time: O(n), Space: O(min(n, alphabet_size))
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace  std;



int longestSubstrWithKDistinctChars(const string& s, int k) {
    int left = 0, right = 0;
    int maxLength = 0;
    unordered_map<char, int> charCount;
    
    while(right < int(s.size())){
        charCount[s[right]]++;
        
        if(int(charCount.size()) > k){
            charCount[s[left]]--;
            if(charCount[s[left]] == 0){
                charCount.erase(s[left]);
            }
            left++;
        }

        if(int(charCount.size()) <= k) maxLength = max(maxLength, right - left + 1);
        right++;
    }
    
    return maxLength;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    cout << longestSubstrWithKDistinctChars(s, k) << endl;
    return 0;
}