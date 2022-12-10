// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int n = strs.size(), res = 0;
        for (const string& si : strs) {
            int ccnt = 0;
            for (const char& ci : si) if (islower(ci)) ++ccnt;
            if (ccnt > 0) res = max(res, (int)(si.length()));
            else res = max(res, stoi(si));
        }
        return res;
    }
};
