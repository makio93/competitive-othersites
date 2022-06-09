// 自力TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);

int main() {
	while (1) {
		ll p;
		cin >> p;
		if (p == 0) break;
		vector<ll> plst;
		for (ll i=2; i*i<=p; ++i) {
			while (p%i == 0) {
				plst.push_back(i);
				p /= i;
			}
		}
		if (p > 1) plst.push_back(p);
		int plen = plst.size();
		vector<ll> glst(3, 1LL);
		ll res = LINF, nval = 3;
		multiset<ll> nst;
		rep(i, 3) nst.insert(glst[i]);
		set<multiset<ll>> memo;
		auto dfs = [&](auto dfs, int di=0) -> void {
			if (memo.find(nst) != memo.end()) return;
			if (di == plen) {
				res = min(res, nval);
				return;
			}
			if (nval > res) return;
			rep(i1, 3) {
				bool sm = false;
				rep(j1, i1) if (glst[j1] == glst[i1]) sm = true;
				if (sm) continue;
				nval -= glst[i1];
				nst.erase(nst.find(glst[i1]));
				glst[i1] *= plst[di];
				nst.insert(glst[i1]);
				nval += glst[i1];
				dfs(dfs, di+1);
				nval -= glst[i1];
				nst.erase(nst.find(glst[i1]));
				glst[i1] /= plst[di];
				nst.insert(glst[i1]);
				nval += glst[i1];
			}
			memo.insert(nst);
		};
		dfs(dfs);
		cout << res << endl;
	}
	return 0;
}
