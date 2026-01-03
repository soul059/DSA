#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * fractionalKnapsack - Greedy algorithm for the fractional knapsack problem

 * Description:
 *   Computes the maximum obtainable value given a knapsack capacity W by
 *   taking whole items or fractions of items. For each item i, the value-to-weight
 *   ratio r_i = val[i] / wt[i] is computed, items are sorted in descending order
 *   of r_i, and the knapsack is filled greedily:
 *     - take the whole item while its weight fits,
 *     - if the next item's weight exceeds remaining capacity, take the fractional
 *       part that fits and add proportional value, then stop.

 * Parameters:
 *   W   - knapsack capacity (remaining weight allowed)
 *   wt  - vector of item weights
 *   val - vector of item values
 *   n   - number of items

 * Return:
 *   Maximum value obtainable (note: implementation returns an int; fractional
 *   contributions may be truncated—use double return type for exact fractional value).

 * Complexity:
 *   Time: O(n log n) due to sorting
 *   Space: O(n) extra for storing ratios/indices

 * Preconditions / Notes:
 *   - wt[i] must be > 0 for all items.
 *   - wt and val should each contain at least n elements.
 *   - Uses greedy choice proven optimal for the fractional knapsack problem.
 */

int fractionalKnapsack(int W, vector<int> wt, vector<int> val, int n){
    vector<pair<double, int>> ratio;
    for(int i=0;i<n;i++){
        double r = (double)val[i]/(double)wt[i];
        ratio.push_back({r, i});
    }
    sort(ratio.rbegin(), ratio.rend());
    int totalValue = 0;
    for(int i=0;i<n;i++){
        int idx = ratio[i].second;
        if(wt[idx]<=W){
            W -= wt[idx];
            totalValue += val[idx];
        }else{
            totalValue += ratio[i].first * W;
            break;
        }
    }
    return totalValue;
}

int main(){
    int n;
    cin>>n;
    vector<int> wt(n), val(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];
    int W;
    cin>>W;
    cout << fractionalKnapsack(W, wt, val, n) << endl;
    return 0;
}