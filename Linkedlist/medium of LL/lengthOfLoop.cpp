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

int findLoopLength(Node<int>* slow, Node<int>* fast) {
    int length = 1;
    while (slow->next != fast) {
        slow = slow->next;
        length++;
    }
    return length;
}

int lengthOfLoop(Node<int>* head) {
    Node<int>* slow = head;
    Node<int>* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return findLoopLength(slow,fast);
    }
    return 0; // No loop
}

int main(){
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    Node<int>* head = list.getHead();
    // Creating a loop for testing
    head->next->next->next->next->next = head->next; //
    // 1 -> 2 -> 3 -> 4 -> 5 -> 2 (loop)
    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop detected." << endl;
    }
    return 0;
}