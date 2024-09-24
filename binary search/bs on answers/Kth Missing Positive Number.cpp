#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace  std;

int missingK(vector<int> arr,int k){
    int low = 0, high = arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing = arr[mid] - (mid+1);
        if(missing < k) 
            low = mid+1;
        else 
            high = mid-1;
    }
    return k + high +1;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = missingK(arr,k);
    cout<<"missing number is: "<<ans<<endl;
    return 0;
}