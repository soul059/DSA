#include<iostream>
using namespace  std;

void bubbleSort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        bool didswap= false;
        for (int j = 0; j < n-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap = true;
            }
        }
        if (!didswap)
        {
            break;
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
    
    cout<<"before bubble sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    bubbleSort(arr,n);

    cout<<"after bubble sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }

    
    return 0;
}