// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        map<int, set<pair<int, int>>> sche;
        for (int i=0; i<n; ++i) {
            sche[times[i][0]].emplace(1, i);
            sche[times[i][1]].emplace(-1, i);
        }
        set<int> chairs;
        vector<int> used(n, -1);
        for (int i=0; i<=n; ++i) chairs.insert(i);
        for (auto p : sche) {
            for (auto p2 : p.second) {
                if (p2.first == -1) chairs.insert(used[p2.second]);
                else {
                    used[p2.second] = *chairs.begin();
                    chairs.erase(chairs.begin());
                }
            }
        }
        return used[targetFriend];
    }
};
