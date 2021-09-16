#include <bits/stdc++.h>
using namespace std;

// 解説AC1

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        vector<int> res;
        int li = 0, ui = 0, ri = m-1, di = n-1;
        while ((int)(res.size()) < n*m) {
            for (int i=li; i<=ri; ++i) res.push_back(matrix[ui][i]);
            for (int i=ui+1; i<=di; ++i) res.push_back(matrix[i][ri]);
            if (di > ui) for (int i=ri-1; i>=li; --i) res.push_back(matrix[di][i]);
            if (ri > li) for (int i=di-1; i>=ui+1; --i) res.push_back(matrix[i][li]);
            ++li; ++ui; --ri; --di;
        }
        return res;
    }
};
