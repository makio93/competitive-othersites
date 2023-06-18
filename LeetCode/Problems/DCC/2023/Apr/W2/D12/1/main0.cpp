// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        string npath;
        for (int i=0; i<n; ++i) {
            if (path[i] == '/' && (i-1>=0 && path[i-1]=='/')) continue;
            npath.push_back(path[i]);
        }
        swap(npath, path);
        n = path.length();
        while ((int)(path.length()) > 1 && path.back() == '/') path.pop_back();
        if (path == "/") return path;
        n = path.length();
        vector<string> dlst;
        int id = 0;
        while (id < n) {
            ++id;
            int li = id;
            while (id<n && path[id]!='/') ++id;
            dlst.push_back(path.substr(li, id-li));
        }
        int m = dlst.size();
        vector<string> tlst;
        for (int i=0; i<m; ++i) {
            if (dlst[i] == ".") continue;
            if (dlst[i] == "..") {
                if (tlst.empty()) continue;
                tlst.pop_back();
            }
            else tlst.push_back(dlst[i]);
        }
        string res;
        m = tlst.size();
        for (int i=0; i<m; ++i) res += "/" + tlst[i];
        if (res.empty()) res = "/";
        return res;
    }
};
