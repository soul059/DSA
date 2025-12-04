/*
 * FIND SECOND LARGEST ELEMENT
 * 
 * Approach: Track both max and second_max in single pass
 * Update second_max when a new max is found
 * 
 * Time: O(n) | Space: O(1)
 */

#include<iostream>
using namespace  std;

int maxSeEle(int arr[],int n){
    int max = arr[0];
    int max2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>max)
        {
            max2 = max;
            max = arr[i];
        }
        else if (arr[i]>max2 && arr[i]!=max)
        {
            max2 = arr[i];
        }
        
    }
    return max2;
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
    int max = maxSeEle(arr,n);
    cout<<"Second largest element in array is "<<max<<endl;

    
    return 0;
}