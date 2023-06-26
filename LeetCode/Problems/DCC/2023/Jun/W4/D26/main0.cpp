// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = (int)(1e9);
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size(), li = 0, ri = n-1;
        priority_queue<int, vector<int>, greater<int>> lpq, rpq;
        lpq.push(INF);
        rpq.push(INF);
        while (li < candidates) {
            lpq.push(costs[li]);
            ++li;
        }
        while (ri >= n-candidates && ri >= li) {
            rpq.push(costs[ri]);
            --ri;
        }
        ll res = 0;
        for (int i=0; i<k; ++i) {
            if (lpq.top() <= rpq.top()) {
                res += lpq.top();
                lpq.pop();
                if (li <= ri) {
                    lpq.push(costs[li]);
                    ++li;
                }
            }
            else {
                res += rpq.top();
                rpq.pop();
                if (ri >= li) {
                    rpq.push(costs[ri]);
                    --ri;
                }
            }
        }
        return res;
    }
};
