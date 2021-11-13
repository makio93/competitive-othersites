#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<pair<int, int>> plst(n);
        for (int i=0; i<n; ++i) plst[i] = { temperatures[i], -i };
        sort(plst.rbegin(), plst.rend());
        for (int i=0; i<n; ++i) plst[i].second *= -1;
        set<int> ids;
        vector<int> res(n);
        for (int i=0; i<n; ++i) {
            if (ids.upper_bound(plst[i].second) != ids.end()) res[plst[i].second] = *ids.upper_bound(plst[i].second) - plst[i].second;
            ids.insert(plst[i].second);
        }
        return res;
    }
};
