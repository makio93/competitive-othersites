// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.front().size();
        vector<int> res = { -1, -1 };
        for (int i=0; i<m; ++i) {
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            if (res[1] < cnt) res = { i, cnt };
        }
        return res;
    }
};
