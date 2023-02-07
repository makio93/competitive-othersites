// 自力提出1,WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k >= n) return string("0");
        string res;
        int ncnt = 0, lid = 0;
        for (int i=0; i<n; ++i) {
            if (num[i] != '0') ++ncnt;
            if (ncnt >= k+1) {
                lid = i;
                break;
            }
        }
        if (ncnt < k+1) return string("0");
        int cnt = 0;
        if (lid >= k+1) res = num.substr(lid);
        else {
            while (cnt < k) {
                int len = num.length();
                if (len>=3 && max(num[0],num[1])<num[2]) res += num.substr(0, 2);
                else {
                    res.push_back(min(num[0], num[1]));
                    ++cnt;
                }
                for (int i=2; i<len; ++i) {
                    if (cnt<k && res.back()<num[i]) ++cnt;
                    else res.push_back(num[i]);
                }
                if (cnt >= k) return res;
                swap(res, num);
                res.clear();
            }
        }
        if (res.front() == '0') {
            int zcnt = 0;
            for (int i=0; i<(int)(res.length()); ++i) {
                if (res[i] == '0') zcnt = max(zcnt, i);
                else break;
            }
            res = res.substr(zcnt+1);
        }
        if (res.empty()) res = "0";
        return res;
    }
};
