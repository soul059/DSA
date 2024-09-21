#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int upperBound(vector<int> arr,int x){
    int low =0,high=arr.size()-1;
    int ans = arr.size();
    while (low <=high){
        int mid = (low + high) / 2;
        if(arr[mid] > x ){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
    
} 

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>x;

    int ans = upperBound(arr,x);
    cout<<"upper bound at index: "<<ans<<endl;

    ans = upper_bound(arr.begin(), arr.end(), x) - arr.begin(); 
    // lower_bound(arr.begin(), arr.end(), x) returns itrator pointing to index
    cout<<"upper bound by inbuilt function at index: "<<ans<<endl;

    return 0;
}