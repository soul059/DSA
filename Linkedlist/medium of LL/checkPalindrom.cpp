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

Node<int>* reverse(Node<int>* head) {
    Node<int>* prev = nullptr;
    Node<int>* current = head;
    Node<int>* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev; // New head of the reversed list
}

bool isPalindrome(Node<int>* head) {
    Node<int>* slow = head;
    Node<int>* fast = head;

    // Find the middle of the linked list
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse the second half of the linked list
    Node<int>* newHead = reverse(slow->next);
    // Compare the first half and the reversed second half
    Node<int>* firstHalf = head;
    Node<int>* secondHalf = newHead; // This is the head of the reversed second half
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    // Restore the original list (optional)
    slow->next = reverse(newHead); // Restore the second half


    return true; // Is a palindrome
}

int main(){
    LinkedList<int> list;
    vector<int> arr = {1, 2, 3, 2, 1};
    list.creatFromArray(arr);
    list.display();
    if (isPalindrome(list.getHead())) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}