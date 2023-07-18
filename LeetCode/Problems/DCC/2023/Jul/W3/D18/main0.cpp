// 自力AC(出題条件には失格)

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int time_id, capacity;
    unordered_map<int, pair<int, int>> cache;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
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
            if (cache.find(pq.top().second) != cache.end() && cache[pq.top().second].second == pq.top().first) cache.erase(pq.top().second);
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
