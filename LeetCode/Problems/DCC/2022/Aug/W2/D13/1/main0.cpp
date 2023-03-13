// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), m = words.size(), k = words.front().length();
        vector<int> res;
        if (n < m*k) return res;
        unordered_map<string, int> wcnt, tcnt;
        for (int i=0; i<m; ++i) wcnt[words[i]]++;
        for (int i=0; i<k; ++i) {
            int ri = i, bcnt = 0;
            for (int j=i; j+m*k-1<n; j+=k) {
                while (ri-j < m*k) {
                    tcnt[s.substr(ri, k)]++;
                    if (tcnt[s.substr(ri, k)] > wcnt[s.substr(ri, k)]) ++bcnt;
                    ri += k;
                }
                if (bcnt == 0) res.push_back(j);
                if (tcnt[s.substr(j, k)] > wcnt[s.substr(j, k)]) --bcnt;
                tcnt[s.substr(j, k)]--;
            }
            tcnt.clear();
        }
        return res;
    }
};
