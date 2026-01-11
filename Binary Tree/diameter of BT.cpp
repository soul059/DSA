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

int diameterBT(TreeNode* root) {
    int diameter = 0;
    depthBT(root, diameter);
    return diameter;
}

/*
 * Compute the depth (height in nodes) of the binary tree rooted at `root`
 * and update `diameter` with the maximum number of edges on any path between two nodes.
 
 * @param root      pointer to the current TreeNode (nullptr for empty)
 * @param diameter  reference updated in-place to the maximum diameter (measured in edges)
 * @return          depth of the subtree rooted at `root` (0 for empty)
 * Time: O(n), Space: O(h) where h is tree height (recursion stack)
 */
int depthBT(TreeNode* root, int& diameter) {
    if (!root) return 0;
    int leftDepth = depthBT(root->left, diameter);
    int rightDepth = depthBT(root->right, diameter);

    diameter = max(diameter, leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + 1;
}

int main(){ 
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    cout << "Diameter of the binary tree: " << diameterBT(bt.root) << endl;
    return 0;
}