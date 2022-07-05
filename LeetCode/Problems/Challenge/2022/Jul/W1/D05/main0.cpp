// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> ncnt;
        for (int& val : nums) ncnt[val] = false;
        int res = 0;
        for (int& val : nums) if (!ncnt[val]) {
            int tval = val;
            while (ncnt.find(tval-1) != ncnt.end()) --tval;
            int cnt = 0;
            while (ncnt.find(tval) != ncnt.end()) {
                ncnt[tval] = true;
                ++cnt; ++tval;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
