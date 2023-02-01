// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        string slst, tlst;
        for (char& ci : start) if (ci != '_') slst.push_back(ci);
        for (char& ci : target) if (ci != '_') tlst.push_back(ci);
        if (slst != tlst) return false;
        int slcnt = 0, tlcnt = 0, srcnt = 0, trcnt = 0;
        for (int i=0; i<n; ++i) {
            if (start[i] == 'L') ++slcnt;
            if (target[i] == 'L') ++tlcnt;
            if (tlcnt < slcnt) return false;
        }
        for (int i=n-1; i>=0; --i) {
            if (start[i] == 'R') ++srcnt;
            if (target[i] == 'R') ++trcnt;
            if (trcnt < srcnt) return false;
        }
        return true;
    }
};
