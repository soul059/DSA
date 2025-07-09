#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr) {}
};
template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;  
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    Node<T>* getHead() {
        return head;
    }
    Node<T>* getTail() {
        return tail;
    }
    void insertAtHead(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtTail(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
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
            newNode->prev = temp;
            if (temp->next) {
                temp->next->prev = newNode;
            } else {
                tail = newNode; // Update tail if inserting at the end
            }
            temp->next = newNode;
        } else {
            delete newNode; // If k is out of bounds, delete the new node
        }
    }
    void insertBeforeValue(T val, T target) {
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
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    void deleteAtHead() {
        if (!head) return;
        Node<T>* toDelete = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // If the list becomes empty, update tail
        }
        delete toDelete;
    }
    void deleteAtTail() {
        if (!tail) return;
        Node<T>* toDelete = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; // If the list becomes empty, update head
        }
        delete toDelete;
    }
    void deleteAtK(int k) {
        if (k <= 0 || !head) return;
        if (k == 1) {
            deleteAtHead();
            return;
        }
        Node<T>* temp = head;
        for (int i = 1; i < k && temp; ++i) {
            temp = temp->next;
        }
        if (temp) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next; // If deleting the head
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev; // If deleting the tail
            }
            delete temp;
        }
    }
    void display() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        tail = head; // Update tail to the current head
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            if (!current->prev) { // If we reach the new head
                head = current;
            }
            current = current->prev; // Move to the next node in the original order
        }
    }
    void deleteList() {
        while (head) {
            deleteAtHead();
        }
    }
    ~DoublyLinkedList() {
        deleteList();
    }
};

vector<pair<Node<int>*, Node<int>*>> findAllPairWithSum(DoublyLinkedList<int>& list, int targetSum) {
    Node<int>* left = list.getHead();
    Node<int>* right = list.getTail();
    vector<pair<Node<int>*, Node<int>*>> pairs;

    while (left && right && left != right && left->prev != right) {
        int currentSum = left->data + right->data;
        if (currentSum == targetSum) {
            pairs.push_back({left, right});
            left = left->next;
            right = right->prev;
        } else if (currentSum < targetSum) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }
    return pairs;
}


int main(){
    DoublyLinkedList<int> list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    list.insertAtTail(8);
    list.insertAtTail(9);
    list.insertAtTail(10);
    list.display();
    int targetSum = 10;
    auto result = findAllPairWithSum(list, targetSum);
    if (!result.empty()) {
        for (const auto& pair : result) {
            cout << "Pair found: (" << pair.first->data << ", " << pair.second->data << ")" << endl;
        }
    } else {
        cout << "No pairs found with sum " << targetSum << endl;
    }
    return 0;
}