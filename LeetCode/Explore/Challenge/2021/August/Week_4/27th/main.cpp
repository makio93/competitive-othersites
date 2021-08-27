#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        map<string, int> scnt;
        for (int i=0; i<n; ++i) scnt[strs[i]]++;
        vector<int> mid;
        for (auto p : scnt) if (p.second == 1) {
            for (int i=0; i<n; ++i) if (strs[i] == p.first) {
                mid.push_back(i);
                break;
            }
        }
        if (mid.empty()) return -1;
        int res = 0;
        for (int id : mid) {
            int len = strs[id].length();
            if (res >= len) continue;
            set<string> rest;
            rest.insert("");
            for (int i=0; i<len; ++i) {
                set<string> rest2;
                for (string si : rest) {
                    string tar = si + strs[id][i];
                    int li = tar.length();
                    bool ok = true;
                    for (int j=0; j<n; ++j) if (j != id) {
                        int id = 0;
                        for (char ci : strs[j]) {
                            if (ci == tar[id]) ++id;
                            if (id >= li) {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok) break;
                    }
                    if (ok) res = max(res, (int)(tar.length()));
                    rest2.insert(tar);
                }
                for (string si : rest) rest2.insert(si);
                swap(rest, rest2);
            }
        }
        return (res > 0) ? res : -1;
    }
};
