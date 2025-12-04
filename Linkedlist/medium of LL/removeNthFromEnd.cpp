/*
 * REMOVE NTH NODE FROM END
 * 
 * Approach: Two pointer technique
 * 1. Move fast pointer N steps ahead
 * 2. Move both pointers until fast reaches end
 * 3. Slow is now at (N+1)th from end - delete next node
 * 
 * Time: O(n) - Single pass | Space: O(1)
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

Node<int>* removeNthFromEnd(Node<int>* head, int n) {
    if (!head || n <= 0) return head;
    // Two pointer approach
    Node<int>* fast= head;
    Node<int>* slow = head;
    Node<int>* temp = nullptr;

    for (int i = 0; i < n; ++i) {
        if (fast) {
            fast = fast->next;
        } else {
            return head; // n is larger than the length of the list
        }
    }
    if (!fast) {
        // If fast is null, we need to remove the head
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    // Now slow is at the node before the one we want to remove
    temp = slow->next;
    slow->next = temp->next;
    delete temp;

    // Return the modified list
    return head;
}

int main(){
    LinkedList<int> list;
    vector<int> arr = {1, 2, 3, 4, 5};
    list.creatFromArray(arr);
    cout << "Original List: ";
    list.display();
    int n = 2; // Remove the 2nd node from the end
    Node<int>* modifiedHead = removeNthFromEnd(list.getHead(), n);
    list.setHead(modifiedHead);
    cout << "List after removing " << n << "th node from the end: ";
    list.display();
    list.deleteList(); // Clean up the list
    return 0;
}