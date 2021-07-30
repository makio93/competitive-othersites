#include <bits/stdc++.h>
using namespace std;

// 自力AC

class MapSum {
    unordered_map<string, int> data;
public:
    MapSum() {
        data = unordered_map<string, int>();
    }
    void insert(string key, int val) {
        data[key] = val;
    }
    int sum(string prefix) {
        int res = 0;
        for (auto p : data) if (p.first.length()>=prefix.length() && p.first.substr(0,prefix.length())==prefix) res += p.second;
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */