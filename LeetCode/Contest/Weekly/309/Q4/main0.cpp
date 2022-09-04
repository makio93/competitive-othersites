// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int> rcnt(n);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> sche;
        priority_queue<int, vector<int>, greater<int>> ids;
        sort(meetings.begin(), meetings.end());
        for (int i=0; i<n; ++i) ids.push(i);
        for (int i=0; i<m; ++i) {
            while (!sche.empty() && sche.top().first<=meetings[i][0]) {
                ids.push(sche.top().second); sche.pop();
            }
            if (!ids.empty()) {
                rcnt[ids.top()]++;
                sche.emplace(meetings[i][1], ids.top());
                ids.pop();
            }
            else {
                auto pi = sche.top(); sche.pop();
                rcnt[pi.second]++;
                sche.emplace(pi.first+(meetings[i][1]-meetings[i][0]), pi.second);
            }
        }
        pair<int, int> mval = { -1, -1 };
        for (int i=0; i<n; ++i) mval = max(mval, { rcnt[i], -i });
        return -mval.second;
    }
};
