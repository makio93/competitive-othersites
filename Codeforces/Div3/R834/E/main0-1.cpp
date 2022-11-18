// 本番WA

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
		ll h;
		cin >> n >> h;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		sort(all(a));
		vector<int> b = { 2, 2, 3 };
		int id = 0;
		while (id < n) {
			if (a[id] < h) {
				h += a[id] / 2;
				++id;
			}
			else {
				int m = b.size();
				if (m == 0) break;
				bool ok = false;
				rep(i, m) if (a[id] < h*b[i]) {
					ok = true;
					h *= b[i];
					b.erase(b.begin()+i);
					h += a[id] / 2;
					++id;
					break;
				}
				if (ok) continue;
				if (m <= 1) break;
				rep(i, m) {
					rep3(j, i+1, m) if (a[id] < h*b[i]*b[j]) {
						ok = true;
						h *= b[i] * b[j];
						b.erase(b.begin()+i);
						b.erase(b.begin()+j-1);
						h += a[id] / 2;
						++id;
						break;
					}
					if (ok) break;
				}
				if (ok) continue;
				if (m <= 2) break;
				int bm = 1;
				rep(i, m) bm *= b[i];
				if (a[id] < h*bm) {
					h *= bm;
					b.clear();
					h += a[id] / 2;
					++id;
				}
				else break;
			}
		}
		cout << id << endl;
	}
	return 0;
}
