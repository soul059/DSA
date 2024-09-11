#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace  std;

bool sumOf2EqulsTok(vector<int> arr,int k){
    int i = 0;
    int j = arr.size() - 1;
    int sum = 0;

    sort(arr.begin(),arr.end());
    while ( i < j)
    {
        sum = arr[i] + arr[j];
        
        if(sum == k){
            i++;
            j--;
            return true;
        }
        else if (sum > k)
        {
            j--;
        }
        else if (sum < k)
        {   
            i++;
        }
        
        
    }
    
    

    return false;
}

vector<int> byHash(vector<int> arr,int k){
    vector<int> res;
    unordered_map<int,int> ump;

    for (int i = 0; i < arr.size(); i++)
    {
        int a = arr[i];
        int more = k - a;
        if(ump.find(more) != ump.end()){
            res.push_back(ump[more]);
            res.push_back(i);
        }
        ump[a] = i;
    }
    
    
    return res;
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    int res = sumOf2EqulsTok(arr, k);

    if (res)
    {
        cout<< "yes targated sum is present in array"<<endl;
    }
    else{
        cout << "no there is no targated sum in array"<<endl;
    }
    
    vector<int> resp = byHash(arr,k);
    cout<<"first index is: "<< resp[0]<< "second index is:" << resp[1]<<endl;


    
    return 0;
}