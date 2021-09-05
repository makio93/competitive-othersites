#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        vector<pair<int, int>> pro(n);
        for (int i=0; i<n; ++i) pro[i] = { properties[i][0], -properties[i][1] };
        sort(pro.begin(), pro.end());
        for (int i=0; i<n; ++i) pro[i].second *= -1;
        multiset<int> vals;
        int res = 0;
        for (int i=0; i<n; ++i) {
            res += distance(vals.begin(), vals.lower_bound(pro[i].second));
            vals.erase(vals.begin(), vals.lower_bound(pro[i].second));
            vals.insert(pro[i].second);
        }
        return res;
    }
};
