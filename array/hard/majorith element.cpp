#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

vector<int> moorsVotingAlgo(vector<int> &arr , int n){
    vector<int> ans;
    int el1=INT_MIN;
    int el2 = INT_MIN;
    int cnt1=0,cnt2=0;
    int min = n/3 +1;

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != arr[i])
        {
            el1 = arr[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && el1 != arr[i]){
            el2 = arr[i];
            cnt2 = 1;
        }
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }  
    }
    cnt1=0;
    cnt2 =0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el1)
        {
            cnt1++;
        }
        if (arr[i] == el2)
        {
            cnt2++;
        }
    }
    
    if(cnt1 >= min) ans.push_back(el1);
    if(cnt2 >= min) ans.push_back(el2);
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> res = moorsVotingAlgo(arr,n);
    if (!res.empty())
    {
        cout << "maximum number occers in array by moors voting algo is: ";
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i < res.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    
    
    return 0;
}