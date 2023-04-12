// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string> clst, st;
        for (int i=0,li=i; i<n; ++i) {
            if (i+1==n || path[i+1]=='/') {
                clst.push_back(path.substr(li+1, i-li));
                li = i + 1;
            }
        }
        for (const auto& ci : clst) {
            if (ci.empty() || ci==string(".")) continue;
            if (ci == string("..")) {
                if (st.empty()) continue;
                st.pop_back();
            }
            else st.push_back(ci);
        }
        if (st.empty()) return "/";
        string res;
        for (const auto& ci : st) res += "/" + ci;
        return res;
    }
};
