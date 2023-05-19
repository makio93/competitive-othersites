// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const vector<string> ops = { "and", "or", "xor", "imp" }, bins = { "False", "True" };
const vector<vector<int>> results = {
	{ 0, 0, 0, 1 }, { 0, 1, 1, 1 }, { 0, 1, 1, 0 }, { 1, 1, 0, 1 }
};

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<string> a(n*2-1);
		vector<int> s(n-1);
		rep(i, n) cin >> a[i*2];
		rep(i, n-1) cin >> a[i*2+1];
		rep(i, n-1) {
			cin >> s[i];
			s[i]--;
		}
		fenwick_tree<int> ft(n*2-1);
		rep(i, n*2-1) ft.add(i, 1);
		function<string(int)> get = [&](int id) {
			int li = -1, ri = n*2-1;
			while (ri-li > 1) {
				int ci = li + (ri-li) / 2;
				if (ft.sum(0, ci+1) > id) ri = ci;
				else li = ci;
			}
			return a[ri];
		};
		function<void(int,string)> set = [&](int id, string val) {
			int li = -1, ri = n*2-1;
			while (ri-li > 1) {
				int ci = li + (ri-li) / 2;
				if (ft.sum(0, ci+1) > id) ri = ci;
				else li = ci;
			}
			a[ri] = val;
		};
		function<void(int)> del = [&](int id) {
			int li = -1, ri = n*2-1;
			while (ri-li > 1) {
				int ci = li + (ri-li) / 2;
				if (ft.sum(0, ci+1) > id) ri = ci;
				else li = ci;
			}
			a[ri] = "";
			ft.add(ri, -1);
		};
		string res;
		rep(i, n-1) {
			string lval = get(s[i]*2), cval = get(s[i]*2+1), rval = get(s[i]*2+2);
			int oid = find(all(ops), cval) - ops.begin(), vid = (lval == "True" ? 2 : 0) + (rval == "True" ? 1 : 0);
			string bval = bins[results[oid][vid]];
			set(s[i]*2, bval);
			del(s[i]*2+2);
			del(s[i]*2+1);
			if (i == n-2) res = bval;
		}
		cout << res << endl;
	}
	return 0;
}
