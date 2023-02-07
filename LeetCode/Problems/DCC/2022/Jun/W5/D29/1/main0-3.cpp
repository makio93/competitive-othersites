// 学習1回目,自力AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](auto& li, auto& ri) -> bool {
            return li[0] != ri[0] ? li[0] > ri[0] : li[1] < ri[1];
        });
        list<pair<int, int>> que;
        auto itr = que.begin();
        int qid = 0;
        for (int i=0; i<n; ++i) {
            while (itr!=que.end() && qid<people[i][1]) ++itr, ++qid;
            itr = que.emplace(itr, people[i][0], people[i][1]);
            ++itr, ++qid;
            if (i+1>=n || people[i+1][0]!=people[i][0]) {
                itr = que.begin();
                qid = 0;
            }
        }
        vector<vector<int>> res(n, vector<int>(2));
        int tcnt = 0;
        for (const auto& pi : que) {
            res[tcnt][0] = pi.first;
            res[tcnt][1] = pi.second;
            ++tcnt;
        }
        return res;
    }
};
