/*
 * BEST TIME TO BUY AND SELL STOCK
 * 
 * Track minimum price so far, calculate profit at each day
 * Max profit = max(current_price - min_price_so_far)
 * 
 * Time: O(n) | Space: O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int maxProfit(vector<int> arr, int n){
    int mini = arr[0];
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = arr[i] - mini;
        profit = max(cost , profit);
        mini = min(arr[i], mini);
    }
    
    return profit;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int res = maxProfit(arr,n);
    cout<<"maximum profit is: "<<res<<endl;
    
    return 0;
}