#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int niceSubarrays(const vector<int>& nums, int k) {
    auto atMost = [&](int maxOddCount) {
        int left = 0, subarrayCount = 0;
        for(int right = 0; right < int(nums.size()); ++right) {
            maxOddCount -= nums[right] % 2;
            while(maxOddCount < 0) {
                maxOddCount += nums[left] % 2;
                left++;
            }
            subarrayCount += right - left + 1;
        }
        return subarrayCount;
    };
    
    if (k < 0) {
        return 0;
    } else if (k == 0) {
        return atMost(0);
    }
    return atMost(k) - atMost(k - 1);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << niceSubarrays(nums, k) << endl;
    return 0;
}