#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get precedence of operators
// Higher value means higher precedence
int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if character is an operand (letter or digit)
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

/*
 * INFIX TO POSTFIX CONVERSION
 * Algorithm:
 * 1. Scan the infix expression from left to right
 * 2. If operand, add to output
 * 3. If '(', push to stack
 * 4. If ')', pop and add to output until '(' is found
 * 5. If operator, pop operators with higher or equal precedence, then push current operator
 * 6. Pop remaining operators from stack
 */
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // If operand, add to output
        if (isOperand(c)) {
            postfix += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop until '(' is found
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        }
        // If operator
        else if (isOperator(c)) {
            // Pop operators with higher or equal precedence (left-associative)
            // For '^' (right-associative), only pop if strictly greater
            while (!st.empty() && st.top() != '(' &&
                   ((c != '^' && getPrecedence(st.top()) >= getPrecedence(c)) ||
                    (c == '^' && getPrecedence(st.top()) > getPrecedence(c)))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

/*
 * INFIX TO PREFIX CONVERSION
 * Algorithm:
 * 1. Reverse the infix expression
 * 2. Replace '(' with ')' and vice versa
 * 3. Apply infix to postfix algorithm (with slight modification for right-associativity)
 * 4. Reverse the result to get prefix
 */
string infixToPrefix(string infix) {
    // Reverse the infix expression
    reverse(infix.begin(), infix.end());
    
    // Replace '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    
    stack<char> st;
    string prefix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if (isOperand(c)) {
            prefix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isOperator(c)) {
            // For prefix, use strictly greater (right-to-left associativity after reversal)
            while (!st.empty() && st.top() != '(' && getPrecedence(st.top()) > getPrecedence(c)) {
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }
    
    // Reverse to get prefix
    reverse(prefix.begin(), prefix.end());
    
    return prefix;
}

/*
 * POSTFIX TO INFIX CONVERSION
 * Algorithm:
 * 1. Scan postfix from left to right
 * 2. If operand, push to stack
 * 3. If operator, pop two operands, combine as (operand1 operator operand2), push result
 * 4. Final element in stack is the infix expression
 */
string postfixToInfix(string postfix) {
    stack<string> st;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (isOperand(c)) {
            // Push operand as string
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            // Pop two operands
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            
            // Combine with parentheses
            string result = "(" + operand1 + c + operand2 + ")";
            st.push(result);
        }
    }
    
    return st.top();
}

/*
 * PREFIX TO INFIX CONVERSION
 * Algorithm:
 * 1. Scan prefix from right to left
 * 2. If operand, push to stack
 * 3. If operator, pop two operands, combine as (operand1 operator operand2), push result
 * 4. Final element in stack is the infix expression
 */
string prefixToInfix(string prefix) {
    stack<string> st;
    
    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        if (isOperand(c)) {
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            // Pop two operands (order is different from postfix)
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();
            
            string result = "(" + operand1 + c + operand2 + ")";
            st.push(result);
        }
    }
    
    return st.top();
}

/*
 * POSTFIX TO PREFIX CONVERSION
 * Algorithm:
 * 1. Scan postfix from left to right
 * 2. If operand, push to stack
 * 3. If operator, pop two operands, combine as (operator + operand1 + operand2), push result
 * 4. Final element in stack is the prefix expression
 */
string postfixToPrefix(string postfix) {
    stack<string> st;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (isOperand(c)) {
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            
            // Prefix: operator comes first
            string result = c + operand1 + operand2;
            st.push(result);
        }
    }
    
    return st.top();
}

/*
 * PREFIX TO POSTFIX CONVERSION
 * Algorithm:
 * 1. Scan prefix from right to left
 * 2. If operand, push to stack
 * 3. If operator, pop two operands, combine as (operand1 + operand2 + operator), push result
 * 4. Final element in stack is the postfix expression
 */
string prefixToPostfix(string prefix) {
    stack<string> st;
    
    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        if (isOperand(c)) {
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();
            
            // Postfix: operator comes last
            string result = operand1 + operand2 + c;
            st.push(result);
        }
    }
    
    return st.top();
}

int main() {
    string infix = "A+B*(C-D)/E";
    string prefix = "*+AB-CD";
    string postfix = "AB+CD-*";
    
    cout << "========== EXPRESSION CONVERSIONS ==========" << endl << endl;
    
    // Infix conversions
    cout << "Original Infix: " << infix << endl;
    cout << "Infix to Postfix: " << infixToPostfix(infix) << endl;
    cout << "Infix to Prefix: " << infixToPrefix(infix) << endl;
    cout << endl;
    
    // Postfix conversions
    cout << "Original Postfix: " << postfix << endl;
    cout << "Postfix to Infix: " << postfixToInfix(postfix) << endl;
    cout << "Postfix to Prefix: " << postfixToPrefix(postfix) << endl;
    cout << endl;
    
    // Prefix conversions
    cout << "Original Prefix: " << prefix << endl;
    cout << "Prefix to Infix: " << prefixToInfix(prefix) << endl;
    cout << "Prefix to Postfix: " << prefixToPostfix(prefix) << endl;
    cout << endl;
    
    // Interactive testing
    cout << "========== INTERACTIVE TEST ==========" << endl;
    cout << "Enter an infix expression (e.g., (A+B)*C): ";
    string userInfix;
    cin >> userInfix;
    
    cout << "Postfix: " << infixToPostfix(userInfix) << endl;
    cout << "Prefix: " << infixToPrefix(userInfix) << endl;
    
    return 0;
}