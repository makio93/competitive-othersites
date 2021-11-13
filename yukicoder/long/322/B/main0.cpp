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
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh;
	rep(i, n) mh.emplace(max(0, x-h[i]), i);
	bool res = false;
	rep(i, a) {
		auto pi = mh.top(); mh.pop();
		h[pi.second] -= x;
		h[pi.second] = max(0, h[pi.second]);
		if (h[pi.second] > 0) mh.emplace(max(0, x-h[pi.second]), pi.second);
		if (mh.empty()) {
			res = true;
			break;
		}
	}
	if (!res) {
		int id = 0;
		rep(i, b) {
			int p = y;
			while (p>0 && id<n) {
				int d = min(p, h[id]);
				h[id] -= d;
				p -= d;
				if (h[id] <= 0) ++id;
			}
			if (id >= n) {
				res = true;
				break;
			}
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
