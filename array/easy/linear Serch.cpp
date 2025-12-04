/*
 * LINEAR SEARCH
 * 
 * Approach: Check each element sequentially
 * 
 * Time: O(n) | Space: O(1)
 * 
 * Works on unsorted arrays
 */

#include<iostream>
using namespace  std;

void linerSearch(int arr[],int n,int key){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == key){
            cout<< "Element found at index: "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout<<"Array before removing duplicate elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    
   
    int key;
    cin>>key;
    linerSearch(arr,n,key);
    
    return 0;
}