#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

vector<int> nextPermu(vector<int> arr,int n){
    int ind = -1;
    for(int i = n-2 ; i>=0 ;i--){
        if(arr[i] < arr[i+1]){
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(arr.begin(),arr.end());
        return arr;
    }
    for(int i = n-1 ; i> ind ;i--){
        if (arr[i] > arr[ind])
        {
            swap(arr[i],arr[ind]);
            break;
        }
        
    }
    reverse(arr.begin() + ind + 1, arr.end());

    return arr;
    
    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> res = nextPermu(arr,n);
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}