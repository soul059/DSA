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
int findlimit(vector<int> arr,int k){
    int totallimit=0;
    for(int i=0;i<arr.size();i++){
        totallimit += ceil((double)(arr[i]) / (double) (k));
    }
    return totallimit;
}
int smallestDivForLimit(vector<int> arr,int hour){
    int low = 1, high = maxi(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int time = findlimit(arr,mid);
        if(time<=hour) 
            high = mid-1;
        else 
            low = mid+1;
    }
    return low;
}

int main(){
    int n,limit;
    cin>>n>>limit;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = smallestDivForLimit(arr,limit);
    cout<<"smallest divisor is: "<<ans<<" to get threshold of: "<<limit<<endl;
    return 0;
}