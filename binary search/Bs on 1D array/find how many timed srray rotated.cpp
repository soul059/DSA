/*
 * FIND HOW MANY TIMES ARRAY IS ROTATED
 * 
 * Rotation count = Index of minimum element
 * Use binary search to find minimum in rotated sorted array
 * 
 * Time: O(log n) | Space: O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;
// arr = [3 4 5 1 2];
// ans will be 3 times so same as minimum in array 
//here 1 is at 3 index that's why array is being roted 3 times
// just for understanding : rotating done by 1 rotation at time 
int minInRotatedSorted(vector<int> arr){
    int low=0, high= arr.size()-1;
    int mini = INT_MAX;
    int index = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low] <= arr[high]){ //optimization ont needed
            if(arr[low] < mini){
                mini = arr[low];
                index = low;
            }
            break;
        }
        if(arr[low] <= arr[mid]){ //left half sorted
            if(arr[low] < mini){
                mini = arr[low];
                index = low;
            }
            low = mid +1;
        }
        else{ //right half sorted
            if(arr[mid] < mini){
                mini = arr[mid];
                index = low;
            }
            high = mid-1;
        }
    }
    return index;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = minInRotatedSorted(arr);
    cout<<"array is being rotated: "<<ans<<"\ttimes"<<endl;
    return 0;
}