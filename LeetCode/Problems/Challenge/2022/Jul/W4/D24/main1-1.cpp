// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size(), ri = 0, ci = n-1;
        while (ri<m && ci>=0) {
            if (matrix[ri][ci] == target) return true;
            if (matrix[ri][ci] > target) --ci;
            else ++ri;
        }
        return false;
    }
};
