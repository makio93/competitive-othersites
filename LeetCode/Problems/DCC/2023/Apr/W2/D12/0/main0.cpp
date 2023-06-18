// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        string res;
        for (int i=0; i<n; ++i) {
            if (path[i]=='/' && !res.empty() && res.back()=='/') continue;
            res.push_back(path[i]);
        }
        if ((int)(res.length())>=2 && res.back()=='/') res.pop_back();
        path = res;
        res.clear();
        n = path.length();
        for (int i=0; i<n; ++i) {
            if (path[i]=='/' && (int)(res.length())>=2 && res.substr(res.length()-2, 2)=="/.") res.erase(res.end()-2, res.end());
            res.push_back(path[i]);
        }
        if (res == "/.") res.pop_back();
        if ((int)(res.length())>=2 && res.substr(res.length()-2, 2)=="/.") res.erase(res.end()-2, res.end());
        path = res;
        res.clear();
        n = path.length();
        for (int i=0; i<n; ++i) {
            if (path[i]=='/' && (int)(res.length())>=3 && res.substr(res.length()-3, 3)=="/..") {
                res.erase(res.end()-3, res.end());
                if (!res.empty()) {
                    while (res.back() != '/') res.pop_back();
                    res.pop_back();
                }
            }
            res.push_back(path[i]);
        }
        if (res == "/..") res.erase(res.end()-2, res.end());
        if ((int)(res.length())>=3 && res.substr(res.length()-3, 3)=="/..") {
            res.erase(res.end()-3, res.end());
            while (res.back() != '/') res.pop_back();
            if ((int)(res.length()) > 1) res.pop_back();
        }
        return res;
    }
};
