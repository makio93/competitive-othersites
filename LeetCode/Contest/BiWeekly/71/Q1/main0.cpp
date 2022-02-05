#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits(4);
        for (int i=0; i<4; ++i) {
            digits[i] = num % 10;
            num /= 10;
        }
        vector<int> ord(4);
        for (int i=0; i<4; ++i) ord[i] = i;
        int res = (int)(1e9);
        do {
            vector<int> tdig(4);
            for (int i=0; i<4; ++i) tdig[i] = digits[ord[i]];
            for (int i=0; i<2; ++i) {
                int ai = 0, bi = 0;
                for (int j=0; j<4; ++j) {
                    if (j <= i) ai = ai * 10 + tdig[j];
                    else bi = bi * 10 + tdig[j];
                }
                res = min(res, ai+bi);
            }
        } while (next_permutation(ord.begin(), ord.end()));
        return res;
    }
};
