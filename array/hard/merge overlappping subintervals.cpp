/*
 * MERGE OVERLAPPING INTERVALS
 * 
 * Approach: Sort by start time
 * If current start <= last end: merge (update end)
 * Else: add as new interval
 * 
 * Time: O(n log n) for sorting | Space: O(n) for result
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

vector<vector<int>> mergeSubinterval(vector<vector<int>> arr,int n){
    vector<vector<int>> ans;
    for(int i =0; i<n;i++){
        if(ans.empty() || arr[i][0] > ans.back()[1] ) ans.push_back(arr[i]);
        else ans.back()[1] = max(arr[i][1], ans.back()[1]);
    }

    return ans;
}

int main(){
    int n;
    cin>>n; // row
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0; i<n; i++){
       for(int j=0;j<2;j++){
            cin>>arr[i][j];
       }
    }

    cout<<"before overlap"<<endl;
    for(int i=0; i<n; i++){
       for(int j=0;j<2;j++){
            cout<<arr[i][j]<<" ";
       }
       cout<<"\t";
    }
    cout<<endl;

    vector<vector<int>> res = mergeSubinterval(arr,n);
    cout<<"after overlapping"<<endl;
    for(int i=0; i<res.size(); i++){
       for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
       }
       cout<<endl;
    }
   
    return 0;
}