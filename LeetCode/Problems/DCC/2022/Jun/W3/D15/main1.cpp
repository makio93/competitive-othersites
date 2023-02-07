// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& lstr, string& rstr) -> bool {
            return lstr.length() < rstr.length();
        });
        unordered_map<string, int> dp;
        int res = 0;
        for (int i=0; i<n; ++i) {
            dp[words[i]] = max(dp[words[i]], 1);
            for (int j=0; j<(int)(words[i].length()); ++j) {
                string tmp = words[i].substr(0, j) + words[i].substr(j+1);
                if (dp.find(tmp) != dp.end()) dp[words[i]] = max(dp[words[i]], dp[tmp]+1);
            }
            res = max(res, dp[words[i]]);
        }
        return res;
    }
};
