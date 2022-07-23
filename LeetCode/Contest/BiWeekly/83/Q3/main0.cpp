// 本番AC

#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
    unordered_map<int, int> vals;
    unordered_map<int, set<int>> indices;
public:
    NumberContainers() {}
    void change(int index, int number) {
        if (vals.find(index) != vals.end()) {
            indices[vals[index]].erase(index);
            if (indices[vals[index]].empty()) indices.erase(vals[index]);
        }
        vals[index] = number;
        indices[number].insert(index);
    }
    int find(int number) {
        if (indices.find(number) != indices.end()) return *indices[number].begin();
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
