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

/*
 Short documentation:

 - Purpose:
    Implements a simple binary tree with level-order insertion and checks whether
    the tree is symmetric (a mirror of itself about the root).

 - Key components:
    * TreeNode: node holding an int value and left/right pointers.
    * BinaryTree::insert: fills the tree in level order (not a BST).
    * BinaryTree::clear / ~BinaryTree: post-order deletion of nodes.
    * isSymmetricalUtil: recursively compares left and right subtrees in mirrored order.
    * isSymmetrical: entry point that returns true for an empty tree.

 - Correctness:
    The tree is symmetric iff for every pair of corresponding nodes:
      - both are null, or both non-null with equal values, and
      - their children are mirrors (left.left vs right.right and left.right vs right.left).

 - Complexity:
    Time: O(n) — every node visited at most once by the symmetry check.
    Space: O(h) recursion depth (h = tree height); insert uses O(n) queue temporarily.

 - Usage:
    Build the tree via BinaryTree::insert, then call isSymmetrical(root) to test symmetry.
*/

bool isSymmetricalUtil(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    
    return isSymmetricalUtil(left->left, right->right) &&
    isSymmetricalUtil(left->right, right->left);
}
bool isSymmetrical(TreeNode* root) {
    if (!root) return true;
    return isSymmetricalUtil(root->left, root->right);
}

int main(){ 
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(2);
    cout << "Is the binary tree symmetrical? " << (isSymmetrical(bt.root) ? "Yes" : "No") << endl;
    return 0;
}