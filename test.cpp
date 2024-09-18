#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

bool check(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;
        if(nums[left] < nums[right]){
            cout<<nums[left]<<","<<nums[right]<<"\t1"<<endl;
            for(int i=1;i<nums.size();i++){
                if(nums[i] < nums[i-1]) return false;
            }
        }
        else{
        while(left < right -1){
            cout<<nums[left]<<","<<nums[right]<<"\t2"<<endl;
            if(nums[left] <= nums[left+1] && nums[left] >= nums[right]) left++;
            else{
                cout<<nums[left]<<","<<nums[right]<<"\t3"<<endl;
                if(nums[right] >= nums[right-1] && nums[left] >= nums[right]) right--;
                else return false;
            }
        }
        }
        return true;
    }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    bool x = check(arr);
    cout<<x<<endl;
    return 0;
}