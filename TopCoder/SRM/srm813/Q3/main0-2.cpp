// 終了後,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class PartialRaceResults {
    vector<set<int>> g;
    vector<bool> visited, searching;
    bool roop = false;
    void dfs(int v) {
        if (searching[v]) {
            roop = true;
            return;
        }
        searching[v] = true;
        for (int t : g[v]) if (!visited[t]) {
            dfs(t);
            if (roop) return;
        }
        searching[v] = false;
        visited[v] = true;
    }
public:
    string reconstruct(vector<string> memories) {
        int n = memories.size();
        vector<char> clst;
        rep(i, n) rep(j, 4) if (j != 1) clst.push_back(memories[i][j]);
        sort(all(clst));
        clst.erase(unique(all(clst)), clst.end());
        int clen = clst.size();
        unordered_map<char, int> cid;
        rep(i, clen) cid[clst[i]] = i;
        g = vector<set<int>>(clen);
        vector<int> din(clen);
        rep(i, n) {
            if (g[cid[memories[i][2]]].find(cid[memories[i][0]]) == g[cid[memories[i][2]]].end()) {
                g[cid[memories[i][2]]].insert(cid[memories[i][0]]);
                din[cid[memories[i][0]]]++;
            }
            if (g[cid[memories[i][0]]].find(cid[memories[i][3]]) == g[cid[memories[i][0]]].end()) {
                g[cid[memories[i][0]]].insert(cid[memories[i][3]]);
                din[cid[memories[i][3]]]++;
            }
        }
        visited = vector<bool>(clen);
        searching = vector<bool>(clen);
        rep(i, clen) {
            if (!visited[i]) {
                dfs(i);
                if (roop) break;
            }
        }
        string res;
        if (roop) return res;
        queue<int> que;
        set<int> fin;
        rep(i, clen) if (din[i] == 0) {
            que.push(i);
            res += clst[i];
            fin.insert(i);
        }
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (int t : g[v]) if (fin.find(t) == fin.end()) {
                din[t]--;
                if (din[t] == 0) {
                    que.push(t);
                    res += clst[t];
                    fin.insert(t);
                }
            }
        }
        rep(i, clen) if (fin.find(i) == fin.end()) res += clst[i];
        return res;
    }
};
