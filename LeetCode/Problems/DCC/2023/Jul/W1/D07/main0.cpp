// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length(), res = 0, ri = 0, rcnt = 0;
        for (int i=0; i<n; ++i) {
            while (ri<n && (rcnt<k || (rcnt<=k && answerKey[ri]=='T'))) {
                if (answerKey[ri] == 'F') ++rcnt;
                ++ri;
            }
            res = max(res, ri-i);
            if (answerKey[i] == 'F') --rcnt;
        }
        ri = 0, rcnt = 0;
        for (int i=0; i<n; ++i) {
            while (ri<n && (rcnt<k || (rcnt<=k && answerKey[ri]=='F'))) {
                if (answerKey[ri] == 'T') ++rcnt;
                ++ri;
            }
            res = max(res, ri-i);
            if (answerKey[i] == 'T') --rcnt;
        }
        return res;
    }
};
