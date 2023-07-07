// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length(), res = k, tcnt = 0, fcnt = 0;
        for (int i=0; i<k; ++i) {
            if (answerKey[i] == 'T') ++tcnt;
            else ++fcnt;
        }
        int li = 0;
        for (int ri=k; ri<n; ++ri) {
            if (answerKey[ri] == 'T') ++tcnt;
            else ++fcnt;
            while (min(tcnt, fcnt) > k) {
                if (answerKey[li] == 'T') --tcnt;
                else --fcnt;
                ++li;
            }
            res = max(res, ri-li+1);
        }
        return res;
    }
};
