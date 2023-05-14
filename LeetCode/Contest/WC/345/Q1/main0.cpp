// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> wins(n);
        wins[0] = true;
        int ball = 0, turn = 1;
        while (1) {
            ball = (ball + k * turn) % n;
            ++turn;
            if (wins[ball]) break;
            wins[ball] = true;
        }
        vector<int> res;
        for (int i=0; i<n; ++i) if (!wins[i]) res.push_back(i+1);
        return res;
    }
};
