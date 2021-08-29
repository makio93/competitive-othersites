#include <bits/stdc++.h>
using namespace std;

// 本番後,自力AC

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        set<map<int, int>> rest;
        map<int, int> tmp;
        tmp[0] = n;
        rest.insert(tmp);
        for (int i=0; i<n; ++i) {
            set<map<int, int>> rest2;
            for (auto pi : rest) for (auto pj : pi) {
                if (pj.first+tasks[i] > sessionTime) break;
                auto pi2 = pi;
                pi2[pj.first]--;
                if (pi2[pj.first] == 0) pi2.erase(pj.first);
                pi2[pj.first+tasks[i]]++;
                rest2.insert(pi2);
            }
            swap(rest2, rest);
        }
        int res = n;
        for (auto pi : rest) {
            int cnt = 0;
            for (auto pi2 : pi) if (pi2.first > 0) cnt += pi2.second;
            res = min(res, cnt);
        }
        return res;
    }
};
