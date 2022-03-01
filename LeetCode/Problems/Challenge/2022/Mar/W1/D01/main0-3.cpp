// 自力AC3,O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        int lid = 0;
        for (int i=1; i<=n; ++i,++lid) {
            if (lid*2 == i) lid = 0;
            res[i] = 1 + res[lid];
        }
        return res;
    }
};
