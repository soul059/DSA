#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * Compute the minimum number of platforms required so that no train waits.
 * Approach: sort arrival and departure times, then use two-pointer scan to
 * count overlapping trains (arrival <= departure counts as overlap).
 *
 * Parameters:
 *  - arrival: vector<int> of arrival times
 *  - departure: vector<int> of departure times
 * Returns:
 *  - int: maximum concurrent platforms needed
 *
 * Complexity: Time O(n log n) (sorting), Space O(1) extra (in-place sorts).
 */

int maxPlatformReq(vector<int> arrival, vector<int> departure) {
    int n = arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int platformNeeded = 0, maxPlatforms = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platformNeeded++;
            maxPlatforms = max(maxPlatforms, platformNeeded);
            i++;
        } else {
            platformNeeded--;
            j++;
        }
    }
    return maxPlatforms;
}

int main(){
    int n;
    cin>>n;
    vector<int> arrival(n), departure(n);
    for(int i=0;i<n;i++) cin>>arrival[i];
    for(int i=0;i<n;i++) cin>>departure[i];
    cout << maxPlatformReq(arrival, departure) << endl;
    return 0;
}