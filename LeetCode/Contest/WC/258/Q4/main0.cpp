#include <bits/stdc++.h>
using namespace std;

// 本番TLE

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> dep(n);
        vector<vector<int>> g(n);
        for (int i=0; i<n; ++i) if (parents[i] != -1) g[parents[i]].push_back(i);
        function<void(int,int)> dfs = [&](int v, int d) {
            dep[v] = d;
            for (int t : g[v]) dfs(t, d+1);
        };
        dfs(0, 0);
        vector<int> mex(n, 1);
        vector<pair<int, unordered_set<int>>> gvals(n);
        for (int i=0; i<n; ++i) gvals[i] = { 1, unordered_set<int>({ nums[i] }) };
        vector<set<pair<int, int>>> sids(n);
        for (int i=0; i<n; ++i) sids[i].emplace(1, i);
        priority_queue<pair<int, int>> que;
        for (int i=0; i<n; ++i) {
            que.emplace(dep[i], i);
            if (nums[i] == 1) mex[i] = 2;
        }
        vector<int> ans(n);
        while (!que.empty()) {
            auto [di, vi] = que.top(); que.pop();
            int asid = sids[vi].rbegin()->second;
            for (auto itr=next(sids[vi].rbegin()); itr!=sids[vi].rend(); ++itr) {
                for (int val : gvals[itr->second].second) gvals[asid].second.insert(val);
                gvals[asid].first += gvals[itr->second].first; 
            }
            while (gvals[asid].second.find(mex[vi]) != gvals[asid].second.end()) mex[vi]++;
            ans[vi] = mex[vi];
            sids[vi].clear();
            sids[vi].emplace(gvals[asid].first, asid);
            if (parents[vi] != -1) {
                mex[parents[vi]] = max(mex[parents[vi]], mex[vi]);
                sids[parents[vi]].emplace(*sids[vi].begin());
            }
        }
        return ans;
    }
};
