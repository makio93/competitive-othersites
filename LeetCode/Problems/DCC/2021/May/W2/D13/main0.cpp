#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    bool isok(string s) {
        int n = s.length();
        if (n <= 0) return false;
        else if (n <= 1) return isdigit(s[0]);
        else {
            if (s[0] == '0') {
                if (s[1] != '.') return false;
                else return (isdigit(s.back()) && s.back()!='0');
            }
            else if (!isdigit(s[0])) return false;
            else {
                if (count(s.begin(), s.end(), '.') == 0) return true;
                else return (isdigit(s.back()) && s.back()!='0');
            }
        }
    }
    vector<string> mklsts(string s) {
        int n = s.length();
        vector<string> res;
        if (isok(s)) res.push_back(s);
        for (int i=0; i<n-1; ++i) {
            string t = s.substr(0, i+1) + '.' + s.substr(i+1);
            if (isok(t)) res.push_back(t);
        }
        return res;
    }
    string wrap(string s1, string s2) {
        return string("(") + s1 + string(", ") + s2 + string(")");
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.length();
        vector<string> res;
        for (int i=0; i<n-3; ++i) {
            auto llst = mklsts(s.substr(1, i+1)), rlst = mklsts(s.substr(i+2, n-i-3));
            int llen = llst.size(), rlen = rlst.size();
            for (int l=0; l<llen; ++l) for (int r=0; r<rlen; ++r) res.push_back(wrap(llst[l], rlst[r]));
        }
        return res;
    }
};
