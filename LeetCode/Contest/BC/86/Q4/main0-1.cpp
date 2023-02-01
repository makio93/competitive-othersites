// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int li, int ri) -> bool {
            return chargeTimes[li] < chargeTimes[ri];
        });
        int li = 0, ri = n+1;
        while (ri-li > 1) {
            priority_queue<int> pq;
            ll csum = 0;
            int ci = li + (ri-li) / 2;
            bool ok = (ci == 0);
            if (ci > 0) {
                for (int i=0; i<ci; ++i) {
                    pq.push(runningCosts[ord[i]]);
                    csum += runningCosts[ord[i]];
                }
                if (csum*ci <= budget-chargeTimes[ord[ci-1]]) ok = true;
                for (int i=ci; i<n; ++i) {
                    pq.push(runningCosts[ord[i]]);
                    csum += runningCosts[ord[i]];
                    csum -= pq.top(); pq.pop();
                    if (csum*ci <= budget-chargeTimes[ord[i]]) ok = true;
                }
            }
            if (ok) li = ci;
            else ri = ci;
        }
        return li;
    }
};
