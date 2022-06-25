// 自力WA3

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if (n == 1) return target[0] == 1;
        ll sum = n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i=0; i<n; ++i) pq.emplace(target[i]-1, -1);
        while ((int)(pq.size()) > 1) {
            auto pi = pq.top(); pq.pop();
            int si = pi.first, vi = -pi.second;
            ll sub = sum - vi;
            if (si < sub) return false;
            sum += sub;
            if (si > sub) pq.emplace((int)(si-sub), -(int)(vi+sub));
        }
        ll sub = sum + pq.top().second;
        if (pq.top().first < sub) return false;
        return (pq.top().first%sub == 0);
    }
};
