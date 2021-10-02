#include <bits/stdc++.h>
using namespace std;

const string tar = "TF";
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length(), res = 0;
        for (int i=0; i<2; ++i) {
            int sval = 0, r = 0;
            for (int l=0; l<n; ++l) {
                while (r<n && (answerKey[r]==tar[i]||(sval<k&&answerKey[r]!=tar[i]))) {
                    if (answerKey[r] != tar[i]) ++sval;
                    ++r;
                }
                res = max(res, r-l);
                if (answerKey[l] != tar[i]) --sval;
            }
        }
        return res;
    }
};
