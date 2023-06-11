// 解説AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class SnapshotArray {
    int cur_id;
    vector<vector<pair<int, int>>> hist;
public:
    SnapshotArray(int length) {
        cur_id = 0;
        hist.assign(length, { { cur_id, 0 } });
    }
    void set(int index, int val) {
        hist[index].emplace_back(cur_id, val);
    }
    int snap() {
        return cur_id++;
    }
    int get(int index, int snap_id) {
        return prev(upper_bound(hist[index].begin(), hist[index].end(), make_pair(snap_id, INF)))->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
