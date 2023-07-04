// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length(), m = goal.length();
        if (n != m) return false;
        vector<int> slst;
        for (int i=0; i<n; ++i) if (s[i] != goal[i]) slst.push_back(i);
        if ((int)(slst.size()) == 0) {
            sort(s.begin(), s.end());
            s.erase(unique(s.begin(), s.end()), s.end());
            return (int)(s.length()) < n;
        }
        else if ((int)(slst.size()) == 2) {
            swap(s[slst[0]], s[slst[1]]);
            return s == goal;
        }
        else return false;
    }
};
