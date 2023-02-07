// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](auto& li, auto& ri) -> bool {
            return li[0] != ri[0] ? li[0] < ri[0] : li[1] > ri[1];
        });
        vector<vector<int>> res(n);
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            for (int j=0; j<n; ++j) {
                if (res[j].empty()) {
                    if (cnt == people[i][1]) {
                        res[j] = people[i];
                        break;
                    }
                    ++cnt;
                }
            }
        }
        return res;
    }
};
