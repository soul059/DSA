#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

vector<int> withBite(vector<int> arr,int n){
    vector<int> ans;
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }
    int nm = xr & ~(xr-1);
    int one = 0;
    int zero = 0;
    for(int i = 0; i < n; i++){
        //for 1 club
        if((arr[i] & nm) != 0){
            one = one ^ arr[i];
        }
        //for 0 club
        else{
            zero = zero ^ arr[i];
        }
    }
    for(int i = 1; i <= n; i++){
        //for 1 club
        if((i & nm) != 0){
            one = one ^ i;
        }
        //for 0 club
        else{
            zero = zero ^ i;
        }
    }

    int ctn = 0;
    for(int i = 0; i < n; i++){
        if(one == arr[i]){
            ctn++;
        }
    }
    if(ctn == 2){
        ans.push_back(one);
        ans.push_back(zero);
    }
    else{
        ans.push_back(zero);
        ans.push_back(one);
    }

    return ans;
}
vector<int> withMath(vector<int> arr,int n){
    long long s1=0;
    long long sn1 = (n*(n+1))/2;
    long long s2 = 0;
    long long sn2 = (n*(n+1)*(2*n +1))/6;

    for(int i=0;i<n;i++){
        s1+= arr[i];
        s2+= arr[i]*arr[i];
    }
    long long val1 = s1 - sn1;
    long long val2 = s2 - sn2;
    val2 = val2/val1;
    int x = (val1 + val2)/2;
    int y = x - val1;

    
    vector<int> ans = {x,y};
    return ans;
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> res = withBite(arr,n);

    cout<<"done by bite"<<endl;
    cout<<"{"<<res[0]<<","<<res[1]<<"}"<<endl;


    res = withMath(arr,n);
    cout<<"done by math"<<endl;
    cout<<"{"<<res[0]<<","<<res[1]<<"}"<<endl;

    
    return 0;
}