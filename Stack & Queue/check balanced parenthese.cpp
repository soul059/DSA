#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

bool isBalanced(const string& str) {
    vector<char> stack;
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push_back(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) return false;
            char top = stack.back();
            stack.pop_back();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main(){
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    if (isBalanced(expression)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }   
    return 0;
}