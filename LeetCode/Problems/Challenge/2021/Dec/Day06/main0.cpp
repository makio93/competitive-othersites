#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size(), cnt = 0;
        for (int i=0; i<n; ++i) if (position[i]%2 == 0) ++cnt;
        return min(cnt, n-cnt);
    }
};
