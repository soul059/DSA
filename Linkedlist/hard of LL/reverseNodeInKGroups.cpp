/*
 * REVERSE NODES IN K-GROUPS
 * 
 * Approach: 1. Count if K nodes exist
 *           2. Reverse K nodes
 *           3. Recursively process rest
 *           4. Connect reversed group with result
 * 
 * Time: O(n) | Space: O(n/k) for recursion stack
 * 
 * Note: Remaining nodes (< K) stay as-is
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
Node<int>* reverseLinkedList(Node<int>* head) {
    Node<int>* temp = head;
    Node<int>* prev = nullptr;
    while (temp != nullptr) {
        Node<int>* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node<int>* getKthNode(Node<int>* temp, int k) {
    k -= 1;
    while (temp != nullptr && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node<int>* kReverse(Node<int>* head, int k) {
    Node<int>* temp = head;
    Node<int>* prevLast = nullptr;

    while (temp != nullptr) {
        Node<int>* kThNode = getKthNode(temp, k);

        if (kThNode == nullptr) {
            if (prevLast) {
                prevLast->next = temp;
            }
            break;
        }

        Node<int>* nextNode = kThNode->next;
        kThNode->next = nullptr;

        reverseLinkedList(temp);

        if (temp == head) {
            head = kThNode;
        } else {
            prevLast->next = kThNode;
        }

        prevLast = temp;
        temp = nextNode;
    }
    return head;
}
int main(){
    LinkedList<int> ll;
    vector<int> arr = {1, 2, 3, 4, 5};
    ll.creatFromArray(arr);
    cout << "Original List: ";
    ll.display();
    int k = 2;
    Node<int>* newHead = kReverse(ll.getHead(), k);
    ll.setHead(newHead);
    cout << "List after reversing in groups of " << k << ": ";
    ll.display();
    ll.deleteList(); // Clean up the linked list
    return 0;
}