// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size(), res = 0;
        for (int i=0; i+2<n; ++i) res = max(res, abs(stones[i+2]-stones[i]));
        res = max(res, abs(stones[1]-stones[0]));
        res = max(res, abs(stones[n-1]-stones[n-2]));
        return res;
    }
};
