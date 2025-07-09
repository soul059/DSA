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

Node<int>* deleteAllOccurrencesOfK(DoublyLinkedList<int>& list, int k) {
    Node<int>* current = list.getHead();
    while (current) {
        if (current->data == k) {
            Node<int>* toDelete = current;
            current = current->next; // Move to the next node before deleting
            if (toDelete->prev) {
                toDelete->prev->next = toDelete->next;
            } else {
                list.deleteAtHead(); // If deleting the head
            }
            if (toDelete->next) {
                toDelete->next->prev = toDelete->prev;
            } else {
                list.deleteAtTail(); // If deleting the tail
            }
            delete toDelete;
        } else {
            current = current->next;
        }
    }
    return list.getHead();
}

int main(){
    DoublyLinkedList<int> list;
    list.insertAtHead(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(2);
    list.insertAtTail(5);
    cout << "Original List: ";
    list.display();
    int k = 2;
    cout << "Deleting all occurrences of " << k << ": ";
    deleteAllOccurrencesOfK(list, k);
    list.display();
    cout << "List after deletion: ";
    list.display();
    cout << "Head: " << (list.getHead() ? list.getHead()->data : -1) << endl;
    cout << "Tail: " << (list.getTail() ? list.getTail()->data : -1) << endl;
    list.deleteList(); // Clean up the list
    return 0;
}