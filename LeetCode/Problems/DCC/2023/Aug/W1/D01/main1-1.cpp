// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> plst(k);
        int id = 0;
        while (id >= 0) {
            plst[id]++;
            if (plst[id] > n) --id;
            else if (id == k-1) res.push_back(plst);
            else {
                ++id;
                plst[id] = plst[id-1];
            }
        }
        return res;
    }
};
