// 解説AC

#include <bits/stdc++.h>
using namespace std;

const int W = 20, M = 15;
class MyHashSet {
    vector<vector<int>> data;
public:
    MyHashSet() {
        data.resize(1<<M);
    }
    void add(int key) {
        int h = (key & ((1<<W) - 1)) >> (W-M);
        if (find(data[h].begin(), data[h].end(), key) == data[h].end()) data[h].push_back(key);
    }
    void remove(int key) {
        int h = (key & ((1<<W) - 1)) >> (W-M);
        if (find(data[h].begin(), data[h].end(), key) != data[h].end()) data[h].erase(find(data[h].begin(), data[h].end(), key));
    }
    bool contains(int key) {
        int h = (key & ((1<<W) - 1)) >> (W-M);
        return find(data[h].begin(), data[h].end(), key) != data[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
