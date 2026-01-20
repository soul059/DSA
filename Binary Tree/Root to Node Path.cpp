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



bool findPath(TreeNode* root, int target, vector< int >& path) {
    if (root == nullptr) {
        return 0;
    }
    
    path.push_back(root->val);
    
    if (root->val == target) {
        return 1;
    }
    
    if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
        return 1;
    }
    
    path.pop_back();
    return 0;
}

vector< int > rootToNodePath(TreeNode* root, int target) {
    vector< int > path;
    if (findPath(root, target, path)) {
        return path;
    }
    return {};
}

int main(){ 
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    int target = 5;
    vector< int > path = rootToNodePath(bt.root, target);
    if (!path.empty()) {
        cout << "Path from root to node " << target << ": ";
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "Node " << target << " not found in the tree." << endl;
    }
    
    return 0;
}