#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        map<int, multiset<int, greater<int>>> sub;
        for (int i=0; i<n; ++i) {
            sub[firstList[i][0]].insert(1);
            sub[firstList[i][1]].insert(-1);
        }
        for (int i=0; i<m; ++i) {
            sub[secondList[i][0]].insert(1);
            sub[secondList[i][1]].insert(-1);
        }
        vector<vector<int>> res;
        bool start = false;
        int level = 0;
        for (auto pi : sub) {
            for (int val : pi.second) {
                level += val;
                if (level == 2) {
                    if (!start) {
                        start = true;
                        res.push_back(vector<int>({ pi.first }));
                    }
                }
                else {
                    if (start) {
                        start = false;
                        res.back().push_back(pi.first);
                    }
                }
            }
        }
        return res;
    }
};
