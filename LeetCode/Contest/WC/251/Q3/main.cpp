#include <bits/stdc++.h>
using namespace std;

class Solution {
    int bitcount(int val) {
        int res = 0;
        while (val > 0) {
            res += (val & 1);
            val >>= 1;
        }
        return res;
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = students.front().size();
        vector<int> xstu(m), xmen(m);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) xstu[i] |= (students[i][j]<<j);
            for (int j=0; j<n; ++j) xmen[i] |= (mentors[i][j]<<j);
        }
        vector<int> perm(m);
        for (int i=0; i<m; ++i) perm[i] = i;
        int mval = 0;
        do {
            int score = 0;
            for (int i=0; i<m; ++i) score += n - bitcount(xstu[i]^xmen[perm[i]]);
            mval = max(mval, score);
        } while (next_permutation(perm.begin(), perm.end()));
        return mval;
    }
};
