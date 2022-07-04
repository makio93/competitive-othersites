// 解説1改良版:AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> vals(n, 1);
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i=0; i<n; ++i) {
                if (i-1>=0 && ratings[i]>ratings[i-1] && vals[i]<=vals[i-1]) {
                    changed = true;
                    vals[i] = vals[i-1] + 1;
                }
                if (i+1<n && ratings[i]>ratings[i+1] && vals[i]<=vals[i+1]) {
                    changed = true;
                    vals[i] = vals[i+1] + 1;
                }
            }
            if (!changed) break;
            for (int i=n-1; i>=0; --i) {
                if (i-1>=0 && ratings[i]>ratings[i-1] && vals[i]<=vals[i-1]) {
                    changed = true;
                    vals[i] = vals[i-1] + 1;
                }
                if (i+1<n && ratings[i]>ratings[i+1] && vals[i]<=vals[i+1]) {
                    changed = true;
                    vals[i] = vals[i+1] + 1;
                }
            }
        }
        return accumulate(vals.begin(), vals.end(), 0);
    }
};
