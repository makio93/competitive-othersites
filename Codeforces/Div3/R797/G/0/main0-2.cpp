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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b;
		rep(i, n) cin >> a[i];
		b = a;
		rep(i, n-1) b[i+1] = min(b[i+1], b[i]);
		map<int, int> alst;
		alst[n] = b[0];
		rep3(i, 1, n) if (b[i-1] > b[i]) alst[n-i] = b[i];
		rep(i, m) {
			int ki, di;
			cin >> ki >> di;
			--ki;
			a[ki] -= di;
			bool non = false;
			if (alst.find(n-ki) != alst.end()) alst[n-ki] = a[ki];
			else {
				auto titr = alst.lower_bound(n-ki);
				if (titr->second <= a[ki]) non = true;
				else alst[n-ki] = a[ki];
			}
			if (!non) {
				int tval = alst[n-ki];
				auto aitr = alst.find(n-ki);
				while (aitr != alst.begin()) {
					--aitr;
					if (aitr->second < tval) break;
					aitr = alst.erase(aitr);
				}
			}
			cout << (int)(alst.size()) << ' ';
		}
		cout << endl;
	}
	return 0;
}
