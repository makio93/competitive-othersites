// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& lst, string& rst) -> bool { return lst.length() < rst.length(); });
        auto is_predecessor = [&](int fi, int ti) -> bool {
            int llen = words[fi].length(), len = words[ti].length();
            if (llen+1 != len) return false;
            for (int i=0; i<len; ++i) if (words[fi] == words[ti].substr(0, i)+words[ti].substr(i+1)) return true;
            return false;
        };
        vector<int> dp(n, 1);
        for (int i=0; i<n; ++i) for (int j=0; j<i; ++j) if (is_predecessor(j, i)) dp[i] = max(dp[i], dp[j]+1);
        int res = 0;
        for (int i=0; i<n; ++i) res = max(res, dp[i]);
        return res;
    }
};
