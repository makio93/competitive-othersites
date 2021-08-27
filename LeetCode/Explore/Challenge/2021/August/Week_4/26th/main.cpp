#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        vector<int> vals;
        int tval = 0;
        for (int i=0; i<n; ++i) {
            if (preorder[i] == '#') tval = -1;
            else if (preorder[i] == ',') {
                vals.push_back(tval);
                tval = 0;
            }
            else tval = tval * 10 + (preorder[i]-'0');
        }
        vals.push_back(tval);
        int m = vals.size();
        stack<pair<int, int>> dfs;
        dfs.emplace(vals.front(), 0);
        int id = 1;
        while (!dfs.empty()) {
            while (!dfs.empty() && (dfs.top().first==-1||(dfs.top().first!=-1&&dfs.top().second==2))) dfs.pop();
            if (dfs.empty() || (!dfs.empty()&&id>=m)) break;
            dfs.top().second++;
            dfs.emplace(vals[id], 0);
            ++id;
        }
        return (id==m && dfs.empty());
    }
};
