// 学習1回目,自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size(), hmx = 0;
        for (int i=0; i<n; ++i) hmx = max(hmx, people[i][0]);
        vector<vector<int>> klst(hmx+1);
        for (int i=0; i<n; ++i) klst[people[i][0]].push_back(people[i][1]);
        vector<vector<int>> res, tmp;
        for (int i=hmx; i>=0; --i) if (!klst[i].empty()) {
            sort(klst[i].begin(), klst[i].end());
            int rlen = res.size(), id = 0, klen = klst[i].size();
            for (int j=0; j<rlen; ++j) {
                while (id<klen && (int)(tmp.size())==klst[i][id]) {
                    tmp.push_back({ i, klst[i][id] });
                    ++id;
                }
                tmp.push_back(res[j]);
            }
            while (id < klen) {
                tmp.push_back({ i, klst[i][id] });
                ++id;
            }
            swap(tmp, res);
            tmp.clear();
        }
        return res;
    }
};
