
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * maxCandiesApproach1

 * Short algorithm:
 * - Greedy two-pass solution.
 * - Initialize all children with 1 candy.
 * - Left-to-right pass: if rating[i] > rating[i-1], set candies[i] = candies[i-1] + 1.
 * - Right-to-left pass: if rating[i] > rating[i+1], set candies[i] = max(candies[i], candies[i+1] + 1).
 * - Sum candies to get the minimum total satisfying both neighbors constraints.

 * Parameters:
 * - childRatings: vector<int> of length n containing ratings for each child.

 * Returns:
 * - int: minimum total number of candies required.

 * Complexity:
 * - Time: O(n)
 * - Space: O(n) (for the candies array)
 */
int maxCandiesApproach1(vector<int> childRatings) {
    int n = childRatings.size();
    vector<int> candies(n, 1);
    for(int i = 1; i < n; i++) {
        if(childRatings[i] > childRatings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        if(childRatings[i] > childRatings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    int totalCandies = 0;
    for(int c : candies) {
        totalCandies += c;
    }
    return totalCandies;

}

 
/*
 * maxCandiesApproach2

 * Short algorithm:
 * - One-pass greedy using slope tracking (up / down / peak).
 * - Traverse ratings once, count lengths of increasing (up) and decreasing (down) sequences.
 * - For an increase, increment up and add appropriate candies.
 * - For a decrease, increment down and add; if peak length >= down, adjust to avoid double-counting the peak.
 * - On equal ratings, reset counters and give 1 candy.
 * - Produces the same minimal total using O(1) extra space.

 * Parameters:
 * - childRatings: vector<int> of length n containing ratings for each child.

 * Returns:
 * - int: minimum total number of candies required.

 * Complexity:
 * - Time: O(n)
 * - Space: O(1)
 */

int maxCandiesApproach2(vector<int> childRatings) {
    int n = childRatings.size();
    if(n == 0) return 0;
    int totalCandies = 1;
    int up = 0, down = 0, peak = 0;
    for(int i = 1; i < n; i++) {
        if(childRatings[i] > childRatings[i - 1]) {
            up++;
            peak = up;
            down = 0;
            totalCandies += 1 + up;
        } else if(childRatings[i] < childRatings[i - 1]) {
            up = 0;
            down++;
            totalCandies += 1 + down;
            if(peak >= down) {
                totalCandies -= 1;
            }
        } else {
            up = down = peak = 0;
            totalCandies += 1;
        }
    }
    return totalCandies;
}

int main(){
    int n;
    cin>>n;
    vector<int> ratings(n);
    for(int i=0;i<n;i++) cin>>ratings[i];
    cout << maxCandiesApproach1(ratings) << endl;
    cout << maxCandiesApproach2(ratings) << endl;
    return 0;
}