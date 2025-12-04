/*
 * LEADERS IN AN ARRAY
 * 
 * Leader: Element greater than all elements to its right
 * 
 * Approach: Traverse from right, track maximum
 * If element > max, it's a leader
 * 
 * Time: O(n) | Space: O(n) for result
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

vector<int> leaderInArr(vector<int> arr,int n){
    vector<int> ans;
    int  maxi = INT_MIN;

    for(int i = n-1;i>=0;i--){
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
        }
        maxi = max(arr[i],maxi);
        
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> res = leaderInArr(arr,n);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}