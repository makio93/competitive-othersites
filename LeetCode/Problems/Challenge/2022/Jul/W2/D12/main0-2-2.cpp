// 自力TLE2-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), mval = 1, tmx = 1, thv = 1;
        int tar = 0;
        for (int val : matchsticks) tar += val;
        if (tar%4 != 0) return false;
        tar /= 4;
        for (int i=0; i<n; ++i) mval *= 3;
        unordered_map<int, unordered_set<int>> rlst;
        vector<int> sums;
        for (int i=0; i<mval; ++i) {
            sums.assign(2, 0);
            int bid = 0, ival = i;
            for (int j=0; j<n; ++j) {
                if (ival%3 > 0) {
                    sums[ival%3-1] += matchsticks[j];
                    bid |= (1<<j);
                }
                ival /= 3;
            }
            if (sums[0]==tar && sums[0]==sums[1]) rlst[sums[0]].insert(bid);
            if (i == tmx) {
                tmx = tmx * 3 + 2; thv *= 3;
                i = thv - 1;
            }
        }
        if (rlst.find(tar) == rlst.end()) return false;
        for (const int& val : rlst[tar]) {
            int tid = (~val) & ((1<<n)-1);
            if (rlst[tar].find(tid) != rlst[tar].end()) return true;
        }
        return false;
    }
};
