/*
 * MOVE ZEROS TO END
 * 
 * Approach: Two pointer - swap non-zero with first zero position
 * 
 * Time: O(n) | Space: O(1)
 * 
 * Maintains relative order of non-zero elements
 */

#include<iostream>
using namespace  std;

void moveZeroToEnd(int arr[],int n){
    int start = 0;
    int end = n-1;
    while (start < end)
    {
        if(arr[start] == 0){
            swap(arr[start],arr[end]);
            end--;
        }else{
            start++;
        }
    }
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
    moveZeroToEnd(arr,n);

    cout<<"Array after moving zero to end"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    
   

    
    return 0;
}