/*
 * FIND LARGEST ELEMENT IN ARRAY
 * 
 * Approach: Linear scan, track maximum
 * 
 * Time: O(n) | Space: O(1)
 */

#include<iostream>
using namespace  std;

int maxele(int arr[],int n){
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
        
    }
    return max;
}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    int max = maxele(arr,n);
    cout<<"largest element in array is "<<max<<endl;

    
    return 0;
}