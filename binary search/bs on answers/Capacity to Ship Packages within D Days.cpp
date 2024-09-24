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

int sumOfAllArrele(vector<int> arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    return sum;
}

bool finddays(vector<int> arr,int k,int day){
    int days=1;
    int load=0;
    for(int i=0;i<arr.size();i++){
        if(load + arr[i] > k){
            days += 1;
            load = arr[i];
        }
        else load+= arr[i];
    }
    return days <= day;
}
int miniCapacityShipWithinDday(vector<int> arr,int day){
    int low = maxi(arr), high = sumOfAllArrele(arr);
    while(low<=high){
        int mid=(low+high)/2;
        if(finddays(arr,mid,day)) 
            high = mid-1;
        else 
            low = mid+1;
    }
    return low;
}

int main(){
    int n,day;
    cin>>n>>day;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = miniCapacityShipWithinDday(arr,day);
    cout<<"minimum capacity ship need is: "<<ans<<" to get deleveered all packaged in: "<<day<<endl;
    return 0;
}