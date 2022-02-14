#include <bits/stdc++.h>
using namespace std;

// 終了後,自力考察,自力AC,コード手直し

const int INF = (int)(1e5);
struct mcf_graph {
  public:
    mcf_graph() {}
    mcf_graph(int n) : _n(n), g(n) {}
    int add_edge(int from, int to, int cap, int cost) {
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap, cost});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0, -cost});
        return m;
    }
    struct edge {
        int from, to;
        int cap, flow;
        int cost;
    };
    pair<int, int> flow(int s, int t) {
        return flow(s, t, INF);
    }
    pair<int, int> flow(int s, int t, int flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    vector<pair<int, int>> slope(int s, int t) {
        return slope(s, t, INF);
    }
    vector<pair<int, int>> slope(int s, int t, int flow_limit) {
        vector<int> dual(_n, 0), dist(_n);
        vector<int> pv(_n), pe(_n);
        vector<bool> vis(_n);
        auto dual_ref = [&]() {
            fill(dist.begin(), dist.end(),
                      INF);
            fill(pv.begin(), pv.end(), -1);
            fill(pe.begin(), pe.end(), -1);
            fill(vis.begin(), vis.end(), false);
            struct Q {
                int key;
                int to;
                bool operator<(Q r) const { return key > r.key; }
            };
            priority_queue<Q> que;
            dist[s] = 0;
            que.push(Q{0, s});
            while (!que.empty()) {
                int v = que.top().to;
                que.pop();
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                for (int i = 0; i < int(g[v].size()); i++) {
                    auto e = g[v][i];
                    if (vis[e.to] || !e.cap) continue;
                    int cost = e.cost - dual[e.to] + dual[v];
                    if (dist[e.to] - dist[v] > cost) {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        que.push(Q{dist[e.to], e.to});
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }
            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };
        int flow = 0;
        int cost = 0, prev_cost = -1;
        vector<pair<int, int>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            int c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = min(c, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            int d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost = cost;
        }
        return result;
    }
  private:
    int _n;
    struct _edge {
        int to, rev;
        int cap;
        int cost;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
};

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        mcf_graph g(n+numSlots*2+2);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<numSlots; ++j) {
                g.add_edge(i, n+j, 1, -(nums[i]&(j+1)));
                g.add_edge(i, n+numSlots+j, 1, -(nums[i]&(j+1)));
            }
        }
        for (int i=0; i<n; ++i) g.add_edge(n+numSlots*2, i, 1, 0);
        for (int i=0; i<numSlots*2; ++i) g.add_edge(n+i, n+numSlots*2+1, 1, 0);
        auto pval = g.flow(n+numSlots*2, n+numSlots*2+1);
        return -pval.second;
    }
};
