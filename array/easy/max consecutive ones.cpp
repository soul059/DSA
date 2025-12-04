/*
 * MAX CONSECUTIVE ONES
 * 
 * Approach: Track current streak and max streak
 * Reset current when 0 is encountered
 * 
 * Time: O(n) | Space: O(1)
 */

#include<iostream>
using namespace  std;

int maxConsecutiveOnes(int arr[],int n){
    int res = 0;
    int crr = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 1){
            crr++;
            res = max(res,crr);
        }else{
            crr = 0;
        }
    }
    
    return res;
}


int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout<<"Array before"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    int maxConsecutive = maxConsecutiveOnes(arr,n);
    cout<<"Max consecutive one's in array: "<<maxConsecutive<<endl;
    
    return 0;
}