#include <bits/stdc++.h>
using namespace std;

// 解説AC1-2

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), res = 0;
        unordered_set<int> slst({0});
        for (string ai : arr) {
            int cset = 0;
            bool ok = true;
            for (char ci : ai) {
                if ((cset>>(ci-'a'))&1) {
                    ok = false;
                    break;
                }
                cset |= (1<<(ci-'a'));
            }
            if (!ok) continue;
            unordered_set<int> nlst;
            for (int si : slst) {
                if (si & cset) continue;
                int nlen = (si>>26) + ai.length();
                nlst.insert(si+cset+(ai.length()<<26));
                res = max(res, nlen);
            }
            slst.insert(nlst.begin(), nlst.end());
        }
        return res;
    }
};
