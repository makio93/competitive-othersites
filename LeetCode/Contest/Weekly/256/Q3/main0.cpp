#include <bits/stdc++.h>
using namespace std;

// 本番WA

class Solution {
    int n;
    vector<int> ts;
    vector<int> used;
    vector<set<int>> rst;
    map<tuple<int,int,int>, pair<int,set<int>>> memo;
    pair<int,set<int>> dfs(int d, int num, int lim) {
        if (memo.find({d,num,lim}) != memo.end()) return memo[{d,num,lim}];
        if (d == n) return (memo[{d,num,lim}] = { 0, set<int>({}) });
        pair<int,set<int>> res1 = {0, {}}, res2 = {0, {}};
        if (used[d]==-1 && lim-ts[d]>=0) {
            res1 = dfs(d+1, num, lim-ts[d]);
            res1.first += ts[d];
            res1.second.insert(d);
        }
        else res2 = dfs(d+1, num, lim);
        auto res = max(res1, res2);
        return (memo[{d,num,lim}] = res);
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        used = vector<int>(n, -1);
        ts = tasks;
        int sum = 0, rval = 0;
        for (int i=0; i<n; ++i) sum += tasks[i];
        while (sum > 0) {
            ++rval;
            auto ri = dfs(0, rval, sessionTime);
            for (int id : ri.second) used[id] = rval;
            sum -= ri.first;
            if (sum <= 0) return rval;
        }
        return rval;
    }
};
