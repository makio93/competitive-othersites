#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size(), res = 0;
        sort(cost.rbegin(), cost.rend());
        for (int i=0; i<n; ++i) if (i%3 != 2) res += cost[i];
        return res;
    }
};
