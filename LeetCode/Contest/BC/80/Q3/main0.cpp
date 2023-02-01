// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<bool>> mps(128, vector<bool>(128));
        for (char ci='a'; ci<='z'; ++ci) mps[(int)ci][(int)ci] = true;
        for (char ci='A'; ci<='Z'; ++ci) mps[(int)ci][(int)ci] = true;
        for (char ci='0'; ci<='9'; ++ci) mps[(int)ci][(int)ci] = true;
        for (auto& pi : mappings) mps[(int)pi[0]][(int)pi[1]] = true;
        int n = s.length(), m = sub.length();
        for (int i=0; i+m-1<n; ++i) {
            bool ok = true;
            for (int j=0; j<m; ++j) if (!mps[(int)sub[j]][(int)s[i+j]]) {
                ok = false;
                break;
            }
            if (ok) return true;
        }
        return false;
    }
};
