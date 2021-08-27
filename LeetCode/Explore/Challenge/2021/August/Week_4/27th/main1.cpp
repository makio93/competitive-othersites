#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size(), res = -1;
        auto isSub = [&](int a, int b) -> bool {
            if (strs[a].length() > strs[b].length()) return false;
            int id = 0;
            for (char ci : strs[b]) if (ci == strs[a][id]) {
                ++id;
                if (id >= (int)(strs[a].length())) return true;
            }
            return false;
        };
        for (int i=0; i<n; ++i) {
            bool ok = true;
            for (int j=0; j<n; ++j) if (i != j) {
                if (isSub(i, j)) {
                    ok = false;
                    break;
                }
            }
            if (ok) res = max(res, (int)(strs[i].length()));
        }
        return res;
    }
};
