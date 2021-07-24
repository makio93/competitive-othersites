#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const int INF = (int)(1e9);
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> g(n+1);
        for (int i=0; i<=n; ++i) for (int j=i+1; j<=n; ++j) {
            string s1 = ((i == 0) ? beginWord : wordList[i-1]), s2 = wordList[j-1];
            int diff = 0, slen = s1.length();
            for (int i2=0; i2<slen; ++i2) if (s1[i2] != s2[i2]) ++diff;
            if (diff == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        vector<int> dist(n+1, INF);
        queue<int> que;
        que.push(0);
        dist[0] = 0;
        while (!que.empty()) {
            int v = que.front(); que.pop();
            int d = dist[v], nd = d + 1;
            for (int t : g[v]) {
                if (dist[t] <= nd) continue;
                que.push(t);
                dist[t] = nd;
            }
        }
        vector<vector<string>> res;
        vector<string> tmp;
        function<void(int,int)> dfs = [&](int v, int d) {
            tmp.push_back(((v==0)?beginWord:wordList[v-1]));
            if (d == 0) {
                if (v == 0) {
                    auto tmp2 = tmp;
                    reverse(tmp2.begin(), tmp2.end());
                    res.push_back(tmp2);
                }
            }
            else {
                for (int t : g[v]) if (dist[t] == d-1) dfs(t, d-1);
            }
            tmp.pop_back();
            return;
        };
        int tid = -1;
        for (int i=0; i<n; ++i) if (wordList[i] == endWord) {
            tid = i+1;
            break;
        }
        if (tid!=-1 && dist[tid]!=INF) dfs(tid, dist[tid]);
        return res;
    }
};
