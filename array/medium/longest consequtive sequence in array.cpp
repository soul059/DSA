/*
 * LONGEST CONSECUTIVE SEQUENCE
 * 
 * Approach: HashSet
 * For each element, if (element-1) not in set, it's sequence start
 * Count consecutive elements from there
 * 
 * Time: O(n) | Space: O(n)
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace  std;

int longestConsequtiv(vector<int> arr,int n){
    unordered_set<int> us;
    int longest = 1;

    for(int i = 0; i< n ;i++){
        us.insert(arr[i]);
    }

    for(auto it : us){
        if (us.find(it-1) == us.end())
        {
            int crr = 1;
            int x = it;
            while (us.find(x+1) != us.end())
            {
                crr += 1;
                x += 1;
            }
            longest = max(longest , crr);
        }
    }

    return longest;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int res = longestConsequtiv(arr,n);
    cout<<"longest consequtive sequence in array is: "<<" "<<res;
    cout<<endl;
    return 0;
}