// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int& li, int& ri) -> bool {
            return (people[li][0] != people[ri][0]) ? people[li][0] > people[ri][0] : people[li][1] < people[ri][1];
        });
        vector<vector<int>> res;
        for (int i=0; i<n; ++i) {
            vector<vector<int>> nres;
            for (int j=0; j<people[ord[i]][1]; ++j) nres.push_back(res[j]);
            nres.push_back(people[ord[i]]);
            for (int j=people[ord[i]][1]; j<i; ++j) nres.push_back(res[j]);
            swap(res, nres);
        }
        return res;
    }
};
