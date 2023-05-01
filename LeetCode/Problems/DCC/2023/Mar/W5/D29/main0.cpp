// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int sub = 0, val = 0, cnt = 0, mi = -1;
        for (int i=0; i<n; ++i) if (satisfaction[i] >= 0) {
            if (mi == -1) mi = i;
            ++cnt;
            val += satisfaction[i] * cnt;
            sub += satisfaction[i];
        }
        for (int i=mi-1; i>=0; --i) {
            if (sub+satisfaction[i] < 0) break;
            val += sub+satisfaction[i];
            sub += satisfaction[i];
        }
        return val;
    }
};
