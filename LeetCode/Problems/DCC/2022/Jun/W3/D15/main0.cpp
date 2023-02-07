// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), m = 0;
        for (string& si : words) m = max(m, (int)(si.length()));
        vector<vector<int>> slst(m);
        for (int i=0; i<n; ++i) slst[words[i].length()-1].push_back(i);
        auto is_predecessor = [&](int fi, int ti) -> bool {
            int len = words[ti].length();
            for (int i=0; i<len; ++i) if (words[fi] == words[ti].substr(0, i)+words[ti].substr(i+1)) return true;
            return false;
        };
        vector<int> mvals(n, 1);
        for (int i=0; i<m-1; ++i) for (int li : slst[i]) {
            for (int ri : slst[i+1]) if (is_predecessor(li, ri)) 
                mvals[ri] = max(mvals[ri], mvals[li]+1);
        }
        int res = 0;
        for (int val : mvals) res = max(res, val);
        return res;
    }
};
