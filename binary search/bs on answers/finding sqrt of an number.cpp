/*
 * SQUARE ROOT OF A NUMBER - Binary Search on Answer
 * 
 * Find largest integer x where x*x <= n
 * 
 * Approach: Binary search from 1 to n
 * - If mid*mid <= n: answer could be mid or higher
 * - Else: search lower half
 * 
 * Time: O(log n) | Space: O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int findSqrt(int n){
    int low =1,high =n;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid<=n) 
            low = mid+1;
        else 
            high = mid-1;
    }
    return high;
}

int main(){
    int n;
    cin>>n;

    int ans = findSqrt(n);
    cout<<"squre root of "<< n <<"\t is: "<<ans<<endl;
    return 0;
}