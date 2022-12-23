// 自力WA2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        sort(target.begin(), target.end());
        int li = 0;
        ll sum = n;
        if (n == 1) return (target[0] == 1);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<n; ++i) pq.push(1);
        while ((int)(pq.size()) > 1) {
            ll vi = pq.top(); pq.pop();
            if (vi < target[li]) {
                ll sub = sum - vi;
                vi = sum;
                sum += sub;
            }
            if (vi > target[li]) return false;
            if (vi == target[li]) ++li;
            else pq.push(vi);
        }
        if (pq.top() > target[li]) return false;
        ll tar = target[li] - pq.top(), sub = sum - pq.top();
        return (tar%sub == 0);
    }
};
