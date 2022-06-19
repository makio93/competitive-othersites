// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size(), m = searchWord.length();
        sort(products.begin(), products.end());
        vector<vector<string>> res(m);
        for (int i=0; i<n; ++i) {
            int len = products[i].length();
            for (int j=0; j<min(m,len); ++j) {
                if (searchWord[j] != products[i][j]) break;
                if ((int)(res[j].size()) < 3) res[j].push_back(products[i]);
            }
        }
        return res;
    }
};
