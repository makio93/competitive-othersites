// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size(), m = searchWord.length();
        sort(products.begin(), products.end());
        string tmp = "";
        vector<vector<string>> res;
        int li = 0;
        for (int i=0; i<m; ++i) {
            tmp.push_back(searchWord[i]);
            int id = lower_bound(products.begin()+li, products.end(), tmp) - products.begin();
            res.push_back({});
            for (int j=0; j<3; ++j) {
                if (id+j>=n || products[id+j].substr(0,i+1)!=tmp) break;
                res.back().push_back(products[id+j]);
            }
            li = id;
        }
        return res;
    }
};
