#include <bits/stdc++.h>
using namespace std;

// 解説AC1-1

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), res = 0;
        vector<string> slst({""});
        for (string ai : arr) {
            int slen = slst.size();
            for (int i=0; i<slen; ++i) {
                string ti = ai + slst[i];
                unordered_set<char> tst(ti.begin(), ti.end());
                if (tst.size() == ti.length()) {
                    slst.push_back(ti);
                    res = max(res, (int)(ti.length()));
                }
            }
        }
        return res;
    }
};
