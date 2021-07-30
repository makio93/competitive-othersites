#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i=0; i<n; ++i) {
            auto tmp = res;
            reverse(tmp.begin(), tmp.end());
            for (int rv : tmp) res.push_back(rv+(1<<i));
        }
        return res;
    }
};
