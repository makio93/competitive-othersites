// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        string snum = to_string(num);
        int n = snum.length(), res = 0;
        for (int i=0; i<n; ++i) if ((snum[i]-'0')!=0 && num%(snum[i]-'0')==0) ++res;
        return res;
    }
};
