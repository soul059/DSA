#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int lowerBound(vector<int> arr,int x){
    int low =0,high=arr.size()-1;
    int ans = arr.size();
    while (low <=high){
        int mid = (low + high) / 2;
        if(arr[mid] >= x ){
            ans =arr[mid];
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
    
}

int ceil(vector<int> arr,int x){
    return lowerBound(arr,x);
}

int floor(vector<int> arr,int x){
    int low =0,high=arr.size()-1;
    int ans = arr.size();
    while (low <=high){
        int mid = (low + high) / 2;
        if(arr[mid] <= x ){
            ans = arr[mid];
            low = mid+1;
        }
        else high = mid-1;
    }

    return ans;
}

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>x;

    int c = ceil(arr,x);
    int f = floor(arr,x);
    cout<<"ceil is: "<<c<<"\t\t"<<"floor is: "<<f<<endl;

    

    return 0;
}