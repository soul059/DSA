
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace  std;

/*

 * @class MinStack1

 * @brief A stack data structure that supports retrieving the minimum element in O(1) time.
 
 * Uses a stack of pairs where each pair stores (value, current_minimum).
 * Space complexity: O(n) due to storing min with each element.
 
 * @method MinStack1() - Default constructor, initializes empty stack.
 * @method MinStack1(stack<pair<int,int>> st) - Constructor that initializes with given stack.
 * @method push(int val) - Pushes value onto stack, tracking current minimum. O(1) time.
 * @method pop() - Removes top element from stack. O(1) time.
 * @method top() - Returns top element value, or -1 if empty. O(1) time.
 * @method getMin() - Returns minimum element in stack, or -1 if empty. O(1) time.
 * 
 */
class MinStack1 {
public:
    stack<pair<int, int>> s;
    MinStack1() {
        
    }

    MinStack1(stack<pair<int, int>> st) {
        s = st;
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
        } else {
            int currentMin = s.top().second;
            s.push({val, min(val, currentMin)});
        }
    }
    
    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }
    
    int top() {
        if (!s.empty()) {
            return s.top().first;
        }
        return -1; // or throw an exception
    }
    
    int getMin() {
        if (!s.empty()) {
            return s.top().second;
        }
        return -1; // or throw an exception
    }
};


/*
 * @class MinStack2
 * @brief Stack supporting push, pop, top and getMin in O(1) time and O(1) extra space.

 * Uses an encoding trick to avoid storing auxiliary minimums:
 * - Maintains an integer `min` holding the current minimum.
 * - On push(val):
 *     - If stack is empty: set min = val and push(val).
 *     - If val < min: push(encoded = 2*val - min) and set min = val.
 *     - Otherwise: push(val).
 *   Encoded values are strictly less than the current min, allowing detection of
 *   when the top element is an encoded placeholder for a previous minimum.

 * - On pop():
 *     - If top < min, the popped value was encoded. Recover previous min as:
 *         prev_min = 2*min - top;
 *       and update min = prev_min.
 *     - Otherwise, just pop normally.

 * - On top():
 *     - If top < min, the logical top value is min (the encoded value represents it).
 *     - Otherwise, return the top as stored.

 * - getMin(): return current min.
 *
 * Complexity:
 * - Time: O(1) amortized for push/pop/top/getMin.
 * - Space: O(n) for the stack; no extra stack or per-element min stored (O(1) extra space).

 * Edge cases / behavior:
 * - Methods in the referenced implementation return -1 when the stack is empty
 *   (could alternatively throw).
 * - The encoding uses 2*val - min; this can overflow 32-bit int for large values.
 *   Consider using a larger integer type (e.g., long long) or explicit overflow checks
 *   in safety-critical code.

 * Invariant:
 * - After every operation, `min` equals the minimum of all logical elements currently in the stack.
 */

class MinStack2 {
    int min = INT_MAX;
    stack<int> s;
public:
    MinStack2() {
        
    }
    void push(int val){
        if(s.empty()){
            min = val;
            s.push(val);
            return;
        }
        if(val < min){
            min = val;
            s.push(2*val - min);
            return;
        }
        s.push(val);
    }

    void pop(){
        if(s.empty()) return;
        int top = s.top();
        s.pop();
        if(top < min){
            min = 2*min - top;
        }
    }

    int top(){
        if(s.empty()) return -1;
        int top = s.top();
        if(top < min){
            return min;
        }
        return top;
    }

    int getMin(){
        if(s.empty()) return -1;
        return min;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    MinStack1 minstack1 = MinStack1();
    for (int i = 0; i < n; i++){
        minstack1.push(arr[i]);
    }

    MinStack2 minstack2 = MinStack2();
    for (int i = 0; i < n; i++){
        minstack2.push(arr[i]);
    }

    cout<<"MinStack1 Minimum: "<<minstack1.getMin()<<endl;
    cout<<"MinStack2 Minimum: "<<minstack2.getMin()<<endl;
    cout<<"Top of MinStack1: "<<minstack1.top()<<endl;
    cout<<"Top of MinStack2: "<<minstack2.top()<<endl;
    cout<<"Popping from both stacks..."<<endl;
    minstack1.pop();
    minstack2.pop();
    cout<<"MinStack1 Minimum after pop: "<<minstack1.getMin()<<endl;
    cout<<"MinStack2 Minimum after pop: "<<minstack2.getMin()<<endl;
   
    

    return 0;
}