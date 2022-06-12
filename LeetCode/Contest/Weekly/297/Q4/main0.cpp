// 本番WA

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
        vector<int> bcnt(26), ccnt(26);
        for (int i=0; i<m; ++i) for (int j=0; j<26; ++j) if ((xlst[i]>>j)&1) {
            bcnt[j]++;
            ccnt[j] += __builtin_popcount(xlst[i]) - 1;
        }
        ll res = 0;
        for (int i=0; i<m; ++i) {
            int val = 0, sub = 0;
            for (int j=0; j<26; ++j) {
                if (!((xlst[i]>>j)&1)) val += bcnt[j];
                else sub += ccnt[j];
            }
            res += (ll)__builtin_popcount(xlst[i]) * val - sub + __builtin_popcount(xlst[i]) - 1;
        }
        ++res;
        return res;
    }
};
