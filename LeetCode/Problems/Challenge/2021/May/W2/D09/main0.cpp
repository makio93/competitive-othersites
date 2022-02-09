#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        ll sum = 0;
        for (int i=0; i<n; ++i) sum += target[i];
        priority_queue<int> pq;
        for (int i=0; i<n; ++i) if (target[i] > 1) pq.push(target[i]);
        while (!pq.empty()) {
            int tval = pq.top(); pq.pop();
            if (tval-(sum-tval)<1LL || (sum-tval)==0LL) return false;
            ll nval = tval % (sum-tval);
            if (nval == 0) nval += sum-tval;
            sum -= (tval-nval);
            if (nval > 1LL) pq.push((int)nval);
        }
        return true;
    }
};
