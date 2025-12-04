/*
 * SORT LINKED LIST OF 0s, 1s, AND 2s
 * 
 * Approach 1: Count 0s, 1s, 2s and overwrite data
 * Approach 2: Create 3 dummy lists, distribute nodes, connect them
 * 
 * Time: O(n) | Space: O(1)
 * 
 * Similar to Dutch National Flag problem
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
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
    void deleteHead() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteNode(T val) {
        if (!head) return;
        if (head->data == val) {
            deleteHead();
            return;
        }
        Node<T>* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }
    void deleteList() {
        while (head) {
            deleteHead();
        }
    }
    void deleteKthNode(int k) {
        if (k <= 0 || !head) return;
        if (k == 1) {
            deleteHead();
            return;
        }
        Node<T>* temp = head;
        for (int i = 1; i < k - 1 && temp->next; ++i) {
            temp = temp->next;
        }
        if (temp->next) {
            Node<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }
    void insertAtHead(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtTail(T val) {
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
    void insertAtK(T val, int k) {
        if (k <= 0) return;
        if (k == 1) {
            insertAtHead(val);
            return;
        }
        Node<T>* newNode = new Node<T>(val);
        Node<T>* temp = head;
        for (int i = 1; i < k - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (temp) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            delete newNode;
        }
    }
    void insertBeforevalue(T val, T target) {
        if (!head) return;
        if (head->data == target) {
            insertAtHead(val);
            return;
        }
        Node<T>* temp = head;
        while (temp->next && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next) {
            Node<T>* newNode = new Node<T>(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void insertAfterValue(T val, T target) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == target) {
                Node<T>* newNode = new Node<T>(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    ~LinkedList() {
        deleteList();
    }
};

LinkedList<int> sort0_1_2(LinkedList<int>& list) {
// Create dummy heads and tails for 0s, 1s, and 2s lists
Node<int> zeroDummy(0), oneDummy(0), twoDummy(0);
Node<int>* zeroTail = &zeroDummy;
Node<int>* oneTail = &oneDummy;
Node<int>* twoTail = &twoDummy;

Node<int>* curr = list.getHead();

// Partition nodes into three lists
while (curr) {
    if (curr->data == 0) {
        zeroTail->next = curr;
        zeroTail = zeroTail->next;
    } else if (curr->data == 1) {
        oneTail->next = curr;
        oneTail = oneTail->next;
    } else {
        twoTail->next = curr;
        twoTail = twoTail->next;
    }
    curr = curr->next;
}

// Connect the three lists
zeroTail->next = oneDummy.next ? oneDummy.next : twoDummy.next;
oneTail->next = twoDummy.next;
twoTail->next = nullptr;

// Create new LinkedList with sorted nodes
LinkedList<int> result;
result.deleteList(); // Ensure empty
Node<int>* sortedHead = zeroDummy.next;
while (sortedHead) {
    result.insertAtTail(sortedHead->data);
    sortedHead = sortedHead->next;
}
return result;
}

int main(){
    LinkedList<int> list;
    vector<int> arr = {1, 0, 2, 1, 0, 2, 1, 0, 2};
    list.creatFromArray(arr);
    cout << "Original List: ";
    list.display();
    LinkedList<int> sortedList = sort0_1_2(list);
    cout << "Sorted List: ";
    
    return 0;
}