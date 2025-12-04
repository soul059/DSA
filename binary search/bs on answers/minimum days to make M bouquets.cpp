/*
 * Minimum Days to Make M Bouquets
 * Approach: Binary search on days [min, max]; for each day count consecutive bloomed flowers
 *           to form bouquets; find minimum days where bouquets >= m
 * Time: O(n * log(max - min))
 * Space: O(1)
 * Key: Each bouquet needs k consecutive flowers; count bouquets that can be made by given day
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace  std;

int maxi(vector<int> arr){
    int max1 = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > max1) {
            max1 = arr[i];
        }
    }
    return max1;
}

int mini(vector<int> arr) {
    int min1 = INT_MAX;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < min1) {
            min1 = arr[i];
        }
    }
    return min1;
}

bool findbouquets(vector<int> arr,int day,int m,int k){
    int count=0,noOfBou=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] <= day){
            count++;
        }
        else{
            noOfBou += count/k;
            count =0;
        }
    }
    noOfBou += count/k;
    if(noOfBou >= m) return true;

    return false;
}
int miniDayToMakeMBouquwts(vector<int> arr,int m,int k){
    int low = mini(arr), high = maxi(arr);
    while(low<=high){
        int mid=(low+high)/2;
        bool bouque = findbouquets(arr,mid,m,k);
        if(bouque) 
            high = mid-1;
        else 
            low = mid+1;
    }
    return low;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = miniDayToMakeMBouquwts(arr,m,k);
    cout<<"minimum days: "<<ans<<" we need to make M bouquets"<<endl;
    return 0;
}