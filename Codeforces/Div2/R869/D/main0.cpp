// 自力WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> u(m), v(m);
		vector<vector<pair<int, int>>> g(n);
		rep(i, m) {
			cin >> u[i] >> v[i];
			u[i]--; v[i]--;
			g[u[i]].emplace_back(v[i], i);
			g[v[i]].emplace_back(u[i], i);
		}
		vector<int> rlst;
		multiset<int> vlst;
		set<int> tlst, elst;
		rep(i, n) {
			auto f = [&](auto& f, int si, int vi) -> bool {
				vlst.insert(vi);
				for (const auto& tpi : g[vi]) if (elst.find(tpi.second) == elst.end()) {
					elst.insert(tpi.second);
					bool ist = false;
					if (tlst.find(tpi.second) != tlst.end()) {
						tlst.erase(tpi.second);
						ist = true;
					}
					if (tpi.first == si) {
						set<int> alst;
						for (const int& ei : tlst) {
							int li = u[ei], ri = v[ei];
							if (ri == si) swap(li, ri);
							if (vlst.find(ri) == vlst.end()) alst.insert(ei);
						}
						if ((int)(alst.size()) == 2) {
							for (const auto& ei : alst) rlst.push_back(ei);
							for (const auto& ei : elst) rlst.push_back(ei);
							return true;
						}
					}
					else {
						if (f(f, si, tpi.first)) return true;
					}
					if (ist) tlst.insert(tpi.second);
					elst.erase(tpi.second);
				}
				vlst.erase(vlst.find(vi));
				return false;
			};
			for (const auto& tpi : g[i]) tlst.insert(tpi.second);
			if (f(f, i, i)) break;
			tlst.clear();
		}
		if (!rlst.empty()) {
			cout << "YES" << endl;
			int len = rlst.size();
			cout << len << endl;
			rep(i, len) cout << (u[rlst[i]]+1) << ' ' << (v[rlst[i]]+1) << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}
