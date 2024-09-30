#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

float giveMedian(vector<int> arr1,vector<int> arr2,int k){
    int n1 = arr1.size();
    int n2 = arr2.size();
    if(n1>n2) return giveMedian(arr2,arr1,k);
    
    int n = n1+n2;
    int left  = (n+1)/2;
    int low = min(0,k-n2), high = min(k,n1);
    while(low<= high){
        int mid1 = (low+high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = arr1[mid1];
        if (mid2 < n2) r2 = arr2[mid2];
        if (mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main(){
    int n1,n2,k;
    cin>>n1>>n2>>k;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i = 0; i < n1; i++) cin >> arr1[i];
    for(int i = 0; i < n2; i++) cin >> arr2[i];

    float ans = giveMedian(arr1,arr2,k);
    cout<<"median is: "<<ans<<endl;
    return 0;
}