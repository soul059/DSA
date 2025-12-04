/*
 * CLONE LINKED LIST WITH NEXT AND RANDOM POINTERS
 * 
 * Approach (O(1) space):
 * 1. Insert clone nodes between original nodes (A->A'->B->B')
 * 2. Set random pointers: clone.random = original.random.next
 * 3. Separate original and cloned lists
 * 
 * Time: O(n) | Space: O(1) excluding result
 * 
 * Alternative: Use HashMap to map original->clone nodes O(n) space
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* rendom;

    Node(T val) : data(val), next(nullptr),rendom(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}
    Node<T>* getHead() {
        return head;
    }
    void setHead(Node<T>* newHead) {
        head = newHead;
    }
    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
    void creatFromArray(const vector<T>& arr) {
        for (T val : arr) {
            insert(val);
        }
    }  
};

// Function to clone a linked list with next and random pointers
// This approach uses O(1) extra space (excluding the space for the new list)
Node<int>* cloneList(Node<int>* head) {
    if (!head) {
        return nullptr;
    }

    // Step 1: Create a copy of each node and insert it right after the original node.
    // This creates an interleaved list of original and copied nodes.
    Node<int>* current = head;
    while (current) {
        Node<int>* newNode = new Node<int>(current->data);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    // Step 2: Set the random pointers for the copied nodes.
    // The random pointer of a copied node should point to the copy of the node
    // that the original node's random pointer points to.
    current = head;
    while (current) {
        if (current->rendom) {
            current->next->rendom = current->rendom->next;
        }
        current = current->next->next;
    }

    // Step 3: Separate the original and cloned lists.
    // This involves restoring the 'next' pointers of the original list
    // and correctly setting the 'next' pointers of the cloned list.
    Node<int>* originalHead = head;
    Node<int>* clonedHead = head->next;
    Node<int>* clonedCurrent = clonedHead;

    while (originalHead) {
        originalHead->next = clonedCurrent->next;
        originalHead = originalHead->next;
        if (originalHead) {
            clonedCurrent->next = originalHead->next;
            clonedCurrent = clonedCurrent->next;
        }
    }

    return clonedHead;
}

int main(){
    // Create and populate the original list
    LinkedList<int> list;
    list.creatFromArray({1, 2, 3, 4, 5});
    Node<int>* head = list.getHead();

    // Set up random pointers for the original list
    // 1->3, 2->1, 3->5, 4->3, 5->2
    if (head && head->next && head->next->next && head->next->next->next && head->next->next->next->next) {
        head->rendom = head->next->next; // 1 -> 3
        head->next->rendom = head; // 2 -> 1
        head->next->next->rendom = head->next->next->next->next; // 3 -> 5
        head->next->next->next->rendom = head->next->next; // 4 -> 3
        head->next->next->next->next->rendom = head->next; // 5 -> 2
    }

    cout << "Original List:" << endl;
    Node<int>* temp = head;
    while (temp) {
        cout << "Node " << temp->data << ", Random -> " << (temp->rendom ? temp->rendom->data : 0) << endl;
        temp = temp->next;
    }

    // Clone the list
    Node<int>* clonedHead = cloneList(head);

    // Create a new LinkedList for the cloned list to manage its memory
    LinkedList<int> clonedList;
    clonedList.setHead(clonedHead);

    cout << "\nCloned List:" << endl;
    temp = clonedHead;
    while (temp) {
        cout << "Node " << temp->data << ", Random -> " << (temp->rendom ? temp->rendom->data : 0) << endl;
        temp = temp->next;
    }

    cout << "\nOriginal List (after cloning to show it's unchanged):" << endl;
    list.display();
    return 0;
}