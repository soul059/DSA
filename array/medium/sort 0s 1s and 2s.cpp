/*
 * SORT 0s, 1s, AND 2s - Dutch National Flag Algorithm
 * 
 * Three pointers: low, mid, high
 * - 0s go to [0, low-1]
 * - 1s go to [low, mid-1]
 * - 2s go to [high+1, n-1]
 * 
 * Time: O(n) | Space: O(1) - Single pass
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace  std;

void flagalgo(vector<int> &arr,int n){
    int low = 0 , mid = 0 , high = n -1;
    while (mid <= high)
    {
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
        
    }
    
    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    flagalgo(arr,n);

    for(int i =0 ;i<n ; i++){
        cout<< arr[i] << " "; 
    }
    cout<<endl;
    
    
    return 0;
}