#include<iostream>
using namespace  std;

int findNumber(int arr[],int n){
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res^arr[i];
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

    int number = findNumber(arr,n);
    cout<<"Number which appears only once in array: "<<number<<endl;

    return 0;
}