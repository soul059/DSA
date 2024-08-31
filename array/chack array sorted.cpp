#include<iostream>
using namespace  std;

bool isSorted(int array[],int n){
    for (int i = 1; i < n; i++)
    {
        if (array[i]<array[i-1])
        {
            return false;
        }
        
    }
    return true;
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
    bool result = isSorted(arr,n);
    if (result)
    {
        cout<<"Array is sorted";
    }
    else
    {
        cout<<"Array is not sorted";
    }
    

    
    return 0;
}