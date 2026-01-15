#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace  std;

/** 
 * Traversal algorithm comments for BinaryTree implementation

 * General:
 * - TreeNode: simple binary tree node with int value and left/right pointers.
 * - BinaryTree::insert uses a level-order (BFS) approach to maintain a
 *   complete-tree-like insertion order.

 * 1) Level-order (BFS) used in insert, zigzag, and verticalOrder:
 *    - Concept: Visit nodes level by level using a queue.
 *    - Use-case:
 *        * insert: finds the first available child position (left then right).
 *        * zigzag/verticalOrder: processes nodes breadth-first while tracking
 *          level or coordinates.
 *    - Complexity: O(n) time, O(n) auxiliary space for the queue.
 
 * 2) Zigzag (spiral) level-order traversal (BinaryTree::zigzag):
 *    - Concept: BFS by levels but alternate output direction per level
 *      (left-to-right then right-to-left). Implementation here fills a
 *      temporary vector for each level and writes either forward or reversed
 *      depending on the current direction flag.
 *    - Use-case: Produces the "zigzag" order of node values.
 *    - Complexity: O(n) time, O(w) extra space per level (w = max width).

 * 3) Boundary traversal (BinaryTree::boundry with helpers leftBoundary,
 *    leaves, rightBoundary):
 *    - Concept: Output the root, then the left boundary top-down (excluding
 *      leaves), then all leaves left-to-right (via DFS), then the right
 *      boundary bottom-up (excluding leaves). Left/right boundary helpers
 *      recurse down one side choosing child preference to avoid leaves.
 *    - Use-case: Collects outermost nodes in anti-clockwise order.
 *    - Complexity: O(n) time, O(h) recursion stack (h = tree height).

 * 4) Leaves collection (BinaryTree::leaves):
 *    - Concept: DFS (inorder-style) recursion to visit nodes and append nodes
 *      that have no children (leaves).
 *    - Use-case: Utilized by boundary traversal to gather leaves in order.
 *    - Complexity: O(n) time, O(h) recursion stack.

 * 5) Vertical order traversal (BinaryTree::verticalOrder):
 *    - Concept: BFS while tracking (x,y) coordinates: x = horizontal distance
 *      from root, y = depth. Nodes are stored in a map<int, map<int, multiset<int>>>
 *      so they are output grouped by column (x), then row (y), and sorted by
 *      value when multiple nodes share (x,y).
 *    - Use-case: Produces column-wise ordering of nodes, with deterministic
 *      ordering for ties.
 *    - Complexity: O(n log n) time due to ordered maps/multisets, O(n) space.
 
 * 6) Post-order deletion (BinaryTree::clear / ~BinaryTree):
 *    - Concept: DFS post-order traversal to delete child subtrees before
 *      deleting the node itself (clear(left), clear(right), delete node).
 *    - Use-case: Safely frees all allocated nodes in destructor.
 *    - Complexity: O(n) time, O(h) recursion stack.

 * Notes:
 * - All recursive traversals use simple recursion and thus require O(h)
 *   call stack where h is the tree height.
 * - BFS-based traversals use a queue with worst-case O(n) space.
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

    
    void zigzag(vector<int>& result){
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();

                int index = leftToRight ? i : (size - 1 - i);
                row[index] = current->val;

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            leftToRight = !leftToRight;
            result.insert(result.end(), row.begin(), row.end());
        }
    }

private:
    void leftBoundary(TreeNode* node, vector<int>& result) {
        if (!node || (!node->left && !node->right)) return;
        result.push_back(node->val);
        if (node->left) leftBoundary(node->left, result);
        else leftBoundary(node->right, result);
    }

    void rightBoundary(TreeNode* node, vector<int>& result) {
        if (!node || (!node->left && !node->right)) return;
        if (node->right) rightBoundary(node->right, result);
        else rightBoundary(node->left, result);
        result.push_back(node->val);
    }

    void leaves(TreeNode* node, vector<int>& result) {
        if (!node) return;
        leaves(node->left, result);
        if (!node->left && !node->right) result.push_back(node->val);
        leaves(node->right, result);
    }
public:
    void boundry(vector<int>& result){
        if(!root) return;
        result.push_back(root->val);
        leftBoundary(root->left, result);
        leaves(root->left, result);
        leaves(root->right, result);
        rightBoundary(root->right, result);
    }

    
    void verticalOrder(vector<int>& result){
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            if(node->left) q.push({node->left, {x - 1, y + 1}});
            if(node->right) q.push({node->right, {x + 1, y + 1}});
        }

        for(auto p : nodes){
            for(auto q : p.second){
                for(auto val : q.second){
                    result.push_back(val);
                }
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

    vector<int> zigzagResult;
    bt.zigzag(zigzagResult);
    cout << "Zigzag Traversal: ";
    for (int val : zigzagResult) {
        cout << val << " ";
    }

    vector<int> boundaryResult;
    bt.boundry(boundaryResult);
    cout << "\nBoundary Traversal: ";
    for (int val : boundaryResult) {
        cout << val << " ";
    }

    vector<int> verticalResult;
    bt.verticalOrder(verticalResult);
    cout << "\nVertical Order Traversal: ";
    for (int val : verticalResult) {
        cout << val << " ";
    }
    
    return 0;
}