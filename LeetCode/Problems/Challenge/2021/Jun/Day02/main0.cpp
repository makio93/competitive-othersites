#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    map<tuple<int, int, int, int>, bool> memo;
    vector<string> strs;
    string tstr;
    bool dfs(int snum, int ipos, int jpos, int tpos) {
        if (memo.find({snum,ipos,jpos,tpos}) != memo.end()) return memo[{snum,ipos,jpos,tpos}];
        int tnum = 1 - snum;
        if (jpos == (int)(strs[tnum].length())) return (memo[{snum,ipos,jpos,tpos}] = (strs[snum].substr(ipos) == tstr.substr(tpos)));
        else if (ipos == (int)(strs[snum].length())) return (memo[{snum,ipos,jpos,tpos}] = false);
        else {
            int rlen = 0;
            while (ipos+rlen<strs[snum].length() && tpos+rlen<tstr.length() && strs[snum][ipos+rlen]==tstr[tpos+rlen]) ++rlen;
            for (int i=1; i<=rlen; ++i) if (dfs(tnum, jpos, ipos+i, tpos+i)) return (memo[{snum,ipos,jpos,tpos}] = true);
            return (memo[{snum,ipos,jpos,tpos}] = false);
        }
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        strs = { s1, s2 }; tstr = s3;
        return (dfs(0, 0, 0, 0) || dfs(1, 0, 0, 0));
    }
};
