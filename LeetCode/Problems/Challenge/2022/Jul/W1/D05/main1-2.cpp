// 解説AC2:O(n)解

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nst;
        for (int& val : nums) nst.insert(val);
        int res = 0;
        for (int& val : nums) if (nst.find(val-1) == nst.end()) {
            int cnt = 1, cur = val;
            while (nst.find(cur+1) != nst.end()) {
                ++cur;
                ++cnt;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
