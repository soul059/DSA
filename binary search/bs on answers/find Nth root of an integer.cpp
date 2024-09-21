#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int findN(int mid,int n,int m){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans*= mid;
        if(ans> m) return 2; // this is naver be an ans if ans > m
        // so we need to elemeted right half 
    }
    if(ans ==m) return 1; // this is the ans which we looking for
    return 0; // ans < m then we need to elemeted left half
}

int findNthSqrt(int n,int m){
    int low =1,high =n;
    while(low<=high){
        int mid=(low+high)/2;
        int midN = findN(mid,n,m);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid+1;
        else high = mid -1;
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;

    int ans = findNthSqrt(n,m);
    cout<<n<<"'th squre root of "<< m <<"\t is: "<<ans<<endl;
    return 0;
}