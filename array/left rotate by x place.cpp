#include<iostream>
#include<algorithm> // Add this line to include the <algorithm> header
using namespace  std;

void revPart(int arr[],int x, int y){
    while (x<y)
    {
        swap(arr[x],arr[y]);
        x++;
        y--;
    }
    
}

void LrotateByx(int arr[],int n,int x){
    int part = x%n;
    revPart(arr,0,part-1);
    revPart(arr,part,n-1);
    revPart(arr,0,n-1);
}

int main(){
    int n,x;
    cin>> n;
    int arr[n];
    cin>>x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    
    LrotateByx(arr,n,x);

for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    
    return 0;
}