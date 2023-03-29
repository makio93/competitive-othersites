// 終了後,自力AC

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
		ll l, r;
		cin >> l >> r;
		if (l == r) {
			cout << l << endl;
			continue;
		}
		string lstr = to_string(l), rstr = to_string(r);
		int llen = lstr.length(), rlen = rstr.length();
		if (rlen > llen) {
			cout << string(llen, '9') << endl;
			continue;
		}
		string vstr(llen, '0');
		auto dfs = [&](auto dfs, int li, int ri, int vi=0) -> string {
			if (vi == llen) return vstr;
			ll lval = stoll(lstr.substr(0, vi+1)), rval = stoll(rstr.substr(0, vi+1));
			rep3(i, li, ri+1) {
				vstr[vi] = i + '0';
				ll val = stoll(vstr.substr(0, vi+1));
				if (val<lval || val>rval) continue;
				auto ret = dfs(dfs, li, ri, vi+1);
				if (!ret.empty()) return ret;
			}
			return string("");
		};
		string res;
		rep(k, 9) {
			rep(i, 10) {
				if (i+k > 9) break;
				res = dfs(dfs, i, i+k);
				if (!res.empty()) break;
			}
			if (!res.empty()) break;
		}
		if (res.empty()) res = lstr;
		cout << res << endl;
	}
	return 0;
}
