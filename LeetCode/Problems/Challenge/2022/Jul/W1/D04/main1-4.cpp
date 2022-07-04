// 解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        int pval = 0, up = 0, down = 0, res = 0;
        auto sigma = [](int val) -> int { return val * (val+1) / 2; };
        for (int i=1; i<n; ++i) {
            int val = (ratings[i] > ratings[i-1]) ? 1 : (ratings[i] < ratings[i-1]) ? -1 : 0;
            if ((pval>0&&val==0) || (pval<0&&val>=0)) {
                res += sigma(up) + sigma(down) + (max(up, down) + 1) - 1;
                up = down = 0;
            }
            if (val > 0) ++up;
            else if (val < 0) ++down;
            else ++res;
            pval = val;
        }
        res += sigma(up) + sigma(down) + (max(up, down) + 1);
        return res;
    }
};
