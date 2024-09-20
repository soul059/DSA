#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int minInRotatedSorted(vector<int> arr,int target){
    int low=0, high= arr.size()-1;
    int mini = INT_MAX;
    while(low<=high){
        // if(arr[low] <= arr[high]){ 
        //     mini = min(mini,arr[low]);
        //     break;
        // }
        //optimization will not work in this case
        int mid = (low+high)/2;
        //for optimization
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            mini = min(mini,arr[low]);
            low++;
            high--;
            continue;
        }
        if(arr[low] < arr[mid] && arr[mid] < arr[high]){
            mini = min(mini,arr[low]);
            break;
        }
        if(arr[low] <= arr[mid]){ //left half sorted
            mini = min(mini,arr[low]);
            low = mid +1;
        }
        else{ //right half sorted
            mini = min(mini,arr[mid]);
            high = mid-1;
        }
    }
    return mini;
}

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = minInRotatedSorted(arr,x);
    cout<<"minimum element is: "<<ans<<endl;
    return 0;
}