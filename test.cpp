#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    for(auto it: arr) cout<<it<<" ";
    cout<<endl;
    return 0;
}