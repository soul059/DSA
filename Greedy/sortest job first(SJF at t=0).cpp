/*
Short description:
    Compute average waiting time under Shortest Job First (SJF) scheduling
    assuming all jobs arrive at time 0.

Behavior:
    - Sorts job durations in non-decreasing order.
    - Accumulates waiting time as the sum of completion times of all previous jobs.
    - Returns the integer average waiting time (total waiting time / n).

Assumptions:
    - jobs contains positive durations; n > 0.

Complexity:
    - Time: O(n log n) due to sorting.
    - Space: O(1) extra (in-place sort).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;



int avgWaitingTimeSJF(vector<int>& jobs) {
    sort(jobs.begin(), jobs.end());
    int n = jobs.size();
    int totalWaitingTime = 0;
    int cumulativeTime = 0;

    for(int i = 0; i < n; i++) {
        totalWaitingTime += cumulativeTime;
        cumulativeTime += jobs[i];
    }

    return totalWaitingTime / n;
}

int main(){
    int n;
    cin >> n;
    vector<int> jobs(n);
    for(int i = 0; i < n; i++){
        cin >> jobs[i];
    }
    cout << avgWaitingTimeSJF(jobs) << endl;
    return 0;
}