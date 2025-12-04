/*
 * REMOVE DUPLICATES FROM SORTED ARRAY
 * 
 * Approach: Two pointer - track unique position
 * When new element found, place it at unique position
 * 
 * Time: O(n) | Space: O(1)
 * 
 * Returns count of unique elements
 */

#include<iostream>
using namespace  std;


int removeDuplicate(int arr[],int n){
    // brutforce solution is doing with set
    int start = 0;
    for(int i=0; i< n;i++){
        if(arr[start] != arr[i]){
            start++;
            swap(arr[start],arr[i]);
        }
    }
    return start + 1;
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

    int uniqueEle = removeDuplicate(arr,n);

    cout<<"Array after removing duplicate elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    cout<< "number of unique element in array: "<<uniqueEle<<endl; 
   

    
    return 0;
}