#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int val = n + 1;
        while (1) {
            string nstr = to_string(val);
            vector<int> dcnt(10);
            for (char ci : nstr) dcnt[ci-'0']++;
            if (dcnt[0] == 0) {
                bool ok = true;
                for (int i=1; i<10; ++i) if (dcnt[i]>0 && dcnt[i]!=i) {
                    ok = false;
                    break;
                }
                if (ok) return val;
            }
            ++val;
        }
    }
};
