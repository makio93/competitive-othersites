// 自力提出2,WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k == n) return string("0");
        string res0, res1;
        {
            int ncnt = 0, lid = n;
            for (int i=0; i<n; ++i) {
                if (num[i] != '0') {
                    ++ncnt;
                    if (ncnt >= k) {
                        lid = i+1;
                        break;
                    }
                }
            }
            res0 = num.substr(lid);
        }
        {
            vector<bool> remain(n, true);
            vector<stack<int>> vals;
            vals.push_back(stack<int>({0}));
            for (int i=1; i<n; ++i) {
                if (num[i] >= num[vals.back().top()]) vals.back().push(i);
                else vals.push_back(stack<int>({i}));
            }
            queue<pair<pair<int, int>, int>> pq;
            int m = vals.size();
            for (int i=0; i<m; ++i) {
                pq.emplace(make_pair(num[vals[i].top()]-'0', vals[i].top()), i);
                vals[i].pop();
            }
            int cnt = 0;
            while (!pq.empty()) {
                auto pi = pq.front(); pq.pop();
                int val = pi.first.first, nid = pi.first.second, mid = pi.second;
                remain[nid] = false;
                ++cnt;
                if (cnt >= k) break;
                if (!vals[mid].empty()) {
                    pq.emplace(make_pair(num[vals[mid].top()]-'0', vals[mid].top()), mid);
                    vals[mid].pop();
                }
            }
            for (int i=0; i<n; ++i) if (remain[i]) res1.push_back(num[i]);
        }
        string res = min(res0, res1);
        if (res.empty()) return string("0");
        int zcnt = 0;
        int rlen = res.length(), rid = 0;
        for (int i=0; i<rlen; ++i) {
            if (res[i] == '0') rid = max(rid, i+1);
            else break;
        }
        res = res.substr(rid);
        if (res.empty()) res = "0";
        return res;
    }
};
