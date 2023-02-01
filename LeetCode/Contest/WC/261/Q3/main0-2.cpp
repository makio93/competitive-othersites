#include <bits/stdc++.h>
using namespace std;

// 本番後,自力AC

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        vector<int> mcnt(3);
        for (int i=0; i<n; ++i) mcnt[stones[i]%3]++;
        int tcnt1 = mcnt[0], tcnt2 = mcnt[0];
        if (mcnt[1] == 0) tcnt1 = 0;
        else {
            auto ccnt = mcnt;
            ++tcnt1;
            ccnt[1]--;
            tcnt1 += min(ccnt[1], ccnt[2]) * 2;
            int tmp = min(ccnt[1], ccnt[2]);
            ccnt[1] -= tmp; ccnt[2] -= tmp;
            if (ccnt[1] > 0) { ccnt[1]--; tcnt1++; }
        }
        if (mcnt[2] == 0) tcnt2 = 0;
        else {
            auto ccnt = mcnt;
            ++tcnt2;
            ccnt[2]--;
            tcnt2 += min(ccnt[1], ccnt[2]) * 2;
            int tmp = min(ccnt[1], ccnt[2]);
            ccnt[1] -= tmp; ccnt[2] -= tmp;
            if (ccnt[2] > 0) { ccnt[2]--; tcnt2++; }
        }
        bool ok = false;
        if (tcnt1%2==1 && tcnt1<n) ok = true;
        if (tcnt2%2==1 && tcnt2<n) ok = true;
        return ok;
    }
};
