#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * valid parenthesis str.cpp

 * Short algorithm comment:
 * - Maintain a range [minOpen, maxOpen] of possible unmatched '(' counts while scanning the string.
 * - For '(' : minOpen++, maxOpen++.
 * - For ')' : minOpen--, maxOpen--.
 * - For '*' : minOpen-- (as ')'), maxOpen++ (as '(') to represent its three possibilities.
 * - If maxOpen < 0 at any point => too many ')' => invalid.
 * - Clamp minOpen to 0 (cannot have negative opens).
 * - At end, string is valid iff minOpen == 0.
 
 * Complexity: O(n) time, O(1) extra space.
 */

bool isValidParenthesis(const string &s) {
    int min=0;
    int max=0;
    for(char c : s) {
        if(c == '(') {
            min++;
            max++;
        } else if(c == ')') {
            min--;
            max--;
        } else if(c == '*') {
            min--;   // Treat '*' as ')'
            max++;   // Treat '*' as '('
        }
        if(max < 0) {
            return false; // Too many ')'
        }
        if(min < 0) {
            min = 0; // Reset min to 0, as we can't have negative open parentheses
        }
    }
    return min == 0; // Valid if all open parentheses are matched
}

int main(){
    string s;
    cin>>s;
    if(isValidParenthesis(s)) {
        cout << "Valid Parenthesis String" << endl;
    } else {
        cout << "Invalid Parenthesis String" << endl;
    }
    return 0;
}