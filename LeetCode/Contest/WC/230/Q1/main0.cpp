// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        const vector<string> rules = { "type", "color", "name" };
        int n = items.size(), res = 0, rule = -1;
        for (int i=0; i<3; ++i) if (ruleKey == rules[i]) rule = i;
        for (int i=0; i<n; ++i) if (items[i][rule] == ruleValue) ++res;
        return res;
    }
};
