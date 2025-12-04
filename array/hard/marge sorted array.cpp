/*
 * MERGE TWO SORTED ARRAYS WITHOUT EXTRA SPACE
 * 
 * Approach 1: Gap Method (Shell Sort idea) - O((n+m)log(n+m))
 * Approach 2: Two Pointer - Swap if arr1[left] > arr2[right], then sort
 * 
 * Time: O((n+m)log(n+m)) | Space: O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

void swapIfGreater(vector<int> &arr1, int ind1, vector<int> &arr2, int ind2){
    if(arr1[ind1] > arr2[ind2]) swap(arr1[ind1],arr2[ind2]);
}

void mergeByGap(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    // Calculate initial gap
    int len = (n + m);
    int gap = len / 2 + len%2;
    while(gap > 0) {
        // Initialize left and right pointers
        int left = 0;
        int right = left + gap;
        while(right < len) {
            // Swap elements if needed
            //arr1 and arr2
            if(left < n && right >= n && right < n + m) {
                swapIfGreater(arr1, left, arr2,right - n);
            }
            //arr2 and arr2
            else if(left >= n && right >=n) {
                swapIfGreater(arr2, left - n,arr2 ,right -n);
            } 
            // arr1 and arr1
            else if(right < n) {
                swapIfGreater(arr1, left,arr1 ,right);
            }
            
            // Move to next pair of elements
            left++;
            right++;
        }
        
        // Update the value of the gap for next iteration
        if(gap == 1)
           break;
        
        // Recalculate next value of the variable 'gap'
        gap = (gap) / 2 + gap%2;
    }
}

void margeBy2point(vector<int> &arr1, int n, vector<int> &arr2, int m){
    int left = n-1;
    int right = 0;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]) {
            
            swap(arr1[left],arr2[right]);
            left--, right++;
        }
        else break;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

int main(){
    int n1,n2;
    cin>>n1>>n2;

    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }
    cout<<"before"<<endl;
    for(int i=0; i<n1; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n2; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    margeBy2point(arr1,n1,arr2,n2);
    cout<<"after marging 2 array"<<endl;
    for(int i=0; i<n1; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n2; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}