/*
 * MERGE K SORTED LINKED LISTS
 * 
 * Approach 1: Divide & Conquer - Pair up and merge like merge sort
 * Approach 2: Min-Heap - Push all heads, extract min, push its next
 * 
 * Time: O(N log K) where N=total nodes, K=number of lists
 * Space: O(K) for heap or O(log K) for recursion
 * 
 * Heap approach is preferred for large K
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

Node<int>* mergeTwoLists(Node<int>* l1, Node<int>* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Node<int>* mergedHead = nullptr;
    if (l1->data < l2->data) {
        mergedHead = l1;
        l1 = l1->next;
    } else {
        mergedHead = l2;
        l2 = l2->next;
    }

    Node<int>* current = mergedHead;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return mergedHead;
}

Node<int>* mergeKSortedLists(vector<Node<int>*> lists) {
    if (lists.empty()) return nullptr;

    while (lists.size() > 1) {
        vector<Node<int>*> mergedLists;
        for (size_t i = 0; i < lists.size(); i += 2) {
            if (i + 1 < lists.size()) {
                mergedLists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
            } else {
                mergedLists.push_back(lists[i]);
            }
        }
        lists = mergedLists;
    }

    return lists[0];
}

int main(){
    LinkedList<int> list1;
    list1.creatFromArray({1, 4, 5});
    LinkedList<int> list2;
    list2.creatFromArray({1, 3, 4});
    LinkedList<int> list3;
    list3.creatFromArray({2, 6});
    vector<Node<int>*> lists = {list1.getHead(), list2.getHead(), list3.getHead()};
    Node<int>* mergedListHead = mergeKSortedLists(lists);
    LinkedList<int> mergedList;
    mergedList.setHead(mergedListHead);
    cout << "\nList 1: ";
    list1.display();
    cout << "\nList 2: ";
    list2.display();
    cout << "\nList 3: ";
    list3.display();
    cout << "\nMerged List: ";
    mergedList.display();
    list1.deleteList();
    list2.deleteList();
    list3.deleteList();
    mergedList.deleteList();
    cout << "All lists deleted." << endl;
    return 0;
}