#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

bool fitCowsInGivenSpacec(vector<int> arr,int mid,int cows){
    int cntcow=1;
    int last = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i] - last >= mid){
            cntcow += 1;
            last = arr[i];
        }
    }

    return cntcow >= cows;
}

int findGapBwtCow(vector<int> &arr,int cows){
    sort(arr.begin(),arr.end());
    int low = 1, high=arr[arr.size()-1];
    while(low<= high){
        int mid = (low+high)/2;
        if(fitCowsInGivenSpacec(arr,mid,cows)){
            low = mid+1;
        }
        else high = mid-1;
    }
    return high;
}

int main(){
    int n,cows;
    cin>>n>>cows;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = findGapBwtCow(arr,cows);
        
    cout << "minimum gap between 2 cows is: "<<ans << endl;
    return 0;
}