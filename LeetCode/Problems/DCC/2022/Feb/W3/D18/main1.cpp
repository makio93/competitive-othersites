// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length(), kcnt = 0;
        string res;
        for (int i=0; i<n; ++i) {
            while (kcnt<k && !res.empty() && res.back()>num[i]) {
                res.pop_back();
                ++kcnt;
            }
            res.push_back(num[i]);
        }
        while (kcnt < k) {
            res.pop_back();
            ++kcnt;
        }
        if (!res.empty()) {
            int lid = 0;
            for (int i=0; i<(int)(res.length()); ++i) {
                if (res[i] == '0') lid = max(lid, i+1);
                else break;
            }
            res = res.substr(lid);
        }
        if (res.empty()) res = "0";
        return res;
    }
};
