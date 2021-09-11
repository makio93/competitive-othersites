#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        function<int(int,int&)> eval = [&](int id, int& rid) -> int {
            int res = 0;
            while (id<n && s[id]==' ') ++id;
            if (id >= n) {
                rid = id;
                return res;
            }
            if (s[id] == '(') {
                ++id;
                while (s[id] == ' ') ++id;
                int li = id;
                if (s[id] == '-') ++id;
                while (isdigit(s[id])) ++id;
                res += stoi(s.substr(li, id-li));
                while (s[id] == ' ') ++id;
                while (s[id] != ')') {
                    int mul = (s[id]=='-') ? -1 : 1;
                    ++id;
                    while (s[id] == ' ') ++id;
                    res += eval(id, id) * mul;
                    while (s[id] == ' ') ++id;
                }
                ++id;
                while (id<n && s[id]==' ') ++id;
                rid = id;
                return res;
            }
            else {
                int li = id;
                if (s[id] == '-') ++id;
                while (id<n && isdigit(s[id])) ++id;
                res += stoi(s.substr(li, id-li));
                while (id<n && s[id]==' ') ++id;
                rid = id;
                return res;
            }
        };
        int sid = 0, res = 0;
        while (s[sid] == ' ') ++sid;
        if (s[sid] != '-') res += eval(sid, sid);
        while (sid < n) {
            int mul = (s[sid] == '-') ? -1 : 1;
            ++sid;
            res += eval(sid, sid) * mul;
        }
        return res;
    }
};
