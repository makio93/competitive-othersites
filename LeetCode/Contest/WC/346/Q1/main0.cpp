// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        string t;
        for (int i=0; i<n; ++i) {
            t.push_back(s[i]);
            while ((int)(t.length()) >= 2) {
                int tlen = t.length();
                string tsub = t.substr(tlen-2, 2);
                if (tsub!=string("AB") && tsub!=string("CD")) break;
                t.erase(t.end()-2, t.end());
            }
        }
        return (int)(t.length());
    }
};
