// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<pair<int, int>> slst(n);
        for (int i=0; i<n; ++i) slst[i] = { spells[i], i };
        sort(slst.begin(), slst.end());
        sort(potions.begin(), potions.end());
        vector<int> pairs(n);
        int ri = m;
        for (int i=0; i<n; ++i) {
            while (ri-1>=0 && (long long)slst[i].first*potions[ri-1]>=success) --ri;
            pairs[slst[i].second] = m - ri;
        }
        return pairs;
    }
};
