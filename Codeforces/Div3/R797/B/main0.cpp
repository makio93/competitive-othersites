// 本番AC

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
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		int sub = INF;
		rep(i, n) if (b[i] > 0) {
			sub = a[i] - b[i];
			break;
		}
		bool res = true;
		if (sub != INF) {
			if (sub < 0) res = false;
			else {
				rep(i, n) {
					if (b[i]>0 && a[i]-b[i]!=sub) { res = false; break; }
					if (b[i]==0 && a[i]>sub) { res = false; break; }
				}
			}
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
