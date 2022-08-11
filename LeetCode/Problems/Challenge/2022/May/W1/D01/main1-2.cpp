// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sid = s.length() - 1, tid = t.length() - 1;
        while (sid>=0 || tid>=0) {
            int cnt = 0;
            while (sid >= 0) {
                if (s[sid] == '#') { ++cnt; --sid; }
                else if (cnt > 0) { --cnt; --sid; }
                else break;
            }
            cnt = 0;
            while (tid >= 0) {
                if (t[tid] == '#') { ++cnt; --tid; }
                else if (cnt > 0) { --cnt; --tid; }
                else break;
            }
            if (sid>=0 && tid>=0 && s[sid]!=t[tid]) return false;
            if ((sid>=0) != (tid>=0)) return false;
            --sid; --tid;
        }
        return true;
    }
};
