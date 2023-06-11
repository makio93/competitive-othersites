// 自力AC

#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
    int cur_id;
    unordered_map<int, map<int, int>> mp;
public:
    SnapshotArray(int length) {
        cur_id = 0;
    }
    void set(int index, int val) {
        mp[index][cur_id] = val;
    }
    int snap() {
        ++cur_id;
        return cur_id-1;
    }
    int get(int index, int snap_id) {
        auto itr = mp[index].upper_bound(snap_id);
        if (itr == mp[index].begin()) return 0;
        return prev(itr)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
