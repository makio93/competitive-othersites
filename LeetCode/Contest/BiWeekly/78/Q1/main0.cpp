// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string nstr = to_string(num);
        int n = nstr.length();
        int res = 0;
        for (int i=0; i+k-1<n; ++i) {
            int val = stoi(nstr.substr(i, k));
            if (val!=0 && num%val==0) ++res;
        }
        return res;
    }
};
