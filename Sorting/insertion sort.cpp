#include<iostream>
using namespace  std;

void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j = i+1;
        while (j > 0 && arr[j] < arr[j-1])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void recursiveInsertionSort(int arr[],int low,int high){
   if(low < high){
        int j = low + 1;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
        recursiveInsertionSort(arr,low+1,high);
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
    
    cout<<"before insertion sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    insertionSort(arr,n);

    cout<<"after insertion sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }

    
    return 0;
}