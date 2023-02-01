#include <bits/stdc++.h>
using namespace std;

// 本番後WA

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, pair<unordered_set<string>, unordered_set<int>>> g;
        set<int> leafs;
        for (int i=0; i<n; ++i) leafs.insert(i);
        for (int i=0; i<n; ++i) {
            string now = paths[i].front();
            int plen = paths[i].size();
            for (int j=0; j<plen-1; ++j) {
                if (g.find(now) != g.end()) for (int sid : g[now].second) leafs.erase(sid);
                g[now].first.insert(paths[i][j+1]);
                now = paths[i][j+1];
            }
            g[now].second.insert(i);
        }
        unordered_map<string, unordered_map<string, unordered_set<int>>> dict;
        for (int lid : leafs) {
            int slen = paths[lid].size();
            for (int i=slen-1; i>=0; --i) {
                string to = (i>0) ? paths[lid][i-1] : string("/");
                dict[paths[lid][i]][to].insert(lid);
            }
        }
        set<vector<string>> rst;
        for (int lid : leafs) {
            vector<string> rstr;
            int slen = paths[lid].size();
            bool skipping = true;
            for (int i=slen-1; i>=0; --i) {
                string to = (i>0) ? paths[lid][i-1] : string("/");
                if (skipping && (int)(dict[paths[lid][i]][to].size())<=1) {
                    skipping = false;
                    continue;
                }
                if (!skipping) rstr.push_back(paths[lid][i]);
            }
            reverse(rstr.begin(), rstr.end());
            vector<string> tstr;
            for (string ri : rstr) {
                tstr.push_back(ri);
                rst.insert(tstr);
            }
        }
        vector<vector<string>> res;
        for (auto vsi : rst) res.push_back(vsi);
        return res;
    }
};
