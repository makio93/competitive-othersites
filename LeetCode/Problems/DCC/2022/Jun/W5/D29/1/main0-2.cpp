// 学習1回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        map<int, set<int>> klst;
        for (int i=0; i<n; ++i) klst[people[i][0]].insert(people[i][1]);
        list<pair<int, int>> que;
        for (auto hitr=klst.rbegin(); hitr!=klst.rend(); ++hitr) {
            auto kitr = hitr->second.begin();
            int klen = hitr->second.size(), lcnt = 0;
            for (auto itr=que.begin(); itr!=que.end(); ++itr,++lcnt) {
                while (kitr!=hitr->second.end() && lcnt==*kitr) {
                    itr = que.emplace(itr, hitr->first, *kitr);
                    ++lcnt; ++kitr; ++itr;
                }
            }
            while (kitr!=hitr->second.end()) {
                que.emplace(que.end(), hitr->first, *kitr);
                ++kitr;
            }
        }
        vector<vector<int>> res(n);
        int tcnt = 0;
        for (const auto& pi : que) {
            res[tcnt] = vector<int>({ pi.first, pi.second });
            ++tcnt;
        }
        return res;
    }
};
