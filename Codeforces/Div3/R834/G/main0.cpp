// 自力AC

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
		int n;
		cin >> n;
		vector<int> b(n/2);
		rep(i, n/2) cin >> b[i];
		set<int> alst;
		rep3(i, 1, n+1) alst.insert(i);
		bool ok = true;
		rep(i, n/2) {
			if (alst.find(b[i]) == alst.end()) {
				ok = false;
				break;
			}
			alst.erase(b[i]);
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		vector<int> blst(n/2);
		repr(i, n/2) {
			auto itr = alst.lower_bound(b[i]);
			if (itr == alst.begin()) {
				ok = false;
				break;
			}
			--itr;
			blst[i] = *itr;
			alst.erase(itr);
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		vector<int> a(n);
		rep(i, n/2) {
			int lv = b[i], rv = blst[i];
			if (lv > rv) swap(lv, rv);
			a[i*2] = lv;
			a[i*2+1] = rv;
		}
		rep(i, n) cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}
