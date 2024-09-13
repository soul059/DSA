#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

// varient 1 -> n/2 are positive and n/2 are negative

vector<int> rearrangeV1(vector<int> arr, int n){
    vector<int> res(n,0);
   int pos = 0 , neg =1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            res[pos] = arr[i];
            pos+= 2;
        }
        else{
            res[neg] = arr[i];
            neg += 2;
        }
        
    }
    

   return res;
}


// varient 2 -> we don't know the number of positive and negative numbers
vector<int> rearrangeV2(vector<int> arr,int n){
    vector<int> pos;
    vector<int> neg;
    vector<int> res(n,0);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
        
    }

    int psize = pos.size();
    int nsize = neg.size();
    if(psize > nsize){
        for (int i = 0; i < nsize; i++)
        {
            res[i*2] = pos[i];
            res[i*2+1] = neg[i];
        }
        
        int index = nsize * 2; 
        for (int i = nsize; i < psize; i++)
        {
            res[index] = pos[i];
            index++;
        }   
    }
    else
    {
        for (int i = 0; i < psize; i++)
        {
            res[i*2] = pos[i];
            res[i*2+1] = neg[i];
        }
        
        int index = psize * 2; 
        for (int i = psize; i < nsize; i++)
        {
            res[index] = neg[i];
            index++;
        }   
    }
    
    return res;
    
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> res = rearrangeV1(arr,n);
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    res = rearrangeV2(arr,n);
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;



    return 0;
}