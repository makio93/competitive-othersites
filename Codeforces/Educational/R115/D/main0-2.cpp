#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA,2

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i] >> b[i];
		map<int, set<int>> ab;
		rep(i, n) ab[a[i]].insert(b[i]);
		map<int, int> bcnt;
		rep(i, n) bcnt[b[i]]++;
		vector<int> vals;
		for (auto bpi : bcnt) vals.push_back(bpi.second);
		int vlen = vals.size();
		vector<ll> sum(vlen);
		sum[0] = vals[0];
		rep(i, vlen-1) sum[i+1] = sum[i] + vals[i+1];
		vector<ll> vals2(vlen), sum2(vlen);
		rep3(i, 1, vlen) vals2[i] = vals[i] * sum[i-1];
		sum2[0] = vals2[0];
		rep3(i, 1, vlen-1) sum2[i+1] = sum2[i] + vals2[i+1];
		ll res0 = 0;
		rep3(i, 1, vlen) res0 += vals[i] * sum2[i-1];
		ll sub0 = 0;
		vector<int> bvals;
		for (auto bpi : bcnt) bvals.push_back(bpi.first);
		for (auto pi : ab) {
			set<int>& alst = pi.second;
			int slen = alst.size(), sid = 0;
			for (auto itr=alst.begin(); itr!=alst.end(); ++itr,++sid) if (next(itr) != alst.end()) {
				int tval = *itr;
				int di = upper_bound(all(bvals), tval) - bvals.begin();
				if (di-1 >= 0) sub0 += sum[di-1] * (slen-sid-1);
			}
		}
		ll res = res0 - sub0 + 3;
		cout << res << endl;
	}
	return 0;
}
