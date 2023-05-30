// 自力AC

#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
    int sz;
    vector<bool> exist;
public:
    MyHashSet() {
        sz = 1;
        exist.resize(sz);
    }
    void add(int key) {
        if (sz <= key) {
            exist.resize(key+1);
            sz = exist.size();
        }
        exist[key] = true;
    }
    void remove(int key) {
        if (key < sz) exist[key] = false;
    }
    bool contains(int key) {
        return key < sz && exist[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
