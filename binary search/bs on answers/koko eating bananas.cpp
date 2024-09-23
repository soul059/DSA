#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace  std;

int maxi(vector<int> arr){
    int max1 = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > max1) {
            max1 = arr[i];
        }
    }
    return max1;
}
int findTime(vector<int> arr,int k){
    int totaltime=0;
    for(int i=0;i<arr.size();i++){
        totaltime += ceil((double)(arr[i]) / (double) (k));
    }
    return totaltime;
}
int eatingFrequ(vector<int> arr,int hour){
    int low = 1, high = maxi(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int time = findTime(arr,mid);
        if(time<=hour) 
            high = mid-1;
        else 
            low = mid+1;
    }
    return low;
}

int main(){
    int n,hour;
    cin>>n>>hour;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = eatingFrequ(arr,hour);
    cout<<"koko need to eat: "<<ans<<" bananas an hour"<<endl;
    return 0;
}