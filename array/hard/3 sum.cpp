#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace  std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> sum3(vector<int> arr,int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<vector<int>> res = sum3(arr,n);
    cout<<"responce with 2 pointer approch"<<endl;
    for(int i=0; i<res.size(); i++){
       for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
       }
       cout<<endl;
    }

    res = triplet(n,arr);
    cout<<"responce with hash set approch"<<endl;
        for(int i=0; i<res.size(); i++){
       for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
       }
       cout<<endl;
    }

    return 0;
}