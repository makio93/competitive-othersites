// 解説AC

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int time_id, capacity;
    unordered_map<int, pair<int, int>> cache;
    queue<pair<int, int>> pq; 
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        time_id = 0;
    }    
    int get(int key) {
        ++time_id;
        if (cache.find(key) != cache.end()) {
            cache[key].second = time_id;
            pq.emplace(time_id, key);
            return cache[key].first;
        }
        else return -1;
    }
    void put(int key, int value) {
        ++time_id;
        cache[key] = { value, time_id };
        pq.emplace(time_id, key);
        while ((int)(cache.size()) > capacity) {
            if (cache.find(pq.front().second) != cache.end() && cache[pq.front().second].second == pq.front().first) cache.erase(pq.front().second);
            pq.pop();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
