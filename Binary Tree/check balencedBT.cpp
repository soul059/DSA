#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace  std;

/*
 * Functions:
 *   - int balencedBTUtil(TreeNode* node)
 *       Purpose:
 *         Post-order helper that computes subtree height and detects imbalance.
 *       Behavior:
 *         - Returns height (>=0) of subtree if balanced.
 *         - Returns -1 as a sentinel if subtree is unbalanced.
 *       Implementation notes:
 *         1. Recursively obtain leftDepth = balencedBTUtil(node->left).
 *            If leftDepth == -1, propagate -1 upward immediately.
 *         2. Recursively obtain rightDepth = balencedBTUtil(node->right).
 *            If rightDepth == -1, propagate -1 upward immediately.
 *         3. If abs(leftDepth - rightDepth) > 1, return -1 (unbalanced).
 *         4. Otherwise return max(leftDepth, rightDepth) + 1 (height).

 *   - bool isBalanced(TreeNode* root)
 *       Purpose:
 *         Public API that returns true if the tree is height-balanced.
 *       Behavior:
 *         Calls balencedBTUtil(root) and checks that the result != -1.

 * Algorithm (short):
 *   Use a bottom-up DFS (post-order). For each node:
 *     - Compute heights of left and right subtrees.
 *     - If either subtree is already unbalanced (sentinel -1), propagate -1.
 *     - If |leftHeight - rightHeight| > 1, mark unbalanced by returning -1.
 *     - Else return max(leftHeight, rightHeight) + 1 as the subtree height.
 *   The tree is balanced iff the root call does not return -1.
 */

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;
    
    BinaryTree() {
        root = nullptr;
    }
    
    void insert(int value) {
        if (!root) {
            root = new TreeNode(value);
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (!current->left) {
                current->left = new TreeNode(value);
                return;
            } else {
                q.push(current->left);
            }
            
            if (!current->right) {
                current->right = new TreeNode(value);
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    void clear(TreeNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    ~BinaryTree() {
        clear(root);
    }
};

int balencedBTUtil(TreeNode* node) {
    if (!node) return 0;

    int leftDepth = balencedBTUtil(node->left);
    if (leftDepth == -1) return -1;

    int rightDepth = balencedBTUtil(node->right);
    if (rightDepth == -1) return -1;

    if (abs(leftDepth - rightDepth) > 1) return -1;

    return max(leftDepth, rightDepth) + 1;
}

bool isBalanced(TreeNode* root) {
    return balencedBTUtil(root) != -1;
}



int main(){
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    if(isBalanced(bt.root)){
        cout<<"The binary tree is balanced."<<endl;
    } else {
        cout<<"The binary tree is not balanced."<<endl;
    }
    return 0;
}