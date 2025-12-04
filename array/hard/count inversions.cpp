/*
 * COUNT INVERSIONS - Modified Merge Sort
 * 
 * Inversion: arr[i] > arr[j] where i < j
 * 
 * Approach: During merge, if left[i] > right[j],
 * all remaining elements in left are inversions
 * Count += (mid - left + 1)
 * 
 * Time: O(n log n) | Space: O(n)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;


// you can declare cnt in globle
int merge(vector<int> &arr,int low ,int mid ,int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    int cnt=0;
    while (left <= mid && right <= high)
    {
        // right >= left
        if(arr[left] <= arr[right] ){
            temp.push_back(arr[left]);
            left++;
        }
        // left > right
        else{
            temp.push_back(arr[right]);
            cnt += mid -left +1;
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    
    return cnt;
    
}

int mergeSort(vector<int> &arr,int low,int high){
    int cnt=0;
    if(low >= high) return cnt;
    int mid = (low + high)/2;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int res = mergeSort(arr,0,n-1);
    cout<<"count is: "<<res;
    return 0;
}