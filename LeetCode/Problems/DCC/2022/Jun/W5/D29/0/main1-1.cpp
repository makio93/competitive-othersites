// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](auto& vl, auto& vr) -> bool {
            return vl[0] != vr[0] ? vl[0] > vr[0] : vl[1] < vr[1];
        });
        vector<vector<int>> res;
        for (auto& vi : people) res.insert(res.begin()+vi[1], vi);
        return res;
    }
};
