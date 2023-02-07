#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size(), m = searchWord.length();
        unordered_map<int, vector<string>> slst;
        set<string> rlst;
        for (int i=0; i<n; ++i) {
            int cnt = 0, len = products[i].length();
            for (int j=0; j<min(m,len); ++j) {
                if (searchWord[j] != products[i][j]) break;
                ++cnt;
            }
            slst[cnt].push_back(products[i]);
            if (cnt > 0) rlst.insert(products[i]);
        }
        vector<vector<string>> res(m);
        for (int i=0; i<m; ++i) {
            if (rlst.empty()) break;
            auto itr = rlst.begin();
            for (int j=0; j<3; ++j) {
                if (itr == rlst.end()) break;
                res[i].push_back(*itr);
                ++itr;
            }
            if (slst.find(i+1) != slst.end()) for (string si : slst[i+1]) rlst.erase(si);
        }
        return res;
    }
};
