#include <bits/stdc++.h>
using namespace std;

// 本番WA

using ll = long long;
class Solution {
    int n;
    vector<int> values;
    set<int> rlst;
    map<tuple<int,int,int>, bool> memo;
    bool dfs(int v, int d, int m) {
        if (memo.find({v,d,m}) != memo.end()) return memo[{v,d,m}];
        if (m%3 == 0) return (memo[{v,d,m}] = false);
        if (rlst.empty()) return (memo[{v,d,m}] = (n%2 == 0));
        bool res = true;
        for (auto itr=rlst.begin(); itr!=rlst.end(); ++itr) {
            int rid = *itr;
            rlst.erase(rid);
            if (dfs(rid, d+1, (m+values[rid])%3)) res = false;
            rlst.insert(rid);
            itr = rlst.find(rid);
        }
        return (memo[{v,d,m}] = res);
    }
public:
    bool stoneGameIX(vector<int>& stones) {
        n = stones.size();
        values = stones;
        for (int i=0; i<n; ++i) rlst.insert(i);
        bool ok = false;
        for (int i=0; i<n; ++i) {
            rlst.erase(i);
            if (dfs(i, 0, stones[i]%3)) {
                ok = true;
                break;
            }
            rlst.insert(i);
        }
        return ok;
    }
};
