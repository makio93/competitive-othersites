// 本番WA2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const string tar = "inw";

class Dinic {
public:
	struct edge {
		int to, cap, rev;
		edge(int to, int cap=0, int rev=-1) : to(to), cap(cap), rev(rev) {}
	};
	vector<vector<edge>> g;
	vector<int> level, iter;
	void bfs(int s) {
		level.assign(g.size(), INF);
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (const auto& e : g[v]) if (e.cap>0 && level[e.to]==INF) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
	int dfs(int v, int t, int f) {
		if (v == t) return f;
		while (iter[v] < (int)(g[v].size())) {
			auto& e = g[v][iter[v]];
			iter[v]++;
			if (e.cap>0 && level[e.to]>level[v]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	Dinic(int n) { g.resize(n, vector<edge>()); }
	void add_edge(int from, int to, int cap) {
		g[from].emplace_back(to, cap, (int)(g[to].size()));
		g[to].emplace_back(from, 0, g[from].size()-1);
	}
	int max_flow(int s, int t) {
		int flow = 0;
		while (1) {
			bfs(s);
			if (level[t] == INF) return flow;
			iter.assign(g.size(), 0);
			int f = INF;
			while ((f = dfs(s, t, INF)) > 0) flow += f;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int m;
		cin >> m;
		vector<string> s(m);
		rep(i, m) cin >> s[i];
		rep(i, m) sort(all(s[i]));
		Dinic d(m+2);
		vector<int> wlst, ilst, nlst;
		vector<int> gid(m);
		rep(i, m) {
			if (count(all(s[i]), 'w') >= 2) {
				wlst.push_back(i);
				gid[i] = 2;
			}
			else if (count(all(s[i]), 'i') >= 2) {
				ilst.push_back(i);
				gid[i] = 0;
			}
			else if (count(all(s[i]), 'n') >= 2) {
				nlst.push_back(i);
				gid[i] = 1;
			}
		}
		for (const int& id : wlst) {
			if (s[id] == "www") d.add_edge(m, id, 2);
			else d.add_edge(m, id, 1);
		}
		for (const int& id : ilst) {
			if (s[id] == "iiw") d.add_edge(m, id, 1);
			else for (const int& wid : wlst) { if (count(all(s[wid]), 'i') == 0) d.add_edge(wid, id, 1); }
			if (s[id] == "iin") d.add_edge(id, m+1, 1);
			else for (const int& nid : nlst) { if (count(all(s[nid]), 'i') == 0) d.add_edge(id, nid, 1); }
		}
		for (const int& id : nlst) {
			if (s[id] == "nnn") d.add_edge(id, m+1, 2);
			else d.add_edge(id, m+1, 1);
			if (s[id] != "nnw") for (const int& wid : wlst) { if (count(all(s[wid]), 'n') == 0) d.add_edge(wid, id, 1); }
		}
		d.max_flow(m, m+1);
		vector<pair<pair<int, char>, pair<int, char>>> res;
		rep(i, m) {
			for (const auto& ei : d.g[i]) {
				int ti = ei.to;
				if (ti >= m) continue;
				if (ei.cap > 0) continue;
				res.emplace_back(make_pair(i+1, tar[gid[i]]), make_pair(ti+1, tar[gid[ti]]));
			}
		}
		int k = res.size();
		cout << k << endl;
		rep(i, k) cout << res[i].first.first << ' ' << res[i].first.second << ' ' << res[i].second.first << ' ' << res[i].second.second << endl;
	}
	return 0;
}
