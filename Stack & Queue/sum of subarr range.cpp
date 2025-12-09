#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace  std;

vector<int> nse(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    vector<int> res(n);
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return res;
}

vector<int> psee(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[s.top()] > arr[i]) s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return res;
}

vector<int> pgee(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[s.top()] < arr[i]) s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return res;
}

vector<int> nge(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    vector<int> res(n);
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return res;
}

int sumSubarrayMaxs(vector<int>& arr) {
    int n = arr.size();
    vector<int> next = nge(arr);
    vector<int> prev = pgee(arr);
    long long mod = 1e9 + 7;
    long long res = 0;
    for(int i = 0; i < n; i++){
        long long left = (prev[i] == -1) ? (i + 1) : (i - prev[i]);
        long long right = (next[i] == -1) ? (n - i) : (next[i] - i);
        res = (res + (arr[i] * left * right) % mod) % mod;
    }
    return (int)res;
}

int sumSubarrayMins(vector<int>& arr){
    int n = arr.size();
    vector<int> next = nse(arr);
    vector<int> prev = psee(arr);
    long long mod = 1e9 + 7;
    long long res = 0;
    for(int i = 0; i < n; i++){
        long long left = (prev[i] == -1) ? (i + 1) : (i - prev[i]);
        long long right = (next[i] == -1) ? (n - i) : (next[i] - i);
        res = (res + (arr[i] * left * right) % mod) % mod;
    }
    return (int)res;
}

int sumSubarrayRanges(vector<int>& arr) {
    long long mod = 1e9 + 7;
    long long maxSum = sumSubarrayMaxs(arr);
    long long minSum = sumSubarrayMins(arr);
    long long res = (maxSum - minSum + mod) % mod;
    return (int)res;
}

int main(){
    int n;
    if(!(cin >> n)) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << sumSubarrayRanges(arr) << "\n";
    return 0;
}