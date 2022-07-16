// 

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
		int n, x;
		cin >> n >> x;
		vector<int> h(n*2);
		rep(i, n*2) cin >> h[i];
		sort(all(h));
		bool res = true;
		rep(i, n) if (h[i+n]-h[i] < x) {
			res = false;
			break;
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
