#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * insert intervals

 * Short algorithm:
 * - Given a list of non-overlapping sorted intervals and a new interval,
 *   insert the new interval into the list and merge if necessary.
 * - Steps:
 *   1. Add all intervals ending before the new interval starts.
 *   2. Merge all overlapping intervals with the new interval.
 *   3. Add remaining intervals starting after the new interval ends.

 * Parameters:
 * - intervals: vector<vector<int>> of existing non-overlapping sorted intervals
 * - newInterval: vector<int> representing the new interval to insert

 * Returns:
 * - vector<vector<int>>: updated list of merged intervals

 * Complexity:
 * - Time: O(n) where n is the number of existing intervals
 * - Space: O(n) for the result list
 */

vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();
    
    // Add all intervals ending before newInterval starts
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }
    
    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    // Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i=0;i<n;i++) cin>>intervals[i][0]>>intervals[i][1];
    vector<int> newInterval(2);
    cin>>newInterval[0]>>newInterval[1];
    vector<vector<int>> merged = insertInterval(intervals, newInterval);
    for(const auto &interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}