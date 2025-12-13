#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/* Algorithm (short):
- Use a monotonic increasing stack of characters.
- Iterate digits of num:
    * While k>0 and stack not empty and top > current digit: pop and k--
    * Push current digit
- If k>0 after iteration: pop k digits from stack end
- Remove leading '0's from stack
- Convert remaining chars to vector<int>; if empty, return {0}
*/

vector<int> removeKdigits(const string& num, int k){
    vector<char> stack;
    for(char digit : num){
        while(k > 0 && !stack.empty() && stack.back() > digit){
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }
    while(k > 0 && !stack.empty()){
        stack.pop_back();
        k--;
    }
    // Remove leading zeros
    int index = 0;
    while(index < stack.size() && stack[index] == '0'){
        index++;
    }
    vector<int> result;
    for(int i = index; i < stack.size(); i++){
        result.push_back(stack[i] - '0');
    }
    if(result.empty()){
        result.push_back(0);
    }
    return result;
}

int main(){
    string num;
    int k;
    cin >> num >> k;
    vector<int> result = removeKdigits(num, k);
    for(int digit : result){
        cout << digit;
    }
    cout << endl;
    return 0;
}