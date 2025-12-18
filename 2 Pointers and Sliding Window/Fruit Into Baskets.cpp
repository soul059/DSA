#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace  std;

/*
Short description:
- Sliding-window to find longest subarray with at most 2 distinct fruit types.

Variables:
- left, right: window boundaries.
- count: frequency map for fruits in current window.
- uniqueFruits: number of distinct fruit types in window.
- maxFruits: best window length found.

Algorithm (brief):
1. Expand right, increment count for fruits[right]; if new type, increment uniqueFruits.
2. While uniqueFruits > 2, shrink from left, decrement counts and uniqueFruits when a count drops to 0.
3. After ensuring <=2 distinct types, update maxFruits with current window size.
4. Repeat until right reaches end.

Complexity:
- Time: O(n) (each element enters/leaves window at most once).
- Space: O(1) (map size <= 2 for this problem).
*/

int totalFruit(vector<int>& fruits) {
    int left = 0, right = 0;
    int maxFruits = 0;
    int uniqueFruits = 0;
    unordered_map<int, int> count;
    
    while(right < int(fruits.size())){
        count[fruits[right]]++;
        if(count[fruits[right]] == 1) {
            uniqueFruits++;
        }
        
        if(uniqueFruits > 2){
            count[fruits[left]]--;
            if(count[fruits[left]] == 0){
                uniqueFruits--;
            }
            left++;
        }

        if(uniqueFruits <= 2) maxFruits = max(maxFruits, right - left + 1);
        right++;
    }
    
    return maxFruits;
}

int main(){
    int n;
    cin >> n;
    vector<int> fruits(n);
    for(int i = 0; i < n; i++){
        cin >> fruits[i];
    } 
    cout << totalFruit(fruits) << "\n";
    return 0;
}