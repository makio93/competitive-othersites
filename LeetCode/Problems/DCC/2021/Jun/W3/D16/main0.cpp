#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    void dfs(vector<string>& slst, string& s, int d, int val=0, int l=0) {
        int r = s.length() - l;
        if (l==d && r==d) slst.push_back(s);
        else {
            if (l < d) {
                s += '(';
                dfs(slst, s, d, val+1, l+1);
                s.pop_back();
            }
            if (r<d && val-1>=0) {
                s += ')';
                dfs(slst, s, d, val-1, l);
                s.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        dfs(res, str, n);
        return res;
    }
};
