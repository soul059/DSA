#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;

vector<vector<int>> sum3(vector<int> arr,int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }

    return ans;
}

void test_sum3() {
    // Test case 1: General case with multiple triplets
    vector<int> arr1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> expected1 = {{-1, -1, 2}, {-1, 0, 1}};
    vector<vector<int>> result1 = sum3(arr1, arr1.size());
    assert(result1 == expected1);

    // Test case 2: No triplets found
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<vector<int>> expected2 = {};
    vector<vector<int>> result2 = sum3(arr2, arr2.size());
    assert(result2 == expected2);

    // Test case 3: All zeros
    vector<int> arr3 = {0, 0, 0, 0};
    vector<vector<int>> expected3 = {{0, 0, 0}};
    vector<vector<int>> result3 = sum3(arr3, arr3.size());
    assert(result3 == expected3);

    // Test case 4: Single element
    vector<int> arr4 = {1};
    vector<vector<int>> expected4 = {};
    vector<vector<int>> result4 = sum3(arr4, arr4.size());
    assert(result4 == expected4);

    // Test case 5: Two elements
    vector<int> arr5 = {1, -1};
    vector<vector<int>> expected5 = {};
    vector<vector<int>> result5 = sum3(arr5, arr5.size());
    assert(result5 == expected5);

    // Test case 6: Large numbers
    vector<int> arr6 = {1000000, -1000000, 0, -999999, 999999};
    vector<vector<int>> expected6 = {{-1000000, 0, 1000000}, {-999999, 0, 999999}};
    vector<vector<int>> result6 = sum3(arr6, arr6.size());
    assert(result6 == expected6);

    cout << "All test cases passed!" << endl;
}

int main() {
    test_sum3();
    return 0;
}