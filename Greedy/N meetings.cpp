#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * @brief N Meetings in one room to maximize the number of meetings.

 * Greedy algorithm that sorts meetings by their finish times and selects the maximum number of non-overlapping meetings.
 * 
 * @param start Vector of start times of meetings.
 * @param end Vector of end times of meetings.
 * @param n Number of meetings.
 * @return Maximum number of non-overlapping meetings that can be scheduled.

 * Complexity: O(n log n) time due to sorting, O(1) space.
 */

bool compareMeetings(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second; // Sort by finish time in ascending order
}

int maxMeetings(vector<int>& start, vector<int>& end, int n) {
    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; i++) {
        meetings[i] = {start[i], end[i]};
    }

    // Sort meetings by finish time
    sort(meetings.begin(), meetings.end(), compareMeetings);

    int count = 1; // At least one meeting can be scheduled
    int lastEndTime = meetings[0].second;

    for (int i = 1; i < n; i++) {
        if (meetings[i].first > lastEndTime) {
            count++;
            lastEndTime = meetings[i].second;
        }
    }

    return count;
}

int main(){
    
    return 0;
}