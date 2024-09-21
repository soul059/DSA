#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int findSqrt(int n){
    int low =1,high =n;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid<=n) 
            low = mid+1;
        else 
            high = mid-1;
    }
    return high;
}

int main(){
    int n;
    cin>>n;

    int ans = findSqrt(n);
    cout<<"squre root of "<< n <<"\t is: "<<ans<<endl;
    return 0;
}