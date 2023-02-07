#include <bits/stdc++.h>
using namespace std;

// 自力AC1

using ll = long long;
class RandomizedSet {
    int sval;
    unordered_map<ll, int> vals;
    vector<ll> vlst;
public:
    RandomizedSet() {
        srand(time(NULL));
        sval = 0;
        vals = unordered_map<ll, int>();
        vlst = vector<ll>();
    }
    bool insert(int val) {
        if (vals.find(val) == vals.end()) {
            vals[val] = sval;
            vlst.push_back(val);
            ++sval;
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
            --sval;
            return true;
        }
        else return false;
    }
    int getRandom() { return vlst[(int)(rand())%sval]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
