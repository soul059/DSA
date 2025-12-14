#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace  std;

class LRUCache {
    int capacity;
    list<pair<int, int>> cache; // stores {key, value}
    map<int, list<pair<int, int>>::iterator> keyMap; // maps key to its position in the list
public:
    LRUCache(int cap) : capacity(cap) {}
    pair<int, int> get(int key) {
        if (keyMap.find(key) == keyMap.end()) {
            return {-1, -1}; // Key not found
        }
        // Move the accessed item to the front of the list (most recently used)
        auto it = keyMap[key];
        cache.splice(cache.begin(), cache, it);
        return *it;
    }
    void put(int key, int value) {
        if (keyMap.find(key) != keyMap.end()) {
            // Key exists, update value and move to front
            auto it = keyMap[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
        } else {
            // Key does not exist
            if (cache.size() == capacity) {
                // Remove least recently used item
                auto lru = cache.back();
                keyMap.erase(lru.first);
                cache.pop_back();
            }
            // Insert new item at the front
            cache.emplace_front(key, value);
            keyMap[key] = cache.begin();
        }
    }
    void display() {
        for (const auto& p : cache) {
            cout << "{" << p.first << ": " << p.second << "} ";
        }
        cout << endl;
    }
    void deleteKey(int key) {
        if (keyMap.find(key) != keyMap.end()) {
            auto it = keyMap[key];
            cache.erase(it);
            keyMap.erase(key);
        }
    }
};

int main(){
    LRUCache lru(3);
    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);
    lru.display();
    lru.get(2);
    lru.display();
    lru.put(4, 40);
    lru.display();
    lru.deleteKey(3);
    lru.display();
    return 0;
}