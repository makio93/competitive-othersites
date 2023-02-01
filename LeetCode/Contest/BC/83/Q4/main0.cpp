// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int res = 1;
        unordered_set<int> vst;
        for (int val : rolls) {
            vst.insert(val);
            if ((int)(vst.size()) == k) {
                ++res;
                vst.clear();
            }
        }
        return res;
    }
};
