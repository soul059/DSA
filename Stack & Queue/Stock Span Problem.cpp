#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace  std;
/* Algorithm (short form):
- Initialize empty stack of pairs {price, index} and span vector of size n.
- For each index i from 0 to n-1:
    - While stack not empty and stack.top().first <= price[i], pop.
    - If stack empty: span[i] = i + 1; else span[i] = i - stack.top().second.
    - Push {price[i], i} onto stack.
- Complexity: O(n) time, O(n) extra space.
*/

vector<int> stockSpan(vector<int> &price){
    int n = price.size();
    stack<pair<int,int>> st; // {price, index}
    vector<int> span(n,1);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first <= price[i]){
            st.pop();
        }
        if(!st.empty()){
            span[i] = i - st.top().second;
        } else {
            span[i] = i + 1;
        }
        st.push({price[i], i});
    }
    return span;
}

int main(){
    int n;
    cin >> n;
    vector<int> price(n);
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    vector<int> result = stockSpan(price);
    for(int span : result){
        cout << span << " ";
    }
    cout << endl;
    return 0;
}