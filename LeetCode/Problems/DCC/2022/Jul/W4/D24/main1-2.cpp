// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size();
        auto rsearch = [&](auto rsearch, int ui, int di) -> bool {
            if (di-ui+1 <= 0) return false;
            int mi = ui + (di-ui) / 2;
            auto itr = lower_bound(matrix[mi].begin(), matrix[mi].end(), target);
            if (itr!=matrix[mi].end() && *itr==target) return true;
            else return rsearch(rsearch, ui, mi-1) || rsearch(rsearch, mi+1, di);
        };
        return rsearch(rsearch, 0, m-1);
    }
};
