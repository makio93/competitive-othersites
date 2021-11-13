#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

int main() {
	int n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	int mval = 0;
	rep(i, n) mval = max(mval, h[i]);
	int l = 0, r = mval;
	while (r-l > 0) {
		int c = l + (r-l) / 2;
		auto th = h;
		rep(i, n) th[i] -= min(th[i], c);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh;
		rep(i, n) if (th[i] > 0) mh.emplace(max(0, x-th[i]), i);
		bool res = (mh.empty());
		if (!res) {
			rep(i, a) {
				auto pi = mh.top(); mh.pop();
				th[pi.second] -= min(th[pi.second], x);
				if (th[pi.second] > 0) mh.emplace(max(0, x-th[pi.second]), pi.second);
				if (mh.empty()) {
					res = true;
					break;
				}
			}
		}
		if (!res) {
			int id = 0;
			rep(i, b) {
				int p = y;
				while (p>0 && id<n) {
					int d = min(p, th[id]);
					th[id] -= d;
					p -= d;
					if (th[id] <= 0) ++id;
				}
				while (id<n && th[id]==0) ++id;
				if (id >= n) {
					res = true;
					break;
				}
			}
		}
		if (res) r = c;
		else l = c+1;
	}
	cout << min(l, r) << endl;
	return 0;
}
