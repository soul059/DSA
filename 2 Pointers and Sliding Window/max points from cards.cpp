#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
Brief:
- Computes the maximum sum obtainable by taking exactly k cards from
    either the start or the end of a linear array of card values.
- Uses a two-end sliding window approach: initialize sum of first k
    elements, then iteratively replace one taken-from-left card with one
    taken-from-right card and track the maximum.

Functions:
- int maxPoints(vector<int>& cards, int k)
    - Purpose: Return the maximum sum by taking k cards from the two ends.
    - Parameters:
        - cards: vector<int> of card values.
        - k: number of cards to take (0 <= k <= cards.size()).
    - Returns: maximum achievable sum (int).
    - Complexity: O(n) time, O(1) extra space.
    - Notes: Assumes k is within valid range. Handles k == 0 and k == n.

Edge cases:
- k == 0 -> result 0.
- k == n -> sum of all elements.
- Negative values supported (algorithm is value-agnostic).
*/

int maxPoints(vector<int>& cards, int k) {
    int n = cards.size();
    int leftSum = 0;
    for (int i = 0; i < k; ++i) {
        leftSum += cards[i];
    }
    int maxPoints = leftSum;
    int rightSum = 0;
    for (int i = 0; i < k; ++i) {
        rightSum += cards[n - 1 - i];
        leftSum -= cards[k - 1 - i];
        maxPoints = max(maxPoints, leftSum + rightSum);
    }
    return maxPoints;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }
    cout << maxPoints(cards, k) << endl; 
    return 0;
}