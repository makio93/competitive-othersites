// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size(), m = (int)(1e5+5);
        vector<long long> sub(m+5);
        set<int> separated;
        for (int i=0; i<n; ++i) {
            sub[segments[i][0]] += segments[i][2];
            sub[segments[i][1]] -= segments[i][2];
            separated.insert(segments[i][0]);
            separated.insert(segments[i][1]);
        }
        for (int i=0; i<=m; ++i) sub[i+1] += sub[i];
        vector<vector<long long>> res;
        bool opened = false;
        int lid = 0;
        for (int i=1; i<=m; ++i) {
            if (sub[i-1] != sub[i]) {
                if (opened) {
                    int pi = lid;
                    auto itr = separated.upper_bound(lid);
                    while (itr!=separated.end() && *itr<i) {
                        res.push_back(vector<long long>{ pi, *itr, sub[i-1] });
                        pi = *itr;
                        ++itr;
                    }
                    res.push_back(vector<long long>{ pi, i, sub[i-1] });
                    if (sub[i] > 0) lid = i;
                    else opened = false;
                }
                else {
                    if (sub[i] > 0) {
                        lid = i;
                        opened = true;
                    }
                }
            }
        }
        return res;
    }
};
