#include <bits/stdc++.h>
using namespace std;

typedef list<int>::iterator lit;

class LRUCache {
   public:
    int capacity;
    map<int, pair<lit, int>> hmap;
    list<int> dll;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // check if the item in hmap -> if yes return its address
        if (hmap.find(key) != hmap.end()) {
            // some key has been accessed so it hot so we need to move to back of linked list to mark it hot
            dll.erase(hmap[key].first);

            // push to dll
            dll.push_front(key);

            // update the hashmap
            hmap[key].first = dll.begin();
            return hmap[key].second;
        }

        return -1;
    }

    void put(int key, int value) {
        // if item already exists -> update it in hashmap
        if (hmap.find(key) != hmap.end()) {
            dll.erase(hmap[key].first);
            dll.push_front(key);
            hmap[key].first = dll.begin();
            hmap[key].second = value;  // Update value here
        } else {
            // check if capacity is full -> remove from back
            if (dll.size() == capacity) {
                // whatever is at back we need to remove its reference at hmap
                int last = dll.back();
                dll.pop_back();
                hmap.erase(last);
            }

            dll.push_front(key);
            hmap[key] = {dll.begin(), value};  // Insert new key with value
        }
    }
};

int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);             // Cache is {1=1}
    obj->put(2, 2);             // Cache is {1=1, 2=2}
    int param_1 = obj->get(1);  // returns 1
    obj->put(3, 3);             // LRU key was 2, evicts key 2, Cache is {1=1, 3=3}
    int param_2 = obj->get(2);  // returns -1 (not found)
    obj->put(4, 4);             // LRU key was 1, evicts key 1, Cache is {4=4, 3=3}
    int param_3 = obj->get(1);  // returns -1 (not found)
    int param_4 = obj->get(3);  // returns 3
    int param_5 = obj->get(4);  // returns 4
}