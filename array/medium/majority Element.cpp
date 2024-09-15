#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

// problem statement -> find which element in array apper > n/2 times were n is length of array

int hashSol(vector<int> &arr,int n){
    unordered_map<int,int> ump;
    int min = n/2 +1;

    for (int i = 0; i < n; i++)
    {
        ump[arr[i]]++;
        if(ump[arr[i]] >= min ) return arr[i];
    }
    // for(auto it : ump){
    //     if (it.second > n/2)
    //     {
    //         return it.first;
    //     } 
    // }

    return -1;
}

int moorsVotingAlgo(vector<int> &arr , int n){
    int ele = arr[0];
    int count = 1 , atcualC = 0;

    for (int i = 1; i < n; i++)
    {
        if (count == 0)
        {
            ele = arr[i];
            count = 1;
        }
        else if(arr[i] == ele){
            count++;
        }
        else{
            count--;
        }  
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            atcualC++;
        }
    }
    if (atcualC > n/2)  
    {
        return ele;
    }
    
    return -1;
       

}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int res  = hashSol(arr,n);
    cout<< "maximum number occers in array is: "<<res<<endl;
    res  = moorsVotingAlgo(arr,n);
    cout<< "maximum number occers in array by moors voting algo is: "<<res<<endl;
    
    return 0;
}