// 終了後,自力,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        unordered_map<string, int> slst;
        for (int i=0; i<n; ++i) slst[ideas[i].substr(1)] |= (1<<(ideas[i][0]-'a'));
        vector<int> xlst;
        for (auto pi : slst) xlst.push_back(pi.second);
        int m = xlst.size();
        ll res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<m; ++j) res += __builtin_popcount(xlst[i]^xlst[j]);
        return res / 2;
    }
};
