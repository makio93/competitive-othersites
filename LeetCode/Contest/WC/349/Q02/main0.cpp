// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        if (s == string(n, 'a')) {
            s[n-1] = 'z';
            return s;
        }
        int li = 0, ri = 0;
        for (int i=0; i<n; ++i) if (s[i] != 'a') {
            li = ri = i;
            while (ri < n && s[ri] != 'a') ++ri;
            break;
        }
        for (int i=li; i<ri; ++i) s[i]--;
        return s;
    }
};
