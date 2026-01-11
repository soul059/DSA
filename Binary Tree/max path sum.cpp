#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace  std;

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


int maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    maxPathSumUtil(root, maxi);
    return maxi;
}

/*
 * Computes and updates the maximum path sum in a binary tree using a post-order traversal.

 * Algorithm (short):
 *  - Recurse left and right to obtain the maximum downward path sum from each child.
 *  - The best path that passes through the current node is node->val + left + right; update 'maxi'.
 *  - Return the maximum downward path sum starting at this node for use by its parent: node->val + max(left, right).

 * Parameters:
 *  - root: pointer to the current TreeNode.
 *  - maxi: reference to an integer that stores the global maximum path sum (updated in-place).

 * Return:
 *  - Maximum sum of a path that starts at 'root' and goes down to one of its children.

 * Example:
 *   Tree:   1
 *          / \
 *         2   3
 *   At root: left=2, right=3 -> candidateThroughRoot = 1+2+3 = 6 (may update maxi).
 *   Returned value for parent = 1 + max(2,3) = 4.

 * Note:
 *  - If negative child contributions should be excluded, clamp child results with max(0, child).
 */
int maxPathSumUtil(TreeNode* root, int& maxi) {
    if (!root) return 0;
    int leftDepth = maxPathSumUtil(root->left, maxi);
    int rightDepth = maxPathSumUtil(root->right, maxi);
    maxi = max(maxi, root->val + leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + root->val;
}

int main(){ 
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    cout << "Maximum path sum of the binary tree: " << maxPathSum(bt.root) << endl;
    return 0;
}