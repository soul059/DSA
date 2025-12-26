#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * @brief Job Sequencing to maximize profit with deadlines.

 * Greedy algorithm that sorts jobs by profit and schedules them in the latest available slot before their deadline.
 * 
 * @param jobs Vector of pairs where each pair contains (deadline, profit).
 * @param n Number of jobs.
 * @return Maximum profit achievable by scheduling jobs within their deadlines.

 * Complexity: O(n log n) time due to sorting, O(n) space for the schedule.
 */

 bool compareJobs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second; // Sort by profit in descending order
}

int jobScheduling(vector<pair<int, int>>& jobs, int n) {
    // Sort jobs by profit
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Find maximum deadline to size the schedule
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.first);
    }

    vector<bool> slot(maxDeadline + 1, false); // Track occupied slots
    int totalProfit = 0;

    for (const auto& job : jobs) {
        int deadline = job.first;
        int profit = job.second;

        // Find a free slot for this job (starting from its deadline)
        for (int j = min(deadline, maxDeadline); j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true; // Mark this slot as occupied
                totalProfit += profit; // Add profit
                break;
            }
        }
    }

    return totalProfit;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> jobs(n);
    for(int i = 0; i < n; i++){
        int deadline, profit;
        cin >> deadline >> profit;
        jobs[i] = {deadline, profit};
    }
    cout << jobScheduling(jobs, n) << endl;
    return 0;
}