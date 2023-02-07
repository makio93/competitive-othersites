#include <bits/stdc++.h>
using namespace std;

// 解説AC

class RandomizedSet {
    unordered_map<int, int> vals;
    vector<int> vlst;
public:
    RandomizedSet() {
        srand(time(NULL));
        vals = unordered_map<int, int>();
        vlst = vector<int>();
    }
    bool insert(int val) {
        if (vals.find(val) == vals.end()) {
            vals[val] = vlst.size();
            vlst.push_back(val);
            return true;
        }
        else return false;
    }
    bool remove(int val) {
        if (vals.find(val) != vals.end()) {
            vals[vlst.back()] = vals[val];
            swap(vlst[vals[val]], vlst.back());
            vlst.pop_back();
            vals.erase(val);
            return true;
        }
        else return false;
    }
    int getRandom() { return vlst[(int)(rand())%vlst.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
