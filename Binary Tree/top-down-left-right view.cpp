#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
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

    void topView(vector<int>& result) {
        if (!root) return;

        map<int, int> topNode; // horizontal distance -> node value
        queue<pair<TreeNode*, int>> q; // node, horizontal distance

        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int hd = p.second;

            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = node->val;
            }

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto p : topNode) {
            result.push_back(p.second);
        }
    }

    void bottomView(vector<int>& result) {
        if (!root) return;

        map<int, int> bottomNode; // horizontal distance -> node value
        queue<pair<TreeNode*, int>> q; // node, horizontal distance

        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int hd = p.second;

            bottomNode[hd] = node->val;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto p : bottomNode) {
            result.push_back(p.second);
        }
    }

    void leftView(vector<int>& result) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* current = q.front();
                q.pop();
                if (i == 0) {
                    result.push_back(current->val);
                }
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
    }

    void rightView(vector<int>& result) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* current = q.front();
                q.pop();
                if (i == n - 1) {
                    result.push_back(current->val);
                }
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
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

int main() {
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    return 0;
}