// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int n = s.length();
        set<int> dig;
        for (int i=0; i<n; ++i) if (isdigit(s[i])) dig.insert((int)(s[i]-'0'));
        if ((int)(dig.size()) < 2) return -1;
        else return *(next(dig.rbegin()));
    }
};
