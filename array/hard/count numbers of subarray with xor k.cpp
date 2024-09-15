#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace  std;

int countSubXOREqulK(vector<int> arr,int k){
    map<int,int> mpp;
    mpp[0] = 1; // this is need in case of x - k = 0; 
    int n = arr.size();
    int xr = 0, ctn =0;
    for(int i =0;i<n;i++){
        xr = xr ^ arr[i];
        int remove = xr ^ k;
        ctn += mpp[remove];
        mpp[xr]+=1;
    } 
    return ctn;
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int res = countSubXOREqulK(arr,k);

    cout<<"number of subarray with XOR k in this array is: "<<res<<endl;
  
    return 0;
}