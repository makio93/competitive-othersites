#include <bits/stdc++.h>
using namespace std;

// 自力AC2

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> arr(n*n);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) arr[i*n+j] = matrix[i][j];
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};
