// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](auto& li, auto& ri) -> bool {
            return li[0] != ri[0] ? li[0] > ri[0] : li[1] < ri[1];
        });
        vector<vector<int>> res;
        for (int i=0; i<n; ++i) res.insert(res.begin()+people[i][1], people[i]);
        return res;
    }
};
