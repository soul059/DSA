#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace  std;

/*
 * LRUCache

 * Problem:
 *   Implement a fixed-capacity key->value store that supports retrieval and insertion
 *   while evicting the least-recently-used (LRU) item when capacity is exceeded.

 * Approach:
 *   - Maintain usage order with a doubly-linked list (std::list) where the front is
 *     most-recently-used and the back is least-recently-used.
 *   - Maintain O(1) key lookup with a map from key -> iterator into the list.
 *   - get(key): if present, move the node to the front (most recent) using splice and
 *     return the pair; otherwise return a not-found marker.
 *   - put(key, value): if key exists, update value and move node to front; if new and
 *     capacity reached, evict the back(); then insert new node at front and record its iterator.
 *   - deleteKey(key): remove node and map entry if present.

 * Complexity:
 *   - get, put, deleteKey: O(1) average time (map lookup + list splice/erase/insert).
 *   - Space: O(capacity) for list + map.

 * Notes / Caveats:
 *   - Uses std::map for keyMap (log n lookups); for strict O(1) average use unordered_map.
 *   - Not thread-safe; concurrent access requires external synchronization.
 *   - Values are stored as int,int pairs here; generalize types or templating for reuse.
 */

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