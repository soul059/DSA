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

    void inorderTraversal(TreeNode* node, vector<int>& result) {
        if (!node) return;
        inorderTraversal(node->left, result);
        result.push_back(node->val);
        inorderTraversal(node->right, result);
    }

    void preorderTraversal(TreeNode* node, vector<int>& result) {
        if (!node) return;
        result.push_back(node->val);
        preorderTraversal(node->left, result);
        preorderTraversal(node->right, result);
    }

    void postorderTraversal(TreeNode* node, vector<int>& result) {
        if (!node) return;
        postorderTraversal(node->left, result);
        postorderTraversal(node->right, result);
        result.push_back(node->val);
    }
    
    
    void bfsTraversal(vector<int>& result) {
        if (!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    vector<int> getInorder() {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }

    vector<int> getPreorder() {
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }

    vector<int> getPostorder() {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }

    vector<int> getBFS() {
        vector<int> result;
        bfsTraversal(result);
        return result;
    }



    void itrativeInorderTraversal(vector<int>& result) {
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }
    }

    void itrativePreorderTraversal(vector<int>& result) {
        if (!root) return;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            result.push_back(current->val);

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
    }

    void itrativePostorderTraversal(vector<int>& result) {
        if (!root) return;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left) s1.push(current->left);
            if (current->right) s1.push(current->right);
        }

        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
    }

    vector<int> getItrativeInorder() {
        vector<int> result;
        itrativeInorderTraversal(result);
        return result;
    }

    vector<int> getItrativePreorder() {
        vector<int> result;
        itrativePreorderTraversal(result);
        return result;
    }

    vector<int> getItrativePostorder() {
        vector<int> result;
        itrativePostorderTraversal(result);
        return result;
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


int main(){
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);

    vector<int> inorder = bt.getInorder();
    cout << "Inorder Traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    vector<int> preorder = bt.getPreorder();
    cout << "Preorder Traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> postorder = bt.getPostorder();
    cout << "Postorder Traversal: ";
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> bfs = bt.getBFS();
    cout << "BFS Traversal: ";
    for (int val : bfs) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}