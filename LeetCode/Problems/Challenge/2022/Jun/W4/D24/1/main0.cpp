// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if (n == 1) return target[0] == 1;
        ll sum = accumulate(target.begin(), target.end(), 0LL);
        priority_queue<int> pq;
        for (int i=0; i<n; ++i) pq.push(target[i]);
        bool ok = true;
        while (pq.top() > 1) {
            int tval = pq.top(); pq.pop();
            int pval = tval;
            ll sub = sum - pval;
            if (pval-sub <= 0) {
                ok = false;
                break;
            }
            tval %= sub;
            if (tval == 0) tval += sub;
            sum -= pval - tval;
            pq.push(tval);
        }
        return ok;
    }
};
