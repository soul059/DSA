#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * minRemoveIntervals - Greedy algorithm to find the minimum number of intervals to remove
 * to make the rest of the intervals non-overlapping.

 * Description:
 *   Sorts intervals by their end times. Iterates through the sorted intervals,
 *   counting how many intervals overlap with the last added non-overlapping interval.
 *   Each overlapping interval is counted for removal.

 * Parameters:
 *   intervals - vector of pairs representing the intervals (start, end)

 * Return:
 *   Minimum number of intervals to remove to eliminate all overlaps.

 * Complexity:
 *   Time: O(n log n) due to sorting
 *   Space: O(1) extra space

 * Preconditions / Notes:
 *   - Intervals are represented as pairs of integers.
 *   - Uses greedy choice proven optimal for interval scheduling problems.
 */

int minRemoveIntervals(vector<pair<int, int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.second < b.second;
         });
    
    int count = 0;
    int lastEnd = INT_MIN;
    
    for (const auto &interval : intervals) {
        if (interval.first >= lastEnd) {
            lastEnd = interval.second;
        } else {
            count++;
        }
    }
    
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> intervals(n);
    for(int i=0;i<n;i++){
        cin>>intervals[i].first>>intervals[i].second;
    }
    cout << minRemoveIntervals(intervals) << endl;
    return 0;
}