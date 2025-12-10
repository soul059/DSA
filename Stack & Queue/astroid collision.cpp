#include<iostream>
#include<vector>
#include<algorithm>

using namespace  std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> stack;
    for(int i = 0; i < n; i++){
        int curr = asteroids[i];
        bool destroyed = false;
        while(!stack.empty() && curr < 0 && stack.back() > 0){
            if(stack.back() < -curr){
                stack.pop_back();
                continue;
            } else if(stack.back() == -curr){
                stack.pop_back();
            }
            destroyed = true;
            break;
        }
        if(!destroyed){
            stack.push_back(curr);
        }
    }
    return stack;
}

int main(){
    int n;
    cin >> n;
    vector<int> asteroids(n);
    for(int i = 0; i < n; i++){
        cin >> asteroids[i];
    }
    vector<int> result = asteroidCollision(asteroids);
    for(int val : result){
        cout << val << " ";
    }
    
    return 0;
}