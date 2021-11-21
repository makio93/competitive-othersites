#include <bits/stdc++.h>
using namespace std;

// 自力AC

class RangeFreqQuery {
    unordered_map<int, vector<int>> vids;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i=0; i<n; ++i) vids[arr[i]].push_back(i);
    }
    int query(int left, int right, int value) {
        return (vids.find(value) == vids.end()) ? 0 : 
            (upper_bound(vids[value].begin(), vids[value].end(), right) 
            - lower_bound(vids[value].begin(), vids[value].end(), left));
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
