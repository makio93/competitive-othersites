#include <bits/stdc++.h>
using namespace std;

// 自力AC2

const int INF = (int)(1e9);
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        unordered_map<string, int> dist;
        unordered_set<string> dlst;
        for (int i=0; i<n; ++i) dlst.insert(deadends[i]);
        if (dlst.find(string("0000")) != dlst.end()) return -1;
        if (target == string("0000")) return 0;
        queue<string> que;
        dist["0000"] = 0;
        que.push("0000");
        while (!que.empty()) {
            string val = que.front(); que.pop();
            int d = dist[val];
            vector<int> dvals(4);
            for (int i=0; i<4; ++i) {
                string nval = val;
                if (val[i] < '9') nval[i]++;
                else nval[i] = '0';
                if (dist.find(nval)==dist.end() && dlst.find(nval)==dlst.end()) {
                    if (nval == target) return d+1;
                    dist[nval] = d + 1;
                    que.push(nval);
                }
                nval = val;
                if (val[i] > '0') nval[i]--;
                else nval[i] = '9';
                if (dist.find(nval)==dist.end() && dlst.find(nval)==dlst.end()) {
                    if (nval == target) return d+1;
                    dist[nval] = d + 1;
                    que.push(nval);
                }
            }
        }
        if (dist.find(target) != dist.end()) return dist[target];
        else return -1;
    }
};
