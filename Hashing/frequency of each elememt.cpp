#include<iostream>
#include<unordered_map>

using namespace  std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

// this is brute force approach
    // int freq[100000]={0};
    // for(int i=0;i<n;i++) freq[a[i]]++;
    // for(int i=0;i<100000;i++){
    //     if(freq[i]!=0) cout<<i<<" "<<freq[i]<<endl;
    // }
// now we will use unorderd map to solve this problem

    unordered_map<int,int> m; // you can use map also but in map it will take O(logn) time complexity but in unordered_map it will take O(1) time complexity
    for(int i=0;i<n;i++) m[a[i]]++;
    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }

    return 0;
}